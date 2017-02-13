<?php
/**
 * @file
 * cwrc_menu_links.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_menu_links_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['cwrc_menu_links-login_link'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'login_link',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_menu_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'de_theme' => array(
        'region' => 'masthead',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 2,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
