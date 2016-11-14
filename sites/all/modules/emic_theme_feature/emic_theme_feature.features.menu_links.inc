<?php
/**
 * @file
 * emic_theme_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function emic_theme_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_co-op:co-op
  $menu_links['main-menu_co-op:co-op'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'co-op',
    'router_path' => 'co-op',
    'link_title' => 'CO-OP',
    'options' => array(
      'identifier' => 'main-menu_co-op:co-op',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_documentation:documentation
  $menu_links['main-menu_documentation:documentation'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'documentation',
    'router_path' => 'documentation',
    'link_title' => 'Documentation',
    'options' => array(
      'identifier' => 'main-menu_documentation:documentation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_editions:islandora/search/RELS_EXT_hasModel_uri_mt:"criticalEditionContainerCModel"
  $menu_links['main-menu_editions:islandora/search/RELS_EXT_hasModel_uri_mt:"criticalEditionContainerCModel"'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'islandora/search/RELS_EXT_hasModel_uri_mt:"criticalEditionContainerCModel"',
    'router_path' => 'islandora/search',
    'link_title' => 'Editions',
    'options' => array(
      'identifier' => 'main-menu_editions:islandora/search/RELS_EXT_hasModel_uri_mt:"criticalEditionContainerCModel"',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'query' => array(
        'sort' => 'fgs_label_ss asc',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_lab:lab
  $menu_links['main-menu_lab:lab'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'lab',
    'router_path' => 'lab',
    'link_title' => 'Lab',
    'options' => array(
      'identifier' => 'main-menu_lab:lab',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_login:user/login
  $menu_links['main-menu_login:user/login'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_login:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_members:members
  $menu_links['main-menu_members:members'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'members',
    'router_path' => 'members',
    'link_title' => 'Members',
    'options' => array(
      'identifier' => 'main-menu_members:members',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-workbench:workbench
  $menu_links['main-menu_my-workbench:workbench'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'workbench',
    'router_path' => 'workbench',
    'link_title' => 'My Workbench',
    'options' => array(
      'identifier' => 'main-menu_my-workbench:workbench',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CO-OP');
  t('Documentation');
  t('Editions');
  t('Home');
  t('Lab');
  t('Login');
  t('Members');
  t('My Workbench');


  return $menu_links;
}
