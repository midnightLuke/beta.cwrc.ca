<?php
/**
 * @file
 * cwrc_theme_compat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_theme_compat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "borealis_sb" && $api == "borealis_sb_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cwrc_theme_compat_image_default_styles() {
  $styles = array();

  // Exported image style: user_header_picture.
  $styles['user_header_picture'] = array(
    'label' => 'User Header Picture',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 54,
          'height' => 54,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
