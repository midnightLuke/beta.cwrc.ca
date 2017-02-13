<?php
/**
 * @file
 * cwrc_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cwrc_permissions_user_default_roles() {
  $roles = array();

  // Exported role: DHSI 2014.
  $roles['DHSI 2014'] = array(
    'name' => 'DHSI 2014',
    'weight' => 17,
  );

  // Exported role: Documentation.
  $roles['Documentation'] = array(
    'name' => 'Documentation',
    'weight' => 18,
  );

  // Exported role: Orlando User.
  $roles['Orlando User'] = array(
    'name' => 'Orlando User',
    'weight' => 3,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  return $roles;
}
