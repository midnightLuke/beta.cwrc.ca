<?php
/**
 * @file
 * cwrc_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "borealis_sb" && $api == "borealis_sb_default") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwrc_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function cwrc_projects_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favourite Projects".
  $flags['favourite_projects'] = array(
    'entity_type' => 'node',
    'title' => 'Favourite Projects',
    'global' => 0,
    'types' => array(
      0 => 'project',
    ),
    'flag_short' => '☆',
    'flag_long' => 'Add [node:title] to your favorites',
    'flag_message' => '',
    'unflag_short' => '★',
    'unflag_long' => 'Remove [node:title] from your favorites',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'featured_carousel' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'cwrc_projects',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function cwrc_projects_image_default_styles() {
  $styles = array();

  // Exported image style: featured_object_image.
  $styles['featured_object_image'] = array(
    'label' => 'Featured Object Image',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 245,
          'height' => 325,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_project_carousel_image.
  $styles['featured_project_carousel_image'] = array(
    'label' => 'Featured Project Carousel Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 266,
          'height' => 188,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: project_overview_grid_item.
  $styles['project_overview_grid_item'] = array(
    'label' => 'Project overview grid item',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 602,
          'height' => 444,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cwrc_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A <em>project</em> is your home for the various research materials you will collect and use on CWRC.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
