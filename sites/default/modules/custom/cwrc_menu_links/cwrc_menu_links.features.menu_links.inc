<?php
/**
 * @file
 * cwrc_menu_links.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cwrc_menu_links_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_collaboratory:islandora
  $menu_links['main-menu_collaboratory:islandora'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'islandora',
    'router_path' => 'islandora',
    'link_title' => 'Collaboratory',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_collaboratory:islandora',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_collaboratory:islandora
  $menu_links['menu-secondary-menu_collaboratory:islandora'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'islandora',
    'router_path' => 'islandora',
    'link_title' => 'Collaboratory',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-secondary-menu_collaboratory:islandora',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -4,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_dashboard:admin/dashboard
  $menu_links['menu-secondary-menu_dashboard:admin/dashboard'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-secondary-menu_dashboard:admin/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_help:admin/help
  $menu_links['menu-secondary-menu_help:admin/help'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'admin/help',
    'router_path' => 'admin/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-secondary-menu_help:admin/help',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -2,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_join:user/register
  $menu_links['menu-secondary-menu_join:user/register'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Join',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-secondary-menu_join:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-tertiary-menu_log-in--register:user/login
  $menu_links['menu-tertiary-menu_log-in--register:user/login'] = array(
    'menu_name' => 'menu-tertiary-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in / register',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tertiary-menu_log-in--register:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Collaboratory');
  t('Dashboard');
  t('Help');
  t('Join');
  t('Log in / register');


  return $menu_links;
}
