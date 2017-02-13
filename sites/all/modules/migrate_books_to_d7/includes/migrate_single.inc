<?php

/**
 * @file
 * Logic to move single object.
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
 * Migrates single book object from one repository to another.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form_state
 *
 * @return array
 *   drupal form definition
 */
function migrate_single_form(array $form, array &$form_state) {
  $form = array();
  $form['source'] = array(
    '#type' => 'textfield',
    '#description' => "Enter pid of d6 book to me moved.",
    '#default_value' => 'islandora:',
  );
  $form['destination'] = array(
    '#type' => 'textfield',
    '#description' => "Enter d7 destination collection ",
    '#default_value' => 'islandora:',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate this book.'),
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
function migrate_single_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'migrate_books', 'includes/book_migrate');
  $source = $form_state['values']['source'];
  $destination = $form_state['values']['destination'];
  islandora_move_single_book($source, $destination);
}

/**
 * Moves single book object.
 *
 * @param string $source_book
 *   PID of source book
 * @param string $destination_collection
 *   PID of destination collection
 *
 * @return string
 *   Confirmation message
 */
function islandora_move_single_book($source_book, $destination_collection) {
  $source_repository = migrate_books_create_source_repository();
  $destination_repository = migrate_books_create_destination_repository();
  $source_pages = islandora_migrate_get_page_pids($source_book, $source_repository);
  islandora_migrate_book($source_book, $source_pages, $destination_collection, $source_repository, $destination_repository);
  return "Success";
}
