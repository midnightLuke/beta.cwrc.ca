<?php
/**
 * @file
 * cwrc_workflow.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_workflow_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['cwrc_workflow-recent_stamps'] = array(
    'cache' => 4,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent_stamps',
    'module' => 'cwrc_workflow',
    'node_types' => array(),
    'pages' => 'islandora/object/*',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_workflow-stamp_form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'stamp_form',
    'module' => 'cwrc_workflow',
    'node_types' => array(),
    'pages' => 'islandora/object/*/history',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
