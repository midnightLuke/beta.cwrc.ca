<?php

/**
 * @file
 * Upload CWRC XML file.
 */

/**
 * Upload XML form.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   A Drupal form definition.
 */
function cwrc_islandora_xml_file_form(array $form, array &$form_state) {
  return array(
    'file' => array(
      '#type' => 'managed_file',
      '#title' => t('Content XML File'),
      '#description' => t('A file containing a CWRC content XML record. Select no file to create a record from scratch.'),
      '#upload_validators' => array(
        'file_validate_extensions' => array('xml', 'sgm'),
      ),
    ),
  );
}

/**
 * Populate XML Content datastream.
 *
 * Only populates the datastream if a file was uploaded.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function cwrc_islandora_xml_file_form_submit(array &$form, array &$form_state) {
  module_load_include('inc', 'cwrc_islandora_xml', 'includes/utilities');
  $file = file_load($form_state['values']['file']);
  if ($file) {
    $xml_step_storage = &islandora_ingest_form_get_step_storage($form_state, 'cwrc_islandora_xml_upload');
    $object = islandora_ingest_form_get_object($form_state);
    //2013-10-29 - unneeded if not transforming to MODS?
    //$xml_step_storage['created']['MODS'] = islandora_marcxml_populate_mods($object, $file);
    // To ensure the file is only used once, delete it.
    file_delete($file);
    unset($form_state['values']['file']);
  }
}

/**
 * Undo's any changes the regular submit handler did.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function cwrc_islandora_xml_file_form_undo_submit(array &$form, array &$form_state) {
  $xml_step_storage = &islandora_ingest_form_get_step_storage($form_state, 'islandora_marcxml_upload');
  $object = islandora_ingest_form_get_object($form_state);
  //2013-10-29 - not sure what happens here
  //if (isset($xml_step_storage['created']['MODS']) && $marcxml_step_storage['created']['MODS']) {
    //$object->purgeDatastream('MODS');
  //}
  unset($xml_step_storage['created']);
}
