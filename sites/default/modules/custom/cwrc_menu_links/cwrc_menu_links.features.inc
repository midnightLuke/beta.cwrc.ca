<?php
/**
 * @file
 * cwrc_menu_links.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_menu_links_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "borealis_sb" && $api == "borealis_sb_default") {
    return array("version" => "1");
  }
}
