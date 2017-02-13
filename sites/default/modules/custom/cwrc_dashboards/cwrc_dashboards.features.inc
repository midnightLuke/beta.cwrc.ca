<?php
/**
 * @file
 * cwrc_dashboards.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_dashboards_ctools_plugin_api($module = NULL, $api = NULL) {
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
function cwrc_dashboards_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
