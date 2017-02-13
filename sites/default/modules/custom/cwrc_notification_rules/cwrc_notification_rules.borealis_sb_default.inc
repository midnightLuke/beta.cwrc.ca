<?php
/**
 * @file
 * cwrc_notification_rules.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_notification_rules_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_notification_rules_notification_icon';
  $semantic_wrapper->module = 'cwrc_notification_rules';
  $semantic_wrapper->delta = 'notification_icon';
  $semantic_wrapper->semantics = 'none';
  $export['cwrc_notification_rules_notification_icon'] = $semantic_wrapper;

  return $export;
}
