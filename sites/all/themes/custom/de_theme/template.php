<?php

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function de_theme_preprocess_maintenance_page(&$vars) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // de_theme_preprocess_html($vars);
  // de_theme_preprocess_page($vars);

  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'de_theme';
  // Also, check $vars['db_is_active'] before doing any db queries.
}

/**
 * Implements hook_modernizr_load_alter().
 *
 * @return
 *   An array to be output as yepnope testObjects.
 */
/* -- Delete this line if you want to use this function
function de_theme_modernizr_load_alter(&$load) {

}

/**
 * Implements hook_preprocess_html()
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */

function de_theme_preprocess_html(&$vars) {
  $object = menu_get_object('islandora_object', 2);
  if (!$object) return;

  foreach ($object->models as $k => $model) {
    $vars['classes_array'][] = "page-islandora-object-" . drupal_clean_css_identifier($model);
  }

}

/**
 * Override or insert variables into the page template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_page(&$vars) {

}

/**
 * Override or insert variables into the region templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_region(&$vars) {

}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_block(&$vars) {

}
// */

/**
 * Override or insert variables into the entity template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_entity(&$vars) {

}
// */

/**
 * Override or insert variables into the node template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_node(&$vars) {
  $node = $vars['node'];
}
// */

/**
 * Override or insert variables into the field template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("field" in this case.)
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_field(&$vars, $hook) {

}
// */

/**
 * Override or insert variables into the comment template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_comment(&$vars) {
  $comment = $vars['comment'];
}
// */

/**
 * Override or insert variables into the views template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  // load tablesaw files for responsive tables on specific view displays
  //if ($variables['name'] == 'staff_directory' && $variables['display_id'] == 'page'){
    //drupal_add_css(drupal_get_path('theme', 'de_theme') . '/css/vendor/tablesaw/tablesaw.stackonly.css');
    //drupal_add_js(drupal_get_path('theme', 'de_theme') . '/bower_components/tablesaw/dist/stackonly/tablesaw.stackonly.js', array('scope' => 'header'));
  //}
}
// */

/**
 *
 * add required attributes and classes to specific tables for responsive tables with tablesaw
 *
 */
/* -- Delete this line if you want to use this function
function de_theme_preprocess_views_view_table(&$variables) {
  $view = $variables['view'];

  if ($view->name == 'staff_directory' && $view->current_display == 'page'){
    $variables['attributes_array']['data-mode'] = 'stack';
    $variables['classes_array'][] = 'tablesaw';
    $variables['classes_array'][] = 'tablesaw-stack';
  }
}
// */

/**
 * Override or insert css on the site.
 *
 * @param $css
 *   An array of all CSS items being requested on the page.
 */
/* -- Delete this line if you want to use this function
function de_theme_css_alter(&$css) {

}
// */

/**
 * Override or insert javascript on the site.
 *
 * @param $js
 *   An array of all JavaScript being presented on the page.
 */
/* -- Delete this line if you want to use this function
function de_theme_js_alter(&$js) {

}
// */

/**
 * Implements hook_preprocess_HOOK() for islandora datastreams block
 */
function de_theme_preprocess_islandora_blocks_datastreams(&$variables) {
  $obj = menu_get_object('islandora_object', 2);
  if ($obj != NULL && $obj->id) {
    $variables['bagit_link'] = l(t('Bag these datastreams for download'), "islandora/object/" . $obj->id . "/manage/bagit", array(
      'attributes' => array(
        'class' => 'bag-datastreams-link'
      ),
    ));
  }
}

/**
 * Implements hook_preprocess_HOOK() for block templates.
 */

function de_theme_preprocess_block(&$variables) {

  // Add additional template suggestions for compatibilty with Semantic Blocks module.
  $markup = check_plain($variables['block']->semantics);
  $module = check_plain($variables['block']->module);
  $delta = strtr($variables['block']->delta, '-', '_');
  $variables['theme_hook_suggestions'][] = 'block__' . $markup . '__' . $module . '__' . $delta;

  // Allow blocks to have no content by using the <none> convention.
  if ($variables['content'] == '<none>') {
    $variables['content'] = '';
  }
}
// */

function de_theme_links__locale_block(&$variables) {
  global $language;

  $langs = array();
  foreach ($variables['links'] as $lang => $info) {
    $name = $info['language']->native;
    $href = isset($info['href']) ? $info['href'] : '';
    $li_classes = array('list-item-language');
    if ($lang === $language->language) {
      $li_classes[] = 'active';
    }
    $link_classes = array('language-link');
    $options = array(
      'attributes' => array(
        'class' => $link_classes
      ),
      'language' => $info['language'],
      'html' => true
    );
    $link = l($name, $href, $options);

    if ($href) $langs[] = array('data' => $link, 'class' => $li_classes);
  }

  $attributes = array('class' => array('language-switcher', 'dropdown-menu'));
  $language_list = theme_item_list(array(
    'items' => $langs,
    'title' => '',
    'type' => 'ul',
    'attributes' => $attributes
  ));

  return "<li class='navbar-right nav-language-switcher'><a class='dropdown-toggle' href='#' role='button'>" . $language->native . "</a>$language_list</li>";
}

function de_theme_menu_local_tasks(&$variables) {
  $output = '';

  $actions = menu_local_actions();

  if (!empty($variables['primary']) || !empty($actions)) {
    $tabs = $variables['primary'];

    foreach ($actions as $idx => &$action) {
      $action['options'] = array(
        'attributes' => array(
          'class' => array(
            'action-tab',
          ),
        ),
      );
      $action['#theme'] = 'menu_local_task';
      $action['#link']['localized_options'] = array();

      if ($idx == count($actions) - 1) $action['options']['attributes']['class'][] = 'first-tab';

      $tabs[count($tabs) + $idx] = $action;
    }

    $tabs['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $tabs['#prefix'] .= '<ul class="tabs primary collapsed" id="local-tasks-menu">';
    $tabs['#suffix'] = '</ul>';

    $output .= drupal_render($tabs);
  }
  /*if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }*/

  return $output;
}

function de_theme_menu_local_task(&$variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  $submenuhtml = '';
  if (array_key_exists('submenu', $variables['element']) && count($variables['element']['submenu']) > 1) {
    $submenu = array(
      '#theme' => 'item_list',
      '#items' => $variables['element']['submenu'],
      '#type' => 'ul',
      '#attributes' => array(
        'class' => array(
          'tabs-submenu',
          'dropdown-menu',
        ),
      ),
    );
    $submenuhtml = drupal_render($submenu);
  }

  $options = $link['localized_options'] + array('attributes' => array('class' => array()));

  if (!empty($submenuhtml)) {
    $options['attributes']['class'][] = 'dropdown-toggle';
    $options['attributes']['class'][] = 'hover-menu';

    if (!empty($variables['element']['#active'])) {
      $options['attributes']['class'][] = 'active';
    }

    $options['attributes']['role'] = 'button';
  }
  $atag = l(t($link_text), $link['href'], $options);

  // Allow attributes to be put on the <li> tags
  $li_options = array();
  if (array_key_exists('options', $variables['element'])) $li_options += $variables['element']['options'];
  if (!empty($variables['element']['#active'])) $li_options['attributes']['class'][] = 'active';
  if (!array_key_exists('attributes', $li_options)) $li_options['attributes'] = array();

  return '<li' . drupal_attributes($li_options['attributes']) . '>' . $atag . $submenuhtml . "</li>\n";
}
