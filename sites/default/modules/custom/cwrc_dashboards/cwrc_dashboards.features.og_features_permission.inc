<?php
/**
 * @file
 * cwrc_dashboards.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cwrc_dashboards_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:project:back-up project with islandora_bagit'
  $permissions['node:project:back-up project with islandora_bagit'] = array(
    'roles' => array(
      'member' => 'member',
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:edit workflow reports from workflow reports block'
  $permissions['node:project:edit workflow reports from workflow reports block'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:find and replace in project'
  $permissions['node:project:find and replace in project'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:remove workflow reports from workflow reports block'
  $permissions['node:project:remove workflow reports from workflow reports block'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:see pending applications block'
  $permissions['node:project:see pending applications block'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:see project_members block'
  $permissions['node:project:see project_members block'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  return $permissions;
}
