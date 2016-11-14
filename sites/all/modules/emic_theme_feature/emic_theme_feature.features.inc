<?php
/**
 * @file
 * emic_theme_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function emic_theme_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function emic_theme_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_views_default_views_alter().
 */
function emic_theme_feature_views_default_views_alter(&$data) {
  if (isset($data['frontpage'])) {
    $data['frontpage']->display['default']->display_options['fields'] = array(
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
    ); /* WAS: '' */
    $data['frontpage']->display['default']->display_options['row_plugin'] = 'fields'; /* WAS: 'node' */
    $data['frontpage']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['frontpage']->display['default']->display_options['row_options']);
    unset($data['frontpage']->display['feed']);
  }
}

/**
 * Implements hook_islandora_solr_fields_features_default_fields().
 */
function emic_theme_feature_islandora_solr_fields_features_default_fields() {
  return array(
  0 => array(
    'solr_field' => 'fgs_label_ss',
    'field_type' => 'sort_fields',
    'weight' => -10,
    'solr_field_settings' => array(
      'label' => 'Title',
      'permissions' => FALSE,
    ),
  ),
  1 => array(
    'solr_field' => 'fgs_label_ss',
    'field_type' => 'facet_fields',
    'weight' => -10,
    'solr_field_settings' => array(
      'label' => 'Title',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
    ),
  ),
  2 => array(
    'solr_field' => 'fgs_label_ss',
    'field_type' => 'result_fields',
    'weight' => -10,
    'solr_field_settings' => array(
      'label' => 'Title',
      'snippet' => NULL,
      'date_format' => '',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => TRUE,
      'link_to_search' => FALSE,
    ),
  ),
  3 => array(
    'solr_field' => 'mods_genre_ss',
    'field_type' => 'sort_fields',
    'weight' => -9,
    'solr_field_settings' => array(
      'label' => 'Genre',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
    ),
  ),
  4 => array(
    'solr_field' => 'mods_originInfo_edition_ms',
    'field_type' => 'result_fields',
    'weight' => -9,
    'solr_field_settings' => array(
      'label' => 'Edition',
      'snippet' => NULL,
      'date_format' => '',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => FALSE,
    ),
  ),
  5 => array(
    'solr_field' => 'mods_typeOfResource_ss',
    'field_type' => 'sort_fields',
    'weight' => -8,
    'solr_field_settings' => array(
      'label' => 'Type',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
    ),
  ),
  6 => array(
    'solr_field' => 'mods_name_personal_author_authority_marcrelator_namePart_ms',
    'field_type' => 'result_fields',
    'weight' => -8,
    'solr_field_settings' => array(
      'label' => 'Author',
      'snippet' => NULL,
      'date_format' => '',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => TRUE,
    ),
  ),
  7 => array(
    'solr_field' => 'mods_genre_ss',
    'field_type' => 'result_fields',
    'weight' => -7,
    'solr_field_settings' => array(
      'label' => 'Genre',
      'snippet' => NULL,
      'date_format' => '',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => TRUE,
    ),
  ),
  8 => array(
    'solr_field' => 'mods_originInfo_publisher_ms',
    'field_type' => 'result_fields',
    'weight' => -6,
    'solr_field_settings' => array(
      'label' => 'Publisher',
      'snippet' => NULL,
      'date_format' => '',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => TRUE,
    ),
  ),
  9 => array(
    'solr_field' => 'mods_originInfo_dateIssued_dt',
    'field_type' => 'result_fields',
    'weight' => -5,
    'solr_field_settings' => array(
      'label' => 'Date Issued',
      'snippet' => NULL,
      'date_format' => 'F j, Y',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => FALSE,
    ),
  ),
  10 => array(
    'solr_field' => 'mods_originInfo_dateCreated_dt',
    'field_type' => 'result_fields',
    'weight' => -4,
    'solr_field_settings' => array(
      'label' => 'Date Created',
      'snippet' => NULL,
      'date_format' => 'F j, Y',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => FALSE,
    ),
  ),
  11 => array(
    'solr_field' => 'mods_originInfo_copyrightDate_dt',
    'field_type' => 'result_fields',
    'weight' => -3,
    'solr_field_settings' => array(
      'label' => 'Copyright Date',
      'snippet' => NULL,
      'date_format' => 'F j, Y',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => FALSE,
    ),
  ),
  12 => array(
    'solr_field' => 'mods_subject_topic_ms',
    'field_type' => 'result_fields',
    'weight' => -2,
    'solr_field_settings' => array(
      'label' => 'Topic(s)',
      'snippet' => NULL,
      'date_format' => '',
      'maximum_length' => 0,
      'add_ellipsis' => FALSE,
      'wordsafe' => FALSE,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => TRUE,
    ),
  ),
  13 => array(
    'solr_field' => 'mods_abstract_ms',
    'field_type' => 'result_fields',
    'weight' => -1,
    'solr_field_settings' => array(
      'label' => 'Description',
      'snippet' => NULL,
      'date_format' => '',
      'maximum_length' => 256,
      'add_ellipsis' => 1,
      'wordsafe' => 1,
      'wordsafe_length' => 1,
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
      'link_to_object' => FALSE,
      'link_to_search' => FALSE,
    ),
  ),
  14 => array(
    'solr_field' => 'mods_genre_ss',
    'field_type' => 'facet_fields',
    'weight' => 2,
    'solr_field_settings' => array(
      'label' => 'Genre',
      'permissions' => array(
        1 => 1,
        2 => 2,
        3 => 3,
      ),
    ),
  ),
);
}
