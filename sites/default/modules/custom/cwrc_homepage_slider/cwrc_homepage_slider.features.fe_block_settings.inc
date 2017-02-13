<?php
/**
 * @file
 * cwrc_homepage_slider.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_homepage_slider_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['cwrc_homepage_slider-collecting'] = array(
    'cache' => -1,
    'css_class' => 'what-we-are-homepage',
    'custom' => 0,
    'delta' => 'collecting',
    'module' => 'cwrc_homepage_slider',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'main_suffix',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_homepage_slider-writing'] = array(
    'cache' => -1,
    'css_class' => 'what-we-are-homepage',
    'custom' => 0,
    'delta' => 'writing',
    'module' => 'cwrc_homepage_slider',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'main_suffix',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-homepage_slider-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'homepage_slider-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'project_banner',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-what_we_are_sharing-block'] = array(
    'cache' => -1,
    'css_class' => 'what-we-are-homepage',
    'custom' => 0,
    'delta' => 'what_we_are_sharing-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'main_suffix',
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
