<?php

/**
 * @file
 * Utility functions for object locking module.
 */

/**
 * Alert user to the current object being locked.
 *
 * @param AbstractObject $object
 *   The object that is locked.
 */
function islandora_object_lock_handle_possible_lock_notice(AbstractObject $object) {
  // Notify user that object is locked
  if (islandora_object_lock_is_locked($object)) {
    drupal_set_message(islandora_object_lock_get_locked_message($object), 'warning');
  }
}

/**
 * Get an appropriate message to display to the user about a locked object.
 *
 * @global user
 *
 * @param AbstractObject $object
 *   The object that is locked.
 *
 * @return string
 *   The message to display to the user.
 */
function islandora_object_lock_get_locked_message(AbstractObject $object) {
  global $user;

  if ($user->name == islandora_object_lock_get_lock_username($object)) {

    return t("This object is <strong>locked by you</strong>, so others cannot change it. You may <strong><a href=\"!unlock_url\">remove the lock from this object</a></strong>.",
      array(
        '!unlock_url' => url("islandora/object/{$object->id}/manage/datastreams/locking/unlock"),
      )
    );

  } else {
    $locked_by = user_load_by_name(islandora_object_lock_get_lock_username($object));
    if (module_exists('realname') && isset($locked_by->uid)) {
      $name = realname_load($locked_by);
      if (empty($name)) {
        $name = $locked_by->name;
      }
    } else {
      $name = $locked_by->name;
    }

    $message = t("This object is <strong>locked by <a href=\"!user_url\">@user_name</a></strong>, so it cannot be managed.",
      array(
        '!user_url' => url("user/{$locked_by->uid}"),
        '@user_name' => $name,
      )
    );

    if (islandora_object_lock_request_unlock_access()) {
      $message .= ' ' . t("You may <strong><a href=\"!request_unlock_url\">request that they unlock the object</a></strong>.",
          array(
            '!request_unlock_url' => url("islandora/object/{$object->id}/request_unlock"),
          )
        );
    }

    return $message;
  }
}

/**
 * Will get a number of object locks.
 *
 * @param int $offset
 *   The offset for the object lock query.
 * @param int $limit
 *   The limit for the object lock query.
 *
 * @return array
 *   The locks formated for options in a tableselect.
 */
function islandora_object_lock_get_locks($offset, $limit) {
  $tuque = islandora_get_tuque_connection();

  $repository = $tuque->repository;
  $query = "
    PREFIX islandora_rels_ext: <" . ISLANDORA_RELS_EXT_URI . ">
    PREFIX fm: <" . FEDORA_MODEL_URI . ">
    SELECT ?label ?object ?expiry ?user FROM <#ri> WHERE {
      ?object islandora_rels_ext:" . ISLANDORA_OBJECT_LOCK_USER_PRED . " ?user;
        islandora_rels_ext:" . ISLANDORA_OBJECT_LOCK_EXPIRY_PRED . " ?expiry
    OPTIONAL{?object fm:label ?label}
    }
    ORDER BY ?expiry
    LIMIT $limit
    OFFSET $offset
  ";

  $raw_results = $repository->ri->sparqlQuery($query);
  $results = array();
  foreach ($raw_results as $raw_result) {
    $results[$raw_result['object']['value']] = array(
      'object' => l($raw_result['label']['value'], "islandora/object/{$raw_result['object']['value']}"),
      'expires' => $raw_result['expiry']['value'] == 'indefinite' ? t('Indefinite') : format_date(strtotime($raw_result['expiry']['value'])),
      'user' => $raw_result['user']['value'],
    );
  }

  return $results;
}

/**
 * Will get how many object locks there are.
 *
 * @return int
 *   The number of object locks existing.
 */
function islandora_object_lock_count_locks() {
  $tuque = islandora_get_tuque_connection();
  $repository = $tuque->repository;

  $query = "
    PREFIX islandora_rels_ext: <" . ISLANDORA_RELS_EXT_URI . ">
    SELECT ?object FROM <#ri> WHERE {
      ?object islandora_rels_ext:" . ISLANDORA_OBJECT_LOCK_USER_PRED . " ?user
    }
  ";

  return $repository->ri->countQuery($query, 'sparql');
}

/**
 * Check if an object is locked.
 *
 * @param AbstractObject $object
 *   The object to check.
 *
 * @return bool
 *   TRUE if the object is locked.
 */
function islandora_object_lock_is_locked(AbstractObject $object) {
  $lock = $object->relationships->get(ISLANDORA_RELS_EXT_URI, ISLANDORA_OBJECT_LOCK_EXPIRY_PRED);
  if (count($lock) < 1) {
    return FALSE;
  }
  else {
    $expiry_time = $lock[0]['object']['value'];
    if ($expiry_time != 'indefinite') {
      if (strtotime($expiry_time) < time()) {
        islandora_object_lock_remove_object_lock($object->id);
        return FALSE;
      }
      else {
        return TRUE;
      }
    }
    else {
      return TRUE;
    }
  }
}

/**
 * Helper to check if the current user has the lock.
 *
 * @param AbstractObject $object
 *   The object to be checked.
 *
 * @return bool
 *   TRUE if the current user has a lock on the object; otherwise, FALSE.
 */
function islandora_object_lock_user_has_lock(AbstractObject $object) {
  global $user;

  return islandora_object_lock_is_locked($object) && $user->name == islandora_object_lock_get_lock_username($object);
}
