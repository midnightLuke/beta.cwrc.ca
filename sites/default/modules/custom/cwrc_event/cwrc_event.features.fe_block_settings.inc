<?php
/**
 * @file
 * cwrc_event.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_event_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-events-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'events-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'news
event/*',
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

  $export['views-events-block_1'] = array(
    'cache' => -1,
    'css_class' => 'homepage-news-event',
    'custom' => 0,
    'delta' => 'events-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -21,
      ),
    ),
    'title' => 'Events',
    'visibility' => 1,
  );

  return $export;
}
