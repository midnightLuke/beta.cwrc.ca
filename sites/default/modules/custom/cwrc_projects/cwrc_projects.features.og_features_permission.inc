<?php
/**
 * @file
 * cwrc_projects.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cwrc_projects_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:project:access project dashboard'
  $permissions['node:project:access project dashboard'] = array(
    'roles' => array(
      'member' => 'member',
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:add user'
  $permissions['node:project:add user'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:administer group'
  $permissions['node:project:administer group'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:approve and deny subscription'
  $permissions['node:project:approve and deny subscription'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:create page content'
  $permissions['node:project:create page content'] = array(
    'roles' => array(
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:delete any page content'
  $permissions['node:project:delete any page content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:delete own page content'
  $permissions['node:project:delete own page content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:manage members'
  $permissions['node:project:manage members'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:manage menu'
  $permissions['node:project:manage menu'] = array(
    'roles' => array(
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:manage permissions'
  $permissions['node:project:manage permissions'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:manage roles'
  $permissions['node:project:manage roles'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:subscribe'
  $permissions['node:project:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:project:subscribe without approval'
  $permissions['node:project:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:unsubscribe'
  $permissions['node:project:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
      'project contributor' => 'project contributor',
    ),
  );

  // Exported og permission: 'node:project:update any page content'
  $permissions['node:project:update any page content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:update group'
  $permissions['node:project:update group'] = array(
    'roles' => array(
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:update own page content'
  $permissions['node:project:update own page content'] = array(
    'roles' => array(
      'project contributor' => 'project contributor',
      'project editor' => 'project editor',
    ),
  );

  return $permissions;
}
