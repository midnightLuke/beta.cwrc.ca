<?php
/**
 * @file
 * cwrc_projects.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function cwrc_projects_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:project:project contributor'.
  $roles['node:project:project contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'project',
    'name' => 'project contributor',
  );

  // Exported OG Role: 'node:project:project editor'.
  $roles['node:project:project editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'project',
    'name' => 'project editor',
  );

  return $roles;
}
