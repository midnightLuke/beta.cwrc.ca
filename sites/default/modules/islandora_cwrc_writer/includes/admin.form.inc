<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_cwrc_writer_admin_settings_form(array $form, array &$form_state) {
  return system_settings_form(array(
    'objects' => array(
      '#type' => 'fieldset',
      '#title' => t('Objects'),
      'islandora_cwrc_writer_default_schema_object' => array(
        '#type' => 'textfield',
        '#title' => t('Default Schema Object'),
        '#autocomplete_path' => 'islandora/cwrc-writer/autocomplete/schema',
        '#required' => TRUE,
        '#default_value' => variable_get('islandora_cwrc_writer_default_schema_object', 'cwrc:teiSchema'),
        '#description' => t('The PID of schema object to use as the default for validating / rendering documents.'),
        '#element_validate' => array('islandora_cwrc_writer_admin_settings_form_validate_schema_pid'),
      ),
      'islandora_cwrc_writer_person_entity_collection' => array(
        '#type' => 'textfield',
        '#title' => t('Person Entity Collection'),
        '#autocomplete_path' => 'islandora/basic_collection/find_collections',
        '#required' => TRUE,
        '#default_value' => variable_get('islandora_cwrc_writer_person_entity_collection', 'cwrc:personEntityCollection'),
        '#description' => t('The PID of the collection in which to add new <strong>person</strong> entity objects.'),
        '#element_validate' => array('islandora_cwrc_writer_admin_settings_form_validate_collection_pid'),
      ),
      'islandora_cwrc_writer_organization_entity_collection' => array(
        '#type' => 'textfield',
        '#title' => t('Organization Entity Collection'),
        '#autocomplete_path' => 'islandora/basic_collection/find_collections',
        '#required' => TRUE,
        '#default_value' => variable_get('islandora_cwrc_writer_organization_entity_collection', 'cwrc:organizationEntityCollection'),
        '#description' => t('The PID of the collection in which to add new <strong>organization</strong> entity objects.'),
        '#element_validate' => array('islandora_cwrc_writer_admin_settings_form_validate_collection_pid'),
      ),
      'islandora_cwrc_writer_title_entity_collection' => array(
        '#type' => 'textfield',
        '#title' => t('Title Entity Collection'),
        '#autocomplete_path' => 'islandora/basic_collection/find_collections',
        '#required' => TRUE,
        '#default_value' => variable_get('islandora_cwrc_writer_title_entity_collection', 'cwrc:titleEntityCollection'),
        '#description' => t('The PID of the collection in which to add new <strong>title</strong> entity objects.'),
        '#element_validate' => array('islandora_cwrc_writer_admin_settings_form_validate_collection_pid'),
      ),
      'islandora_cwrc_writer_place_entity_collection' => array(
        '#type' => 'textfield',
        '#title' => t('Place Entity Collection'),
        '#autocomplete_path' => 'islandora/basic_collection/find_collections',
        '#required' => TRUE,
        '#default_value' => variable_get('islandora_cwrc_writer_place_entity_collection', 'cwrc:placeEntityCollection'),
        '#description' => t('The PID of the collection in which to add new <strong>place</strong> entity objects.'),
        '#element_validate' => array('islandora_cwrc_writer_admin_settings_form_validate_collection_pid'),
      ),
    ),
    'apis' => array(
      '#type' => 'fieldset',
      '#title' => t('APIs'),
      'islandora_cwrc_writer_cwrc_api_url' => array(
        '#type' => 'textfield',
        '#title' => t('CWRC API URL'),
        '#description' => t('This REST end point is used for creating/editing/searching for entities.'),
        '#default_value' => variable_get('islandora_cwrc_writer_cwrc_api_url', 'cwrc/api'),
      ),
      'islandora_cwrc_writer_geo_names_url' => array(
        '#type' => 'textfield',
        '#title' => t('GeoNames URL'),
        '#description' => t(
          'This REST end point is used for searching the <a href="@url">GeoNames Service</a>.',
          array('@url' => url('https://github.com/cwrc/CWRC-Mapping-Timelines-Project/tree/master/geonames'))
        ),
        '#default_value' => variable_get('islandora_cwrc_writer_geo_names_url', 'geonames'),
      ),
      'islandora_cwrc_writer_google_geocode_url' => array(
        '#type' => 'textfield',
        '#title' => t('Google Geocode URL'),
        '#description' => t('This REST end point is used for searching the Google Geocode database.'),
        '#default_value' => variable_get('islandora_cwrc_writer_google_geocode_url', 'http://maps.googleapis.com/maps/api/geocode/xml'),
      ),
      'islandora_cwrc_writer_viaf_url' => array(
        '#type' => 'textfield',
        '#title' => t('VIAF URL'),
        '#description' => t(
          'This REST end point is used for searching <a href="@url">The Virtual International Authority File</a> database.',
          array('@url' => url('https://viaf.org/'))
        ),
        '#default_value' => variable_get('islandora_cwrc_writer_viaf_url', 'viaf'),
      ),
      'islandora_cwrc_writer_repository_base_object_url' => array(
        '#type' => 'textfield',
        '#title' => t('Repository Base Object URL'),
        '#description' => t('Used to denote the URL used as the base for the repository. Left empty this will default to the base root. Note a trailing slash is needed if not using the default.'),
        '#default_value' => variable_get('islandora_cwrc_writer_repository_base_object_url', ''),
      ),
    ),
  ));
}

/**
 * Validates that the given schema exists.
 *
 * @param array $element
 *   The form element containing the pid.
 * @param array $form_state
 *   The Drupal form state.
 * @param array $form
 *   The Drupal form.
 */
function islandora_cwrc_writer_admin_settings_form_validate_schema_pid(array $element, array &$form_state, array $form) {
  $pid = $element['#value'];
  $object = islandora_object_load($pid);
  if (!$object) {
    form_error($element, t('The object specified %pid, does not exist.', array('%pid' => $pid)));
  }
  elseif (!in_array(ISLANDORA_CWRC_WRITER_SCHEMA_CONTENT_MODEL, $object->models)) {
    form_error($element, t('The given object %label (%pid) is not a CWRC-Writer schema object.', array('%label' => $object->label, '%pid' => $pid)));
  }
}

/**
 * Validates that the given collection exists.
 *
 * @param array $element
 *   The form element containing the pid.
 * @param array $form_state
 *   The Drupal form state.
 * @param array $form
 *   The Drupal form.
 */
function islandora_cwrc_writer_admin_settings_form_validate_collection_pid(array $element, array &$form_state, array $form) {
  $pid = $element['#value'];
  $object = islandora_object_load($pid);
  if (!$object) {
    form_error($element, t('The object specified %pid, does not exist.', array('%pid' => $pid)));
  }
  elseif (!in_array('islandora:collectionCModel', $object->models)) {
    form_error($element, t('The given object %label (%pid) is not a collection.', array('%label' => $object->label, '%pid' => $pid)));
  }
  // @todo Check the collection policy to see if it can contain the given type.
}
