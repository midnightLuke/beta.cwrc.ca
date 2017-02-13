<?php

/**
 * @file
 * Holds the schema and css upload form..
 */

/**
 * The schema upload form.
 *
 * @param array $form
 *   The current form.
 * @param array $form_state
 *   The current form state.
 *
 * @return array
 *   The current form.
 */
function islandora_cwrc_writer_schema_upload_form(array $form, array &$form_state) {
  $upload_size = min((int) ini_get('post_max_size'), (int) ini_get('upload_max_filesize'));
  $rng_extensions = array('rng');
  $css_extensions = array('css');
  return array(
    'label' => array(
      '#title' => t('Title'),
      '#description' => t('Please give a unique title for this schema.'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#element_validate' => array('islandora_cwrc_writer_schema_upload_form_validate_label'),
    ),
    'rng_file' => array(
      // This is a hack to get around that pluploader doesn't display #required.
      '#prefix' => theme('form_element_label', array(
        'element' => array(
          '#id' => 'edit-rng-file',
          '#title' => t('RNG File'),
          '#title_display' => 'before',
          '#required' => TRUE,
        ),
      )),
      '#title_display' => 'invisible',
      // End hack.
      '#title' => t('RNG File'),
      '#type' => 'managed_file',
      '#required' => TRUE,
      '#description' => t('Select file to upload.<br/>Files must be less than <strong>@size MB.</strong><br/>Allowed file types: <strong>@ext.</strong>', array('@size' => $upload_size, '@ext' => $rng_extensions[0])),
      '#default_value' => isset($form_state['values']['rng_file']) ? $form_state['values']['rng_file'] : NULL,
      '#upload_location' => 'public://',
      '#upload_validators' => array(
        'file_validate_extensions' => $rng_extensions,
         // Assume it's specified in MB.
        'file_validate_size' => array($upload_size * 1024 * 1024),
      ),
    ),
    'css_file' => array(
      // This is a hack to get around that pluploader doesn't display #required.
      '#prefix' => theme('form_element_label', array(
        'element' => array(
          '#id' => 'edit-css-file',
          '#title' => t('CSS File'),
          '#title_display' => 'before',
          '#required' => TRUE,
        ),
      )),
      '#title_display' => 'invisible',
      // End hack.
      '#title' => t('CSS File'),
      '#type' => 'managed_file',
      '#required' => TRUE,
      '#description' => t('Select file to upload.<br/>Files must be less than <strong>@size MB.</strong><br/>Allowed file types: <strong>@ext.</strong>', array('@size' => $upload_size, '@ext' => $css_extensions[0])),
      '#default_value' => isset($form_state['values']['rng_file']) ? $form_state['values']['rng_file'] : NULL,
      '#upload_location' => 'public://',
      '#upload_validators' => array(
        'file_validate_extensions' => $css_extensions,
        // Assume it's specified in MB.
        'file_validate_size' => array($upload_size * 1024 * 1024),
      ),
    ),
  );
}

/**
 * Validates that the given label is unique among schema objects.
 *
 * @param array $element
 *   The element to validate.
 * @param array $form_state
 *   The drupal form state.
 * @param array $form
 *   The drupal form.
 */
function islandora_cwrc_writer_schema_upload_form_validate_label(array $element, array &$form_state, array $form) {
  $tuque = islandora_get_tuque_connection();
  $label = $element['#value'];
  $query = <<<EOT
PREFIX fedora-model: <info:fedora/fedora-system:def/model#>
SELECT ?object WHERE {
  ?object <fedora-model:hasModel> <info:fedora/cwrc:schemaCModel> ;
          <fedora-model:label> "$label"
}
EOT;
  $count = $tuque->repository->ri->countQuery($query, 'sparql');
  if ($count !== 0) {
    form_error($element, t('The label "%label" is already in use.', array('%label' => $element['#value'])));
  }
}

/**
 * Adds the uploaded files to the ingestible object.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 */
function islandora_cwrc_writer_schema_upload_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'islandora', 'includes/ingest.form');
  $object = islandora_ingest_form_get_object($form_state);
  $object->label = $form_state['values']['label'];
  if (empty($object['SCHEMA'])) {
    $ds = $object->constructDatastream('SCHEMA', 'M');
    $ds->mimetype = "application/xml";
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['SCHEMA'];
  }
  $rng_file = file_load($form_state['values']['rng_file']);
  $rng_path = drupal_realpath($rng_file->uri);
  $ds->setContentFromFile($rng_path, FALSE);
  if ($ds->label !== $rng_file->filename) {
    $ds->label = $rng_file->filename;
  }

  if (empty($object['CSS'])) {
    $ds = $object->constructDatastream('CSS', 'M');
    $ds->mimetype = "text/css";
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['CSS'];
  }
  $css_file = file_load($form_state['values']['css_file']);
  $css_path = drupal_realpath($css_file->uri);
  $ds->setContentFromFile($css_path, FALSE);
  if ($ds->label !== $css_file->filename) {
    $ds->label = $css_file->filename;
  }

}
