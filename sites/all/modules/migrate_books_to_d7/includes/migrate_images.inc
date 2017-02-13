<?php

/**
 * @file
 * Logic to move all images in a collection.
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
 * Migrates all images to new collection.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form_state
 *
 * @return array
 *   drupal form definition
 */
function migrate_images_by_collection_form(array $form, array &$form_state) {
  $form = array();
  $form['source'] = array(
    '#type' => 'textfield',
    '#description' => "Enter pid of d6 collection to be migrated.",
    '#default_value' => 'islandora:',
  );
  $form['destination'] = array(
    '#type' => 'textfield',
    '#description' => "Enter d7 destination collection",
    '#default_value' => 'islandora:',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate these images.'),
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
function migrate_images_by_collection_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'migrate_books', 'includes/book_migrate');
  $source_repository = migrate_books_create_source_repository();
  $destination_repository = migrate_books_create_destination_repository();
  $source = $form_state['values']['source'];
  $destination = $form_state['values']['destination'];
  $image_pids = migrate_books_get_image_pids($source_repository, $source);

  $batch = array(
    'title' => t('Migrating Images'),
    'operations' => array(),
    'file' => drupal_get_path('module', 'migrate_books') . '/includes/migrate_images.inc',
    'progress_message' => t('@current of @total objects created.'),
  );

  foreach ($image_pids as $image_pid) {

    $batch['operations'][] = array('migrate_books_build_new_image', array(
        'repository_49' => $source_repository,
        'repository_50' => $destination_repository,
        'source_pid' => $image_pid,
        '$destination_dir_pid' => $destination,
      ));
  }

  batch_set($batch);
  batch_process();
}

/**
 * Returns PIDS of all image objects within an identified directory.
 *
 * @param Repository $source_repository
 *   Repository object
 * @param string $source
 *   PID of source directory
 *
 * @return array
 *   array of image pids
 */
function migrate_books_get_image_pids($source_repository, $source) {
  $query = <<<QUERY
select \$subject from <#ri> 
    where (
      (\$subject <info:fedora/fedora-system:def/relations-external#isMemberOfCollection> <info:fedora/$source>
       or
       \$subject <info:fedora/fedora-system:def/relations-external#isMemberOf> <info:fedora/$source>
      )
    and
      (
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/islandora:sp_large_image_cmodel>
      or
      \$subject <info:fedora/fedora-system:def/model#hasModel> <info:fedora/sp_basic_image_cmodel>
      )
    )
QUERY;

  $image_pids = array();
  $image_objects = $source_repository->ri->itqlQuery($query, 'unlimited');
  foreach ($image_objects as $image_object) {
    $image_pids[] = $image_object['subject']['value'];
  }
  return $image_pids;
}
/*
 * Clones image object from D6 to D7
 */
/**
 * Clones image objects.
 *
 * @param Repository $source_repository
 *   Repository object
 * @param Repository $destination_repository
 *   Repository object
 * @param string $source_pid
 *   PID of source object
 * @param string $destination_dir_pid
 *   PID of destination directory
 *
 * @return string
 *   PID of newly created object
 */
function migrate_books_build_new_image($source_repository, $destination_repository, $source_pid, $destination_dir_pid) {

  $source_image_object = $source_repository->getObject($source_pid);
  $new_image_object = $destination_repository->constructObject('islandora');
  $new_image_object->label = $source_image_object->label;
  foreach ($source_image_object as $dsid => $content) {
    $new_image_object->ingestDatastream($content);
  }
  $new_image_object->relationships->changeObjectID($new_image_object->id);
  $new_image_object->relationships->remove(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', NULL);
  $new_image_object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $destination_dir_pid);
  $ingested_object = islandora_add_object($new_image_object);
  return $ingested_object->id;
}
