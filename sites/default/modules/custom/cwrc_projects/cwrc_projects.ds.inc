<?php
/**
 * @file
 * cwrc_projects.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwrc_projects_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'group_join_form' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'project_featured_object' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|project_overview_grid_item';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'project_overview_grid_item';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '-1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|project|project_overview_grid_item'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwrc_projects_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'group_join_form';
  $ds_field->label = 'Group Join Form';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'project|*';
  $ds_field->properties = array(
    'block' => 'cwrc_projects|project_group_join',
    'block_render' => '1',
  );
  $export['group_join_form'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'project_featured_object';
  $ds_field->label = 'Project featured object';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'project|*';
  $ds_field->properties = array(
    'block' => 'views|project_featured_object-block',
    'block_render' => '1',
  );
  $export['project_featured_object'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwrc_projects_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_logo',
        1 => 'field_banner_image',
      ),
      'left' => array(
        2 => 'field_project_intro',
        3 => 'body',
        4 => 'project_featured_object',
      ),
      'right' => array(
        5 => 'group_join_form',
        6 => 'field_featured_links',
        7 => 'field_acknowledgements',
        8 => 'field_related_projects',
        9 => 'field_social_links',
      ),
      'footer' => array(
        10 => 'field_sponsors',
        11 => 'group_contact',
      ),
    ),
    'fields' => array(
      'field_logo' => 'header',
      'field_banner_image' => 'header',
      'field_project_intro' => 'left',
      'body' => 'left',
      'project_featured_object' => 'left',
      'group_join_form' => 'right',
      'field_featured_links' => 'right',
      'field_acknowledgements' => 'right',
      'field_related_projects' => 'right',
      'field_social_links' => 'right',
      'field_sponsors' => 'footer',
      'group_contact' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|project_overview_grid_item';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'project_overview_grid_item';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_thumbnail_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_thumbnail_image' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|project|project_overview_grid_item'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cwrc_projects_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'project_overview_grid_item';
  $ds_view_mode->label = 'Project overview grid item';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['project_overview_grid_item'] = $ds_view_mode;

  return $export;
}
