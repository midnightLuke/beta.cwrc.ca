<?php
/**
 * @file
 * cwrc_projects.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cwrc_projects_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_cwrcshop-participants:http://beta.cwrc.ca/node/5#overlay-context=
  $menu_links['user-menu_cwrcshop-participants:http://beta.cwrc.ca/node/5#overlay-context='] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'http://beta.cwrc.ca/node/5#overlay-context=',
    'router_path' => '',
    'link_title' => 'CWRCShop Participants',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_cwrcshop-participants:http://beta.cwrc.ca/node/5#overlay-context=',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_messages:messages
  $menu_links['user-menu_messages:messages'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Messages',
    'options' => array(
      'identifier' => 'user-menu_messages:messages',
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_my-dashboard:user/my-dashboard
  $menu_links['user-menu_my-dashboard:user/my-dashboard'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/my-dashboard',
    'router_path' => 'user/my-dashboard',
    'link_title' => 'My dashboard',
    'options' => array(
      'identifier' => 'user-menu_my-dashboard:user/my-dashboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_my-profile:user
  $menu_links['user-menu_my-profile:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My profile',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_my-profile:user',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_my-research-space:user/my-research-space
  $menu_links['user-menu_my-research-space:user/my-research-space'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/my-research-space',
    'router_path' => 'user/my-research-space',
    'link_title' => 'My research space',
    'options' => array(
      'identifier' => 'user-menu_my-research-space:user/my-research-space',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CWRCShop Participants');
  t('Log out');
  t('Messages');
  t('My dashboard');
  t('My profile');
  t('My research space');
  t('User account');


  return $menu_links;
}
