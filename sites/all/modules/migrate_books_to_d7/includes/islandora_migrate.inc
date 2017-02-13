<?php

/**
 * @file
 * Logic to move all books in a collection.
 */
@include_once 'sites/all/libraries/tuque/Datastream.php';
@include_once 'sites/all/libraries/tuque/FedoraApi.php';
@include_once 'sites/all/libraries/tuque/FedoraApiSerializer.php';
@include_once 'sites/all/libraries/tuque/Object.php';
@include_once 'sites/all/libraries/tuque/RepositoryConnection.php';
@include_once 'sites/all/libraries/tuque/Cache.php';
@include_once 'sites/all/libraries/tuque/RepositoryException.php';
@include_once 'sites/all/libraries/tuque/Repository.php';
@include_once 'sites/all/libraries/tuque/FedoraRelationships.php';

/**
 * Moves books in collection.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form_state
 *
 * @return array
 *   drupal form definition
 */
function migrate_books_by_collection_form(array $form, array &$form_state) {
  $form = array();
  $form['collection_pid'] = array(
    '#type' => 'textfield',
    '#description' => "Enter pid of collection to be migrated.",
  );
  $form['destination_pid'] = array(
    '#type' => 'textfield',
    '#description' => "Enter pid of destination collection.",
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate this collection.'),
  );
  return $form;
}

/**
 * Submit handler for the form.
 *
 * @param array $form
 *   The form.
 *
 * @param array $form_state
 *   The form state.
 */
function migrate_books_by_collection_form_submit(array $form, array &$form_state) {

  $source_repository = migrate_books_create_source_repository();
  $destination_repository = migrate_books_create_destination_repository();
  $collection_pid = $form_state['values']['collection_pid'];
  $destination_pid = $form_state['values']['destination_pid'];
  // Get all subcollection pids.
  $subcollections = islandora_migrate_get_subcollections($source_repository, $collection_pid, $destination_pid);
  // Build new collection on destination to house migrated objects.
  $pairings = create_pairings($source_repository, $destination_repository, $subcollections);

  $batch = array(
    'title' => t('Migrating Collections'),
    'operations' => array(),
    'file' => drupal_get_path('module', 'islandora_migrate') . '/includes/islandora_migrate.inc',
    'progress_message' => t('@current of @total objects created.'),
  );

  foreach ($pairings as $book_pid => $new_collection_pid) {
    $page_pids = islandora_migrate_get_page_pids($book_pid, $source_repository);
    $batch['operations'][] = array('islandora_migrate_book', array(
        'book_pid' => $book_pid,
        'page_pids' => $page_pids,
        'new_collection_pid' => $new_collection_pid,
        'source_repository' => $source_repository,
        'destination_repository' => $destination_repository,
    ));
  }

  batch_set($batch);
  batch_process();
}

/**
 * Get all book objects associated with collection object.
 *
 * @param string $collection_pid
 *   PID of collection object
 * @param Repository $repository
 *   Repository object
 *
 * @return array
 *   Array of book pids
 */
function islandora_islandora_migrate_get_book_pids($collection_pid, $repository) {
  $query = <<<QUERY
select \$subject from <#ri> 
    where (
      (\$subject <info:fedora/fedora-system:def/relations-external#isMemberOfCollection> <info:fedora/$collection_pid>
       or
       \$subject <info:fedora/fedora-system:def/relations-external#isMemberOf> <info:fedora/$collection_pid>
      )
    and
      (
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/islandora:iaBookCModel>
      or
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/islandora:bookCModel>
      )
    )
QUERY;
  $book_pids = array();
  $collection_objects = $repository->ri->itqlQuery($query, 'unlimited');
  foreach ($collection_objects as $collection_object) {
    $book_pids[] = $collection_object['subject']['value'];
  }
  return $book_pids;
}

/**
 * Get all page objects associated with book or Critical Edition object.
 *
 * @param string $book_pid
 *   Book PID
 * @param Repository $repository
 *   Repository object
 *
 * @return array
 *   array of page pids.
 */
function islandora_migrate_get_page_pids($book_pid, $repository) {
  $query = <<<QUERY
select \$subject from <#ri> 
    where (
      (\$subject <info:fedora/fedora-system:def/relations-external#isMemberOfCollection> <info:fedora/$book_pid>
       or
       \$subject <info:fedora/fedora-system:def/relations-external#isMemberOf> <info:fedora/$book_pid>
      )
    and
      (
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/islandora:pageCModel>
      )
    and \$subject <fedora-model:state> <fedora-model:Active>
    )
QUERY;
  $page_pids = array();
  $page_objects = $repository->ri->itqlQuery($query, 'unlimited');
  foreach ($page_objects as $page_object) {
    $page_pids[] = $page_object['subject']['value'];
  }
  return $page_pids;
}

/**
 * Migrates book to new repository.
 *
 * @param string $book_pid
 *   Book PID
 * @param array $page_pids
 *   Page PIDS
 * @param string $new_collection_pid
 *   Collection PID
 * @param Repository $source_repository
 *   Repository object
 * @param Repository $destination_repository
 *   Repository object
 */
function islandora_migrate_book($book_pid, $page_pids, $new_collection_pid, $source_repository, $destination_repository) {
  module_load_include('inc', 'islandora_paged_content', 'includes/utilities');
  $source_book_object = $source_repository->getObject($book_pid);
  $new_book_object = $destination_repository->constructObject('islandora');
  $new_book_object->label = $source_book_object->label;
  foreach ($source_book_object as $dsid => $content) {
    if ($dsid != 'PDF') {
      $new_book_object->ingestDatastream($content);
    }
  }
  $new_book_object->relationships->changeObjectID($new_book_object->id);
  $new_book_object->relationships->remove(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', NULL);
  $new_book_object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $new_collection_pid);
  $new_book_object->relationships->remove(FEDORA_MODEL_URI, 'hasModel', NULL);
  $new_book_object->relationships->add(FEDORA_MODEL_URI, 'hasModel', 'islandora:bookCModel');
  $ingested_object = islandora_add_object($new_book_object);
  $new_book_pid = $ingested_object->id;

  foreach ($page_pids as $page_pid) {
    $source_page_object = $source_repository->getObject($page_pid);
    $new_page_object = $destination_repository->constructObject('islandora');
    $new_page_object->label = $source_page_object->label;
    $fakepop = count($source_page_object);
    if ($source_page_object['TIFF']) {
      $tiff = $source_page_object['TIFF']->content;
      add_renamed_datastream($new_page_object, 'OBJ', $tiff, 'image/tif');
      islandora_paged_content_page_derive_image_datastreams($new_page_object);
    }
    else {
      add_renamed_datastream($new_page_object, 'JPG', $source_page_object['JPEG']->content, 'image/jpeg');
      add_renamed_datastream($new_page_object, 'TN', $source_page_object['TN']->content, 'image/jpeg');
    }

    add_renamed_datastream($new_page_object, 'OCR', $source_page_object['OCR']->content, 'text/plain');
    add_renamed_datastream($new_page_object, 'DC', $source_page_object['DC']->content, 'text/xml');
    add_renamed_datastream($new_page_object, 'RELS-EXT', $source_page_object['RELS-EXT']->content, 'application/rdf+xml');
    $new_page_object->relationships->changeObjectID($new_page_object->id);
    $new_page_object->relationships->remove(FEDORA_RELS_EXT_URI, 'isMemberOf', NULL);
    $new_page_object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOf', $new_book_pid);
    $new_page_object->relationships->remove(FEDORA_RELS_EXT_URI, 'isPageOf', NULL);
    $new_page_object->relationships->add(FEDORA_RELS_EXT_URI, 'isPageOf', $new_book_pid);

    $new_object = islandora_add_object($new_page_object);
  }
}

/**
 * Creates source repository object.
 * @return Repository
 *   Repository object
 */
function migrate_books_create_source_repository() {
  $source_url = variable_get('islandora_migrate_source_url', '');
  $source_user = variable_get('islandora_migrate_source_user', '');
  $source_password = variable_get('islandora_migrate_source_password', '');
  return migrate_books_create_repository($source_url, $source_user, $source_password);
}

/**
 * Creates destination repository object.
 * @return Repository
 *   Repository object
 */
function migrate_books_create_destination_repository() {
  $destination_url = variable_get('islandora_migrate_destination_url', '');
  $destination_user = variable_get('islandora_migrate_destination_user', '');
  $destination_password = variable_get('islandora_migrate_destination_password', '');
  return migrate_books_create_repository($destination_url, $destination_user, $destination_password);
}

/**
 * Creates Repository.
 *
 * @param url $fedora_url
 *   Fedora URL
 * @param string $username
 *   Fedora username
 * @param string $password
 *   Fedora password
 *
 * @return FedoraRepository
 *   FedoraRepository object
 */
function migrate_books_create_repository($fedora_url, $username, $password) {
  $connection = new RepositoryConnection($fedora_url, $username, $password);
  $connection->reuseConnection = TRUE;
  $repository = new FedoraRepository(new FedoraApi($connection), new SimpleCache());
  return $repository;
}

/**
 * Builds new Collection Object.
 *
 * @param Repository $source_repository
 *   Repository Object
 * @param Repository $destination_repository
 *   Repository object
 * @param array $collection_info
 *   array with 'source' and 'destination' keys
 *
 * @return string
 *   PID of new collection object
 */
function migrate_books_build_new_collection($source_repository, $destination_repository, $collection_info) {
  $collection_pid = $collection_info['collection'];
  $parent_pid = $collection_info['parent'];
  $source_collection_object = $source_repository->getObject($collection_pid);
  $new_collection_object = $destination_repository->constructObject('islandora');
  $new_collection_object->label = $source_collection_object->label;
  foreach ($source_collection_object as $dsid => $content) {
    $new_collection_object->ingestDatastream($content);
  }
  $new_collection_object->relationships->changeObjectID($new_collection_object->id);
  $new_collection_object->relationships->remove(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', NULL);
  $new_collection_object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $parent_pid);
  $ingested_object = islandora_add_object($new_collection_object);
  return $ingested_object->id;
}

/**
 * Adds datastream to new object.
 *
 * @param FedoraObject $fedora_object
 *   FedoraObject
 * @param string $dsid
 *   DSID
 * @param string $content
 *   Datastreamcontent as string
 * @param string $mimetype
 *   MIMETYPE of datastream
 */
function add_renamed_datastream($fedora_object, $dsid, $content, $mimetype) {
  $new_datastream = $fedora_object->constructDatastream($dsid);
  $new_datastream->label = $dsid;
  $new_datastream->mimetype = $mimetype;
  $new_datastream->setContentFromString($content);
  $fedora_object->ingestDatastream($new_datastream);
}

/*
 */

/**
 * Recursively gets all subcollections of given collection.
 *
 * @param Repository $repository
 *   Repository Object
 * @param string $collection_pid
 *   PID of source collection
 * @param string $destination_pid
 *   PID of destintion collection
 *
 * @return array
 *   array with collection objects and their parents
 */
function islandora_migrate_get_subcollections($repository, $collection_pid, $destination_pid) {
  $pids_to_process = array($collection_pid);
  $pids_to_return[] = array('parent' => $destination_pid, 'collection' => $collection_pid);
  while (count($pids_to_process) > 0) {
    $current_pid = array_shift($pids_to_process);
    $query = <<<QUERY
select \$subject from <#ri> 
    where (
      (\$subject <info:fedora/fedora-system:def/relations-external#isMemberOfCollection> <info:fedora/$current_pid>
       or
       \$subject <info:fedora/fedora-system:def/relations-external#isMemberOf> <info:fedora/$current_pid>
      )
    and
      (
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/islandora:collectionCModel>
      )
    and \$subject <fedora-model:state> <fedora-model:Active>
    )
QUERY;

    $collection_objects = $repository->ri->itqlQuery($query, 'unlimited');
    foreach ($collection_objects as $collection_object) {
      $pids_to_process[] = $collection_object['subject']['value'];
      $pids_to_return[] = array('parent' => $current_pid, 'collection' => $collection_object['subject']['value']);
    }
  }
  return $pids_to_return;
}

/*
 * Maps new collection PIDS back to source collection pids to allow a meaningful
 * directory structure to be created.
 */

/**
 * Maps new collection PIDS back to source collection pids.
 *
 * @param Repository $source_repository
 *   Repository object
 * @param Repository $destination_repository
 *   Repository object
 * @param array $source_pairings
 *   array of collection objects to be cloned
 *
 * @return array
 *   array matching source collections to their cloned counterparts
 */
function create_pairings($source_repository, $destination_repository, $source_pairings) {
  $mappings[$source_pairings[0]['parent']] = $source_pairings[0]['parent'];
  foreach ($source_pairings as $current) {
    $current_collection = $current['collection'];
    $current_parent = $current['parent'];
    $args = array('collection' => $current_collection, 'parent' => $mappings[$current_parent]);
    $new_collection = migrate_books_build_new_collection($source_repository, $destination_repository, $args);
    $mappings[$current_collection] = $new_collection;
  }

  foreach ($mappings as $source => $destination) {
    $book_pids = islandora_islandora_migrate_get_book_pids($source, $source_repository);
    foreach ($book_pids as $book_pid) {
      $pairings[$book_pid] = $destination;
    }
  }
  return $pairings;
}

function save_whole_book_as_zip($book_pid, $destination_directory) {

  $book_pid = 'islandora:17246';
  $destination_directory = '/Users/astanley/SampleFiles/Livesay/Page_20';
  mkdir($destination_directory, 0700, TRUE);

  $username = 'fedoraAdmin';
  $password = 'anotherFed0r@@dmin';
  $fedora_url = '137.149.200.50:8080/fedora';
  $repository = migrate_books_create_repository($fedora_url, $username, $password);
  $fedora_object = $repository->getObject($book_pid);
  $fakepop = count($fedora_object);
  foreach ($fedora_object as $dsid => $content) {
    file_put_contents("$destination_directory/$dsid", $content->content);
  }
}

function update_namespace($pid, $new_namespace, $purge = FALSE) {
  module_load_include('inc', 'islandora', 'includes/IslandoraTuque');
  $tuque = new IslandoraTuque();
  $repository = $tuque->repository;
  $source_object = islandora_object_load($pid);
  $new_object = $repository->constructObject($new_namespace);
  $new_object->label = $source_object->label;
  foreach ($source_object as $dsid => $content) {
    $new_object->ingestDatastream($content);
  }
  $new_object->relationships->changeObjectID($new_object->id);
  $ingested_object = islandora_add_object($new_object);
  $new_pid = $ingested_object->id;
  drupal_set_message(t('Created @pid', array('@pid' => $new_pid)));
  if ($purge) {
    $repository->purgeObject($pid);
  }
}