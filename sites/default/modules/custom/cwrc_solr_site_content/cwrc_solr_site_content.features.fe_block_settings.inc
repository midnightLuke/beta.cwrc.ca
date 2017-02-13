<?php
/**
 * @file
 * cwrc_solr_site_content.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_solr_site_content_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['apachesolr_search-mlt-001'] = array(
    'cache' => 4,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'mlt-001',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'apachesolr_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['apachesolr_search-sort'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sort',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'apachesolr_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'de_theme',
        'weight' => -1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
