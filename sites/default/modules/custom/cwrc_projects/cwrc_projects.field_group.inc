<?php
/**
 * @file
 * cwrc_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwrc_projects_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|project|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced (all languages)',
    'weight' => '6',
    'children' => array(
      0 => 'field_object_lock_duration',
      1 => 'field_search_string',
      2 => 'field_top_level_collection',
      3 => 'group_group',
      4 => 'og_roles_permissions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Advanced (all languages)',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'Advanced settings for this project.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_advanced|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|node|project|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_acknowledgements',
      2 => 'field_project_intro',
      3 => 'title_field',
      4 => 'language',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_basic_information|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|project|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'field_copyrights',
      1 => 'field_email_address',
      2 => 'field_phone_number',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contact|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|project|full';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Connect with Us',
    'weight' => '12',
    'children' => array(
      0 => 'field_copyrights',
      1 => 'field_email_address',
      2 => 'field_phone_number',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Connect with Us',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_objects|node|project|form';
  $field_group->group_name = 'group_featured_objects';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured content',
    'weight' => '4',
    'children' => array(
      0 => 'field_featured_links',
      1 => 'field_featured_objects',
      2 => 'field_related_projects',
      3 => 'field_thumbnail_image',
      4 => 'field_project_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_featured_objects|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout|node|project|form';
  $field_group->group_name = 'group_layout';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Layout',
    'weight' => '5',
    'children' => array(
      0 => 'field_theme',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Layout',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-layout field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_layout|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|project|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Identity and Social Media',
    'weight' => '1',
    'children' => array(
      0 => 'field_banner_image',
      1 => 'field_logo',
      2 => 'field_social_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Identity and Social Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_media|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsors|node|project|form';
  $field_group->group_name = 'group_sponsors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '3',
    'children' => array(
      0 => 'field_sponsors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsors',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_sponsors|node|project|form'] = $field_group;

  return $export;
}
