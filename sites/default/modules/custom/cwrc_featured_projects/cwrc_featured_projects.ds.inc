<?php
/**
 * @file
 * cwrc_featured_projects.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwrc_featured_projects_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|featured_carousel';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'featured_carousel';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '-4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '-2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|project|featured_carousel'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwrc_featured_projects_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|featured_carousel';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'featured_carousel';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_logo',
        1 => 'title',
        2 => 'field_project_intro',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_logo' => 'ds_content',
      'title' => 'ds_content',
      'field_project_intro' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|featured_carousel'] = $ds_layout;

  return $export;
}
