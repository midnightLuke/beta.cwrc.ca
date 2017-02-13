<?php
/**
 * @file
 * Upload a CWRC-Document's Objects CWRC datastream.
 */

/**
 * Defines the upload form for documents for CWRC.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 *
 * @return array
 *   An array representing a Drupal form to be rendered.
 */
function islandora_cwrc_document_upload_form($form, $form_state) {
  module_load_include('inc', 'islandora_cwrc_document', 'includes/utilities');
  $definition = array();
  $definition['source'] = array(
    '#title' => t('Create Document:'),
    '#description' => t('Select whether the TEI will be uploaded from a file or selected from predefined templates.'),
    '#type' => 'radios',
    '#default_value' => isset($form_state['values']['source']) ? $form_state['values']['source'] : 'file',
    '#options' => array(
      'file' => t('From File'),
      'template' => t('From Template'),
    ),
  );
  $definition['template'] = array(
    '#title' => t('Template'),
    '#type' => 'select',
    '#description' => t('Select a template to use. Templates are stored in the <a href="@template-collection" target="_blank">CWRC Document Template Collection</a>.', array(
      '@template-collection' => '/islandora/object/' . ISLANDORA_CWRC_DOCUMENT_TEMPLATE_COLLECTION_PID,
    )),
    '#default_value' => isset($form_state['values']['template']) ? $form_state['values']['template'] : 'cwrc:blankTEIDocument',
    '#options' => islandora_cwrc_document_get_templates(),
    '#states' => array(
      'visible' => array(
        ':input[name="source"]' => array('value' => 'template'),
      ),
      'required' => array(
        ':input[name="source"]' => array('value' => 'template'),
      ),
    ),
  );
  $definition['file'] = islandora_cwrc_document_get_file_upload_element($form_state);
  $definition['schema'] = array(
    '#title' => t('Schema'),
    '#description' => t('Please select a valid schema for this document.'),
    '#type' => 'select',
    '#options' => islandora_cwrc_document_get_schema_options(),
    '#states' => array(
      'visible' => array(
        ':input[name="source"]' => array('value' => 'file'),
      ),
      'required' => array(
        ':input[name="source"]' => array('value' => 'file'),
      ),
    ),
  );

  // There's a weird issue in Drupal (https://www.drupal.org/node/1592688) where
  // #states can cause things to be required twice. Still functional; just needs
  // that patch to make it look proper.
  $definition['file']['#states'] = array(
    'visible' => array(
      ':input[name="source"]' => array('value' => 'file'),
    ),
    'required' => array(
      ':input[name="source"]' => array('value' => 'file'),
    ),
  );
  return $definition;
}

/**
 * Formats default schema selections for a drop-down.
 *
 * @return array
 *   Array of schemas to select, keyed by PID.
 */
function islandora_cwrc_document_get_schema_options() {
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $schemas = islandora_cwrc_writer_get_schemas();
  $schema_options = array();
  foreach ($schemas as $schema) {
    $pid = $schema['pid'];
    $name = $schema['name'];
    $schema_options[$pid] = $name;
  }
  return $schema_options;
}

/**
 * Checks that the given document is valid according to the given schema.
 */
function islandora_cwrc_document_upload_form_validate(array $form, array &$form_state) {
  if ($form_state['values']['source'] == 'file') {
    islandora_cwrc_document_template_upload_form_validate($form, $form_state);
  }
}

/**
 * Submit handler, adds uploaded file to the object.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 */
function islandora_cwrc_document_upload_form_submit($form, $form_state) {
  module_load_include('inc', 'islandora', 'includes/ingest.form.inc');
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $object = islandora_ingest_form_get_object($form_state);
  if (!isset($object['CWRC'])) {
    $ds = $object->constructDatastream('CWRC', 'M');
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['CWRC'];
  }
  if ($form_state['values']['file']) {
    $file = file_load($form_state['values']['file']);
    $ds->setContentFromFile($file->uri, FALSE);
    $ds->label = $file->filename;
    $schema = islandora_object_load($form_state['values']['schema']);
  }
  else {
    $template = islandora_object_load($form_state['values']['template']);
    $source = $template['TEMPLATE'];
    $ds->setContentFromString($source->content);
    $ds->label = $source->label;

    // Hack the schema out of the template's rels ext.
    $schema_relationship = $template->relationships->get(
      CWRC_RELS_EXT_URI,
      ISLANDORA_CWRC_WRITER_SCHEMA_RELATIONSHIP
    );
    $first_schema = reset($schema_relationship);
    $schema_pid = $first_schema ? $first_schema['object']['value'] : variable_get('islandora_cwrc_writer_default_schema_object', 'cwrc:teiSchema');
    $schema = islandora_object_load($schema_pid);
  }

  // Associate the document with the appropriate schema.
  islandora_cwrc_writer_set_document_schema($object, $schema);
  $ds->mimetype = 'application/xml';
}

/**
 * Upload form for template objects.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The form definition.
 */
function islandora_cwrc_document_template_upload_form($form, $form_state) {
  module_load_include('inc', 'islandora_cwrc_document', 'includes/utilities');
  $form = array(
    'file' => islandora_cwrc_document_get_file_upload_element($form_state),
  );
  $form['file']['#required'] = TRUE;
  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Template Name'),
    '#required' => TRUE,
    '#weight' => -1,
  );
  $form['schema'] = array(
    '#title' => t('Schema'),
    '#description' => t('Please select a valid schema for this document.'),
    '#type' => 'select',
    '#options' => islandora_cwrc_document_get_schema_options(),
  );
  return $form;
}

/**
 * Validation for template uploading. Just wraps the document upload validator.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function islandora_cwrc_document_template_upload_form_validate(&$form, &$form_state) {
  // Is there a file?
  $file = file_load($form_state['values']['file']);
  if ($file === FALSE) {
    form_set_error('file', t('Please upload a file.'));
  }
  else {
    // Is it well-formed XML?
    module_load_include('inc', 'islandora_cwrc_document', 'includes/utilities');
    if (!islandora_cwrc_document_check_xml($file)) {
      form_set_error('file', t('The uploaded file @file is not well-formed XML.', array('@file' => $file->filename)));
    }
  }
}

/**
 * Submit handler to add templates to template objects.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 */
function islandora_cwrc_document_template_upload_form_submit($form, $form_state) {
  module_load_include('inc', 'islandora', 'includes/ingest.form.inc');
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $object = islandora_ingest_form_get_object($form_state);
  if (!isset($object['TEMPLATE'])) {
    $ds = $object->constructDatastream('TEMPLATE', 'M');
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['TEMPLATE'];
  }
  $source = file_load($form_state['values']['file']);
  $ds->setContentFromFile($source->uri, FALSE);
  $ds->label = $source->filename;
  $ds->mimetype = 'application/xml';
  // Set the label of the template given the user input.
  $object->label = check_plain($form_state['values']['label']);
  // Set the template's schema from user selection.
  $schema = islandora_object_load($form_state['values']['schema']);
  islandora_cwrc_writer_set_document_schema($object, $schema);
}

/**
 * Gets a file upload element for CWRC/TEMPLATE datastreams.
 *
 * @param array $form_state
 *   The form state of the form to add the element to.
 *
 * @return array
 *   A file element form definition.
 */
function islandora_cwrc_document_get_file_upload_element($form_state) {
  $upload_size = min((int) ini_get('post_max_size'), (int) ini_get('upload_max_filesize'));
  $extensions = array('xml');
  return array(
    '#title' => t('Document'),
    '#type' => 'managed_file',
    '#description' => t('Select file to upload.<br/>Files must be less than <strong>@size MB.</strong><br/>Allowed file types: <b>@ext.</b>', array('@size' => $upload_size, '@ext' => $extensions[0])),
    '#default_value' => isset($form_state['values']['file']) ? $form_state['values']['file'] : NULL,
    '#upload_location' => file_default_scheme() . '://',
    '#upload_validators' => array(
      'file_validate_extensions' => $extensions,
       // Assume its specified in MB.
      'file_validate_size' => array($upload_size * 1024 * 1024),
    ),
    // The pluploader doesn't play nicely with the states statement we might be
    // using, and we don't need it in any case anyhow.
    '#islandora_plupload_do_not_alter' => TRUE,
  );
}
