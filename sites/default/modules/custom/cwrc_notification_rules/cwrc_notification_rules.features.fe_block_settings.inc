<?php
/**
 * @file
 * cwrc_notification_rules.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_notification_rules_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['cwrc_notification_rules-notification_icon'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'notification_icon',
    'module' => 'cwrc_notification_rules',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'masthead',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
