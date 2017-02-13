<?php

/**
 * @file
 * Logic to harvest cleaned up OCR from Critical Edition.
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
 * Form to harvest cleaned up OCR from Critical Edition objects in D6.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form_state
 *
 * @return array
 *   drupal form definition
 */
function migrate_ocr_by_collection_form(array $form, array &$form_state) {
  $form = array();
  $form['source'] = array(
    '#type' => 'textfield',
    '#description' => "Enter pid of d6 critical edition to be mined.",
    '#default_value' => 'islandora:',
  );
  $form['destination'] = array(
    '#type' => 'textfield',
    '#description' => "Enter d7 destination book object ",
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
function migrate_ocr_by_collection_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'migrate_books', 'includes/book_migrate');
  $source_repository = migrate_books_create_source_repository();
  $destination_repository = migrate_books_create_destination_repository();
  $source = $form_state['values']['source'];
  $destination = $form_state['values']['destination'];

  $crited_page_pids = migrate_books_get_page_pids($source_repository, $source);
  $book_page_pids = migrate_books_get_page_pids($destination_repository, $destination);
  $pairings = array();
  for ($count = 0; $count < count($crited_page_pids); $count++) {
    $pairings[] = array('source' => $crited_page_pids[$count], 'destination' => $book_page_pids[$count]);
  }

  $batch = array(
    'title' => t('Migrating OCR'),
    'operations' => array(),
    'file' => drupal_get_path('module', 'migrate_books') . '/includes/migrate_ocr.inc',
    'progress_message' => t('@current of @total objects created.'),
  );

  foreach ($pairings as $pairing) {

    $batch['operations'][] = array('migrate_book_update_ocr', array(
        'repository_49' => $source_repository,
        'repository_50' => $destination_repository,
        'pairing' => $pairing,
      ));
  }

  batch_set($batch);
  batch_process();
}

/**
 * Get all page pids associated with a given book or critical edition object.
 *
 * @param Repository $repository
 *   Tuque repository object
 * @param string $source
 *   PID of book object
 *
 * @return array
 *   Array of page pids
 */
function migrate_books_get_page_pids($repository, $source) {
  $query = <<<XML
  select \$object \$page from <#ri>
    where \$object <fedora-rels-ext:isMemberOf> <info:fedora/$source>
    and (\$object <info:islandora/islandora-system:def/paged-item-info#sequenceNumber> \$page
    or \$object <http://islandora.ca/ontology/relsext#isSequenceNumber> \$page)
  order by \$page
XML;

  $pids = array();
  $objects = $repository->ri->itqlQuery($query, 'unlimited');
  foreach ($objects as $object) {
    $pids[] = $object['object']['value'];
  }
  return $pids;
}


/**
 * Takes CWRC data from source page, cleans it, and writes it new repository.
 *
 * @param Repository $source_repository
 *   Tuque repository object
 * @param Repository $destination_repository
 *   Tuque repository object
 * @param array $pairing
 *   Array with 'source' and 'destination' keys
 */
function migrate_book_update_ocr($source_repository, $destination_repository, $pairing) {
  $crited_page = $source_repository->getObject($pairing['source']);
  $destination_page = $destination_repository->getObject($pairing['destination']);
  $content = new SimpleXMLElement($crited_page['CWRC']->content);
  $tei = $content->body;
  $cleaned_tei = strip_tags($tei->asXML());
  $destination_page['OCR']->content = $cleaned_tei;
}


/**
 * Extracts all critical editions associated with book objects in collection.
 *
 * @param string $collection_pid
 *   PID of collection object
 */
function bulk_info($collection_pid) {
  module_load_include('inc', 'islandora_basic_collection', 'includes/utilities');
  module_load_include('inc', 'migrate_books', 'includes/book_migrate');

  $fedora_49_url = "http://modernistcommons.ca:8080/fedora";
  $source_repository = migrate_books_create_repository($fedora_49_url);
  $book_object = $source_repository->getObject($collection_pid);
  $book_pids = islandora_basic_collection_get_child_pids($book_object);
  $output = array();
  $tab_data = '';
  foreach ($book_pids as $book) {
    $crit_query = <<<STRING
select \$subject \$title from <#ri>
where (\$subject <http://islandora.ca/ontology/relsext#isCriticalEditionOf> '$book'
and \$subject <info:fedora/fedora-system:def/model#state> <info:fedora/fedora-system:def/model#Active>
and \$subject <dc:title> \$title)
STRING;

    $critical_editions = $source_repository->ri->itqlQuery($crit_query, 'unlimited');
    $output[$book] = $critical_editions;
    if (!empty($critical_editions)) {
      $tab_data .= $critical_editions[0]['subject']['value'] . " " . str_replace('Critical Edition of ', '', $critical_editions[0]['title']['value'] . "\n");
    }
  }

  print $tab_data;
}
