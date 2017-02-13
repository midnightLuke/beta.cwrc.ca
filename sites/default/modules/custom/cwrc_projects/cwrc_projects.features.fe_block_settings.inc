<?php
/**
 * @file
 * cwrc_projects.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_projects_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['cwrc_projects-project_context_logo'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_context_logo',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_projects',
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

  $export['cwrc_projects-project_group_join'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_group_join',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_projects',
    'node_types' => array(),
    'pages' => 'r4032login',
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

  $export['fieldblock-874a8e164b51a4d1eddd5b90118eb12f'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '874a8e164b51a4d1eddd5b90118eb12f',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'fieldblock',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'de_theme',
        'weight' => -41,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['fieldblock-cf5e71d2a2183a6a7cdcf61fc27bcf4a'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'cf5e71d2a2183a6a7cdcf61fc27bcf4a',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'fieldblock',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'project_banner',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-7'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 7,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'main_prefix_right',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-8'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 8,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'page',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-bf9c2240e79ce3dceb34cdc7101273a5'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'bf9c2240e79ce3dceb34cdc7101273a5',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'projects
projects/*',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Filters',
    'visibility' => 1,
  );

  $export['views-dd0cd778927866856aefa269a3cfc970'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dd0cd778927866856aefa269a3cfc970',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'project',
    ),
    'pages' => '',
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
    'visibility' => 0,
  );

  $export['views-project_featured_object-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_featured_object-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
    'title' => 'Featured',
    'visibility' => 0,
  );

  return $export;
}
