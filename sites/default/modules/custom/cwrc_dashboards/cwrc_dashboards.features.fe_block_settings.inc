<?php
/**
 * @file
 * cwrc_dashboards.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_dashboards_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-credit_visualization_placeholder'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'credit_visualization_placeholder',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'node/*/dashboard
user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 11,
      ),
    ),
    'title' => 'Credit Visualization',
    'visibility' => 1,
  );

  $export['block-disk_quota_placeholder'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'disk_quota_placeholder',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 10,
      ),
    ),
    'title' => 'Disk Quota',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-project_locked_objects'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_locked_objects',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-project_recently_edited'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_recently_edited',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-project_utilities'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_utilities',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -36,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-project_workflow_reports'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_workflow_reports',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -32,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-user_assigned_to_me'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_assigned_to_me',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -30,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-user_bookmark_lists'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_bookmark_lists',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-user_privatemsg'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_privatemsg',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-user_recently_edited'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_recently_edited',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['cwrc_dashboards-user_workflow_reports'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_workflow_reports',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'cwrc_dashboards',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -35,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['islandora_saved_searches-saved_searches'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'saved_searches',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'islandora_saved_searches',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Saved searches',
    'visibility' => 1,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'online',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'user',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-my_projects-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'my_projects-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'user/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-pending_applications-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'pending_applications-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -33,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-project_members-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project_members-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/*/dashboard',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -34,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
