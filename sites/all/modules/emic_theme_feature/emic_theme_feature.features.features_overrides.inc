<?php
/**
 * @file
 * emic_theme_feature.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function emic_theme_feature_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.frontpage.display|default|display_options|fields"] = array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => '',
      'element_type' => 'h3',
      'element_label_colon' => FALSE,
      'link_to_node' => FALSE,
    ),
    'body' => array(
      'id' => 'body',
      'table' => 'field_data_body',
      'field' => 'body',
      'label' => '',
      'element_label_colon' => FALSE,
    ),
    'field_image' => array(
      'id' => 'field_image',
      'table' => 'field_data_field_image',
      'field' => 'field_image',
      'label' => '',
      'element_label_colon' => FALSE,
      'click_sort_column' => 'fid',
      'settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
    ),
  );
  $overrides["views_view.frontpage.display|default|display_options|row_options"]["DELETED"] = TRUE;
  $overrides["views_view.frontpage.display|default|display_options|row_plugin"] = 'fields';
  $overrides["views_view.frontpage.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.frontpage.display|feed"]["DELETED"] = TRUE;

 return $overrides;
}
