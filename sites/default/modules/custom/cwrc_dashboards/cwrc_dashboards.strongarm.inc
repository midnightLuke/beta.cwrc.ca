<?php
/**
 * @file
 * cwrc_dashboards.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cwrc_dashboards_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_block_max_list_count';
  $strongarm->value = '50';
  $export['user_block_max_list_count'] = $strongarm;

  return $export;
}
