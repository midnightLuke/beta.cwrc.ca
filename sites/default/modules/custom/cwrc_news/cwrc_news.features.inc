<?php
/**
 * @file
 * cwrc_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "borealis_sb" && $api == "borealis_sb_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwrc_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cwrc_news_node_info() {
  $items = array(
    'article' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Use <em>news</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
