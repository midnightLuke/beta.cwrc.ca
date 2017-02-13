<?php
/**
 * @file
 * cwrc_projects.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function cwrc_projects_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: og-menu-single.
  $menus['og-menu-single'] = array(
    'menu_name' => 'og-menu-single',
    'title' => 'OG menu',
    'description' => 'Contains all the links for organic groups and their menus',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contains all the links for organic groups and their menus');
  t('OG menu');


  return $menus;
}
