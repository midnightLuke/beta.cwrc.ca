<?php
/**
 * @file
 * Utility functions.
 */

/**
 * Helper to load up the CWRC Writer.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 * @param AbstractObject $object
 *   An object to be edited.
 * @param array $config
 *   Any configuration options to be merged with the default settings.
 *
 * @return array
 *   An array to be rendered.
 */
function islandora_cwrc_document_display_cwrc_writer($form, $form_state, AbstractObject $object, array $config = array()) {
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  module_load_include('inc', 'islandora', 'includes/breadcrumb');
  drupal_set_title($object->label);
  drupal_set_breadcrumb(islandora_get_breadcrumbs($object));
  form_load_include($form_state, 'inc', 'islandora_object_lock', 'includes/form_handlers');
  if (isset($config['initial_mode']) && $config['initial_mode'] != 'read') {
    islandora_object_lock_acquire_during_alter($form, $form_state, $object, 'CWRC', NULL, TRUE, "islandora/object/{$object->id}");
  }

  return array(
    'cwrc_writer' => array(
      '#theme' => 'islandora_cwrc_writer',
      '#object' => $object,
      '#schema' => islandora_cwrc_writer_get_document_schema_pid($object),
      '#documents' => array($object->id),
      '#sources' => array(),
      '#config' => $config,
    ),
  );
}

/**
 * Show the note version of the CWRC-Writer.
 */
function islandora_cwrc_document_display_cwrc_writer_note(AbstractObject $object) {
    module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
    return array(
        '#type' => 'page',
        '#theme_wrappers' => array('islandora_cwrc_writer_iframe'),
        'content' => array(
            '#theme' => 'islandora_cwrc_writer_note',
            '#documents' => array($object->id),
            '#schema' => islandora_cwrc_writer_get_document_schema_pid($object),
            ),
        );
    //2016-09-27 - removed drupal_goto to add schemaId to call
    //drupal_goto('cwrc/editor/note.htm');
}

/**
 * Wrapper for islandora_download_datastream() that modifies CWRC datastreams.
 *
 * @see islandora_download_datastream()
 */
function islandora_cwrc_document_download_datastream(AbstractDatastream $datastream) {
  islandora_cwrc_document_view_datastream($datastream, TRUE);
}

/**
 * Wrapper for islandora_view_datastream() that styles CWRC datastreams.
 *
 * @see islandora_view_datastream()
 */
function islandora_cwrc_document_view_datastream(AbstractDatastream $datastream, $download = FALSE, $version = NULL) {
  module_load_include('inc', 'islandora', 'includes/datastream');
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/document');

  try {
    $object = $datastream->parent;

    // TODO: This shouldn't be hardcoded, and should be configurable.  We'd
    // have to push DSID/CMODEL pairs into configuration since this menu
    // callback is meant to imitate islandora_view_datastream's interface.
    if (!(in_array($datastream->id, array("CWRC", "TEMPLATE")) && in_array('cwrc:documentCModel', $object->models))) {
      throw new InvalidArgumentException("Attempting to style incorrect datastream or parent object is not a CWRC document.");
    }

    $result = islandora_cwrc_writer_style_document($datastream, $object);

    // Otherwise, make a temp datastream and serve the styled contents.
    $modified = file_unmanaged_save_data($result, 'temporary://');

    // Construct a dummy datastream. This won't be ingested, but is rather
    // just passed on to islandora_view_datastream() in lieu of the
    // regular one so we can reuse that code.
    $download_version = $object->constructDatastream('CWRC_DOWNLOADABLE');
    $download_version->label = $datastream->label;
    $download_version->state = $datastream->state;
    $download_version->mimetype = $datastream->mimetype;
    $download_version->createdDate = $datastream->createdDate;
    $download_version->setContentFromFile($modified);
    // No size data exists until the datastream is ingested, so set it
    // now.
    $download_version->size = filesize($modified);
    unlink($modified);
    islandora_view_datastream($download_version, $download);
  }
  catch (InvalidArgumentException $e) {
    islandora_view_datastream($datastream, $download, $version);
  }
}

/**
 * Check that a file is well-formed xml.
 *
 * @param file $file
 *   A file object.
 *
 * @return bool
 *   Returns TRUE if xml is well-formed, or FALSE if it is not.
 */
function islandora_cwrc_document_check_xml($file) {
  // Check that the uploaded file is well-formed XML.
  libxml_use_internal_errors(TRUE);
  $file_contents = file_get_contents(drupal_realpath($file->uri));
  // XXX: Remove xml-model tag for validation as it will trigger a libxml error
  // depending on the compiled libxml2 version.
  $file_contents = preg_replace('/<\?xml-model .*\?>/', '', $file_contents);
  simplexml_load_string($file_contents);
  $errors = count(libxml_get_errors());
  libxml_use_internal_errors(FALSE);
  if ($errors) {
    return FALSE;
  }
  return TRUE;
}

/**
 * Gets an array of stock templates from the xml/templates folder.
 *
 * @return array
 *   An array containing multiple stock template profiles, using the form:
 *   - 'pid' for the destination PID of the template,
 *   - 'label' for the template label, and
 *   - 'filename' for the name of the template XML file.
 *   - 'schema' for the associated schema object
 */
function islandora_cwrc_document_get_stock_templates() {
  return array(
    array(
      'pid' => 'cwrc:biographyTemplate',
      'label' => 'Biography (Template)',
      'filename' => "biography.xml",
      'url' => "http://cwrc.ca/templates/orlando_biography_template.xml",
      'schema' => "cwrc:biographySchema",
    ),
    array(
      'pid' => 'cwrc:blankTEIDocument',
      'label' => 'Blank TEI Document',
      'filename' => "blank_TEI_document.xml",
      'url' => "http://cwrc.ca/templates/blank_template-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:entryTemplate',
      'label' => 'CWRC Entry (Template)',
      'filename' => "cwrc_entry_template.xml",
      'url' => "http://cwrc.ca/templates/cwrc_entry_template.xml",
      'schema' => "cwrc:entrySchema",
    ),
    array(
      'pid' => 'cwrc:eventTemplate',
      'label' => 'Event (Template)',
      'filename' => "event.xml",
      'url' => "http://cwrc.ca/templates/orlando_event_template.xml",
      'schema' => "cwrc:eventsSchema",
    ),
    array(
      'pid' => 'cwrc:letterTemplate',
      'label' => 'Letter (TEI Template)',
      'filename' => "letter.xml",
      'url' => "http://cwrc.ca/templates/letter_template-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:poemTemplate',
      'label' => 'Poem (TEI Template)',
      'filename' => "poem.xml",
      'url' => "http://cwrc.ca/templates/poem_template-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:proseTemplate',
      'label' => 'Prose (TEI Template)',
      'filename' => "prose.xml",
      'url' => "http://cwrc.ca/templates/prose_template-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:sampleBiography',
      'label' => 'Biography (Sample)',
      'filename' => 'sample_biography.xml',
      'url' => "http://cwrc.ca/templates/orlando_biography_sample.xml",
      'schema' => "cwrc:biographySchema",
    ),
    array(
      'pid' => 'cwrc:sampleLetter',
      'label' => 'Letter (TEI Sample)',
      'filename' => 'sample_letter.xml',
      'url' => "http://cwrc.ca/templates/sample_letter-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:samplePoem',
      'label' => 'Poem (TEI Sample)',
      'filename' => 'sample_poem.xml',
      'url' => "http://cwrc.ca/templates/sample_poem-TEI.xml",
      'schema' => "cwrc:teiLiteSchema",
    ),
    array(
      'pid' => 'cwrc:sampleWriting',
      'label' => 'Writing (Sample)',
      'filename' => 'sample_writing.xml',
      'url' => "http://cwrc.ca/templates/orlando_writing_sample.xml",
      'schema' => "cwrc:writingSchema",
    ),
    array(
      'pid' => 'cwrc:writingTemplate',
      'label' => 'Writing (Template)',
      'filename' => 'writing.xml',
      'url' => "http://cwrc.ca/templates/orlando_writing_template.xml",
      'schema' => "cwrc:writingSchema",
    ),
  );
}

/**
 * Gets template objects with TEMPLATE datastreams as select form options.
 *
 * @return array
 *   An associative array pairing template PIDs with their labels.
 */
function islandora_cwrc_document_get_templates() {
  $content_model = ISLANDORA_CWRC_DOCUMENT_TEMPLATE_CONTENT_MODEL;
  $query = <<<EOQ
SELECT ?pid ?label
FROM <#ri>
WHERE {
  ?pid <fedora-model:hasModel> <info:fedora/$content_model> .
  ?pid <fedora-model:label> ?label .
  ?ds  <fedora-view:disseminationType> <info:fedora/*/TEMPLATE> .
  ?pid <info:fedora/fedora-system:def/view#disseminates> ?ds
}
EOQ;
  $connection = islandora_get_tuque_connection();
  $results = $connection->repository->ri->sparqlQuery($query);
  $templates = array();
  foreach ($results as $result) {
    $templates[$result['pid']['value']] = $result['label']['value'];
  }
  asort($templates);
  return $templates;
}
