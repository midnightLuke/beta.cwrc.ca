<?php
/**
 * @file
 * cwrc_dashboards.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function cwrc_dashboards_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Credit Visualization Placeholder';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'credit_visualization_placeholder';
  $fe_block_boxes->body = '<p>Feature coming soon!</p>
';

  $export['credit_visualization_placeholder'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Disk Quota Placeholder';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'disk_quota_placeholder';
  $fe_block_boxes->body = '<p>Feature coming soon!</p>
';

  $export['disk_quota_placeholder'] = $fe_block_boxes;

  return $export;
}
