<?php
/**
 * @file
 * cwrc_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwrc_workflow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "borealis_sb" && $api == "borealis_sb_default") {
    return array("version" => "1");
  }
}
