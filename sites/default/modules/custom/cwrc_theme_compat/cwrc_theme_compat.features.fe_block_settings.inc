<?php
/**
 * @file
 * cwrc_theme_compat.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_theme_compat_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['blockify-blockify-logo'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'blockify-logo',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'blockify',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'masthead',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['cwrc_theme_compat-sponsors_homepage_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sponsors_homepage_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_theme_compat',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sponsor_region',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -2,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['cwrc_theme_compat-user_picture_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_picture_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_theme_compat',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'main_prefix',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -42,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-9'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 9,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['openid_connect-openid_connect_login'] = array(
    'cache' => 5,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'openid_connect_login',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'openid_connect',
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

  return $export;
}
