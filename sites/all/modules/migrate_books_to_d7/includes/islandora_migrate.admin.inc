<?php

/**
 * @file
 * islandora_migrate.admin.inc
 */

/**
 * Admin form.
 * @return array
 *   Returns admin form.
 */
function islandora_migrate_admin() {
  $form = array();

  $form['source'] = array(
    '#type' => 'fieldset',
    '#title' => t('Source'),
  );
  $form['source']['islandora_migrate_source_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of source Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_url', ''),
    '#description' => t('URL of source fedora ie http://localhost:8080/fedora/'),
  );
  $form['source']['islandora_migrate_source_user'] = array(
    '#type' => 'textfield',
    '#title' => t('User on source Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_user', 'fedoraAdmin'),
    '#description' => t('User name on source fedora - usually fedoraAdmin'),
  );
  $form['source']['islandora_migrate_source_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password for source Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_password', ''),
    '#description' => t('Password associated with user.'),
  );
  $form['destination'] = array(
    '#type' => 'fieldset',
    '#title' => t('Destination'),
  );
  $form['destination']['islandora_migrate_destination_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of destination Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_url', ''),
    '#description' => t('URL of destination fedora ie http://localhost:8080/fedora/'),
  );
  $form['destination']['islandora_migrate_destination_user'] = array(
    '#type' => 'textfield',
    '#title' => t('User on destination Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_user', 'fedoraAdmin'),
    '#description' => t('User name on source fedora - usually fedoraAdmin'),
  );
  $form['destination']['islandora_migrate_destination_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password for destination Fedora'),
    '#default_value' => variable_get('islandora_migrate_source_password', ''),
    '#description' => t('Password associated with user.'),
  );


  return system_settings_form($form);
}
