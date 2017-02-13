<?php
/**
 * @file
 * cwrc_solr_site_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_solr_site_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
