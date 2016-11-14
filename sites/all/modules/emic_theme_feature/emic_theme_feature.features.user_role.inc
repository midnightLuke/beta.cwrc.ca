<?php
/**
 * @file
 * emic_theme_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function emic_theme_feature_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
