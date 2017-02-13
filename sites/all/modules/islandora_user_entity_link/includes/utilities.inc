<?php

/**
 * @file
 * Holds helper functionality for islandora_user_entity_link.
 */

/**
 * Adds a user to entity link to the RELS-EXT of an object.
 *
 * @param string $object_id
 *   The PID of the object.
 * @param int $user_id
 *   The UID for the Drupal user.
 */
function islandora_user_entity_link_add_link($object_id, $user_id) {
  $islandora_object = islandora_object_load($object_id);
  $link_uri = islandroa_user_entity_link_create_link_uri($user_id);

  $islandora_object->relationships->add(
    ISLANDORA_RELS_EXT_URI,
    ISLANDORA_USER_ENTITY_LINK_LINK_RELATIONSHIP,
    $link_uri,
    RELS_TYPE_FULL_URI
  );
}

/**
 * Removes a user to entity link to the RELS-EXT of an object.
 *
 * @param string $object_id
 *   The PID of the object.
 * @param int $user_id
 *   The UID for the Drupal user.
 */
function islandora_user_entity_link_remove_link($object_id, $user_id) {
  $islandora_object = islandora_object_load($object_id);
  $link_uri = islandroa_user_entity_link_create_link_uri($user_id);

  $islandora_object->relationships->remove(
    ISLANDORA_RELS_EXT_URI,
    ISLANDORA_USER_ENTITY_LINK_LINK_RELATIONSHIP,
    $link_uri,
    RELS_TYPE_FULL_URI
  );

}

/**
 * Gets an object/Drupal user link URI from an Islandora object.
 *
 * @global $base_url
 *   Assumes the current site's base_url.
 *
 * @param AbstractObject $islandora_object
 *   The Islandora object.
 *
 * @return mixed
 *   int the linked user, FALSE if no link.
 */
function islandora_user_entity_link_object_get_link(AbstractObject $islandora_object) {
  global $base_url;

  $link_relations = $islandora_object->relationships->GET(
    ISLANDORA_RELS_EXT_URI,
    ISLANDORA_USER_ENTITY_LINK_LINK_RELATIONSHIP
  );

  if ($link_relations) {
    $link_uri = $link_relations[0]['object']['value'];
    // Only return REL if the link is from this site.
    $link = islandora_user_entity_link_decode($link_uri);
    if ($link['base_url'] == $base_url) {
      return $link['user_id'];
    }
  }

  return FALSE;
}

/**
 * Gets an object linked to a user.
 *
 *
 * @param int $user_id
 *   The UID for the Drupal user.
 *
 * @return mixed
 *   array $linked_object['object'] $linked_object['label'] linked to the user.
 *   FALSE if no link.
 */
function islandora_user_entity_link_user_get_linked_object($user_id) {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $tuque = islandora_get_tuque_connection();

  $link_uri = islandroa_user_entity_link_create_link_uri($user_id);

  $query = "PREFIX islandora: <" . ISLANDORA_RELS_EXT_URI . ">
            PREFIX fm: <" . FEDORA_MODEL_URI . ">
            SELECT ?object ?label
            FROM <#ri>
            WHERE {
              {
                ?object islandora:" . ISLANDORA_USER_ENTITY_LINK_LINK_RELATIONSHIP . " <" . $link_uri . ">;
                  fm:state fm:Active;
              }
              OPTIONAL {
                ?object fm:label ?label
              }
            }";

  $results = $tuque->repository->ri->sparqlQuery($query, 'unlimited');
  if ($results) {
    return array(
      'object' => $results[0]['object']['value'],
      'label' => $results[0]['label']['value'],
    );
  }

  return FALSE;
}

/**
 * Will create a URI defining a link to a Drupal user.
 *
 * @global $base_url
 *   Assumes the current site's base_url.
 *
 * @param int $user_id
 *   The UID for the Drupal user.
 *
 * @return string
 *   The link URI.
 */
function islandroa_user_entity_link_create_link_uri($user_id) {
  global $base_url;
  return "$base_url/user/$user_id";
}

/**
 * This will break out the data from a link URI.
 *
 * @param string $link_uri
 *   The link URI.
 *
 * @return array
 *   $ling['user_id'] the UID for the Drupal user. $ling['nsdr_url'] the
 *   originiating site's base_url.
 */
function islandora_user_entity_link_decode($link_uri) {
  $link = array();

  $site_end_index = strpos($link_uri, '/user/');
  $user_start_index = $site_end_index + 6;
  $link['base_url'] = substr($link_uri, 0, $site_end_index);
  $link['user_id'] = substr($link_uri, $user_start_index);

  return $link;
}

/**
 * This will decode an autocomplete string.
 *
 * @param string $autocomplete
 *   The string to decode.
 *
 * @return string
 *   The PID embeded in the autocomplete string.
 */
function islandora_user_entity_link_decode_autocomplete($autocomplete) {
  // Single quote used as delimiter.
  $entitiy_string_length = strlen($autocomplete);
  $id_start_pos = strrpos($autocomplete, "'", -2) + 1;
  $islandora_object_id_length = $entitiy_string_length - $id_start_pos - 1;
  return substr($autocomplete, $id_start_pos, $islandora_object_id_length);
}
