<?php
/**
 * @file
 * emic_ctype_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function emic_ctype_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function emic_ctype_feature_node_info() {
  $items = array(
    'documentation_and_lab' => array(
      'name' => t('Documentation and Lab'),
      'base' => 'node_content',
      'description' => t('Content type for adding copy and files to Documentation and Lab sections'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'solr_query' => array(
      'name' => t('Solr Query'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
