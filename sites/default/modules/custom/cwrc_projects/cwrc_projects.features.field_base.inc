<?php
/**
 * @file
 * cwrc_projects.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cwrc_projects_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_acknowledgements'
  $field_bases['field_acknowledgements'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_acknowledgements',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_banner_image'
  $field_bases['field_banner_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'image',
  );

  // Exported field_base: 'field_copyrights'
  $field_bases['field_copyrights'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_copyrights',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_description'
  $field_bases['field_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_email_address'
  $field_bases['field_email_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_email_address',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'email',
  );

  // Exported field_base: 'field_featured_links'
  $field_bases['field_featured_links'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_featured_links',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_featured_objects'
  $field_bases['field_featured_objects'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_featured_objects',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 1,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_full_name'
  $field_bases['field_full_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_full_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_link'
  $field_bases['field_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_object'
  $field_bases['field_object'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_object',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'pid' => array(
        0 => 'pid',
      ),
    ),
    'locked' => 0,
    'module' => 'islandora_object_field',
    'settings' => array(
      'content_models' => array(
        0 => 0,
        'cwrc:documentCModel' => 0,
        'cwrc:organization-entityCModel' => 0,
        'cwrc:person-entityCModel' => 0,
        'cwrc:place-entityCModel' => 0,
        'cwrc:schemaCModel' => 0,
        'cwrc:title-entityCModel' => 0,
        'ir:citationCModel' => 0,
        'ir:thesisCModel' => 0,
        'islandora:OACCModel' => 0,
        'islandora:binaryObjectCModel' => 0,
        'islandora:bookCModel' => 0,
        'islandora:collectionCModel' => 0,
        'islandora:compoundCModel' => 0,
        'islandora:criticalApparatusCModel' => 0,
        'islandora:criticalEditionCModel' => 0,
        'islandora:criticalEditionCModelPage' => 0,
        'islandora:criticalEditionContainerCModel' => 0,
        'islandora:criticaleditionschemaCModel' => 0,
        'islandora:entityCModel' => 0,
        'islandora:eventCModel' => 0,
        'islandora:markupEditorCModel' => 0,
        'islandora:markupeditorschemaCModel' => 0,
        'islandora:newspaperCModel' => 0,
        'islandora:newspaperIssueCModel' => 0,
        'islandora:newspaperPageCModel' => 0,
        'islandora:organizationCModel' => 0,
        'islandora:pageCModel' => 0,
        'islandora:personCModel' => 0,
        'islandora:placeCModel' => 0,
        'islandora:sp-audioCModel' => 0,
        'islandora:sp_basic_image' => 0,
        'islandora:sp_large_image_cmodel' => 0,
        'islandora:sp_pdf' => 0,
        'islandora:sp_videoCModel' => 0,
        'islandora:transcriptionCModel' => 0,
        'islandora:versionableObjectCModel' => 0,
      ),
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'islandora_object_field',
  );

  // Exported field_base: 'field_object_lock_duration'
  $field_bases['field_object_lock_duration'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_object_lock_duration',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_phone_number'
  $field_bases['field_phone_number'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_phone_number',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'telephone',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'telephone',
  );

  // Exported field_base: 'field_project_categories'
  $field_bases['field_project_categories'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_categories',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'project_categories',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_project_intro'
  $field_bases['field_project_intro'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_intro',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_related_projects'
  $field_bases['field_related_projects'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_related_projects',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'project' => 'project',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 1,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_research_space'
  $field_bases['field_research_space'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_research_space',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'pid' => array(
        0 => 'pid',
      ),
    ),
    'locked' => 0,
    'module' => 'islandora_object_field',
    'settings' => array(
      'content_models' => array(
        'cwrc:documentCModel' => 0,
        'cwrc:organization-entityCModel' => 0,
        'cwrc:person-entityCModel' => 0,
        'cwrc:place-entityCModel' => 0,
        'cwrc:schemaCModel' => 0,
        'cwrc:title-entityCModel' => 0,
        'ir:citationCModel' => 0,
        'ir:thesisCModel' => 0,
        'islandora:OACCModel' => 0,
        'islandora:bookCModel' => 0,
        'islandora:collectionCModel' => 'islandora:collectionCModel',
        'islandora:compoundCModel' => 0,
        'islandora:criticalApparatusCModel' => 0,
        'islandora:criticalEditionCModel' => 0,
        'islandora:criticalEditionCModelPage' => 0,
        'islandora:criticalEditionContainerCModel' => 0,
        'islandora:criticaleditionschemaCModel' => 0,
        'islandora:entityCModel' => 0,
        'islandora:eventCModel' => 0,
        'islandora:markupEditorCModel' => 0,
        'islandora:markupeditorschemaCModel' => 0,
        'islandora:organizationCModel' => 0,
        'islandora:pageCModel' => 0,
        'islandora:personCModel' => 0,
        'islandora:placeCModel' => 0,
        'islandora:sp-audioCModel' => 0,
        'islandora:sp_basic_image' => 0,
        'islandora:sp_large_image_cmodel' => 0,
        'islandora:sp_pdf' => 0,
        'islandora:sp_videoCModel' => 0,
        'islandora:transcriptionCModel' => 0,
        'islandora:versionableObjectCModel' => 0,
      ),
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'islandora_object_field',
  );

  // Exported field_base: 'field_search_string'
  $field_bases['field_search_string'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_search_string',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_social_links'
  $field_bases['field_social_links'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_social_links',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_sponsors'
  $field_bases['field_sponsors'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsors',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 1,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_text'
  $field_bases['field_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_text',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_theme'
  $field_bases['field_theme'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_theme',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'default' => 'Default',
        'bloodorange' => 'Blood orange',
        'burntsienna' => 'Burnt sienna',
        'darktan' => 'Dark tan',
        'desert' => 'Desert',
        'forest' => 'Forest',
        'marine' => 'Marine',
        'mediumblue' => 'Medium blue',
        'pomegranate' => 'Pomegranate',
        'sage' => 'Sage',
        'slatemagenta' => 'Slate magenta',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_thumbnail_image'
  $field_bases['field_thumbnail_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_thumbnail_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_title'
  $field_bases['field_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_title',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  // Exported field_base: 'field_top_level_collection'
  $field_bases['field_top_level_collection'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_top_level_collection',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'pid' => array(
        0 => 'pid',
      ),
    ),
    'locked' => 0,
    'module' => 'islandora_object_field',
    'settings' => array(
      'content_models' => array(
        0 => 0,
        'cwrc:documentCModel' => 0,
        'cwrc:organization-entityCModel' => 0,
        'cwrc:person-entityCModel' => 0,
        'cwrc:place-entityCModel' => 0,
        'cwrc:schemaCModel' => 0,
        'cwrc:title-entityCModel' => 0,
        'ir:citationCModel' => 0,
        'ir:thesisCModel' => 0,
        'islandora:OACCModel' => 0,
        'islandora:bookCModel' => 0,
        'islandora:collectionCModel' => 'islandora:collectionCModel',
        'islandora:compoundCModel' => 0,
        'islandora:criticalApparatusCModel' => 0,
        'islandora:criticalEditionCModel' => 0,
        'islandora:criticalEditionCModelPage' => 0,
        'islandora:criticalEditionContainerCModel' => 0,
        'islandora:criticaleditionschemaCModel' => 0,
        'islandora:entityCModel' => 0,
        'islandora:eventCModel' => 0,
        'islandora:markupEditorCModel' => 0,
        'islandora:markupeditorschemaCModel' => 0,
        'islandora:organizationCModel' => 0,
        'islandora:pageCModel' => 0,
        'islandora:personCModel' => 0,
        'islandora:placeCModel' => 0,
        'islandora:sp-audioCModel' => 0,
        'islandora:sp_basic_image' => 0,
        'islandora:sp_large_image_cmodel' => 0,
        'islandora:sp_pdf' => 0,
        'islandora:sp_videoCModel' => 0,
        'islandora:transcriptionCModel' => 0,
        'islandora:versionableObjectCModel' => 0,
      ),
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'islandora_object_field',
  );

  // Exported field_base: 'field_user_bio'
  $field_bases['field_user_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_bio',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_user_registration_reason'
  $field_bases['field_user_registration_reason'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_registration_reason',
    'field_permissions' => array(
      'type' => 1,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_user_website'
  $field_bases['field_user_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_website',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
