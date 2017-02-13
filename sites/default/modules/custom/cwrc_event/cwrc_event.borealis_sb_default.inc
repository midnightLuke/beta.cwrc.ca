<?php
/**
 * @file
 * cwrc_event.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_event_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_events-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'events-block';
  $semantic_wrapper->semantics = 'div';
  $export['views_events-block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_events-block_1';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'events-block_1';
  $semantic_wrapper->semantics = 'div';
  $export['views_events-block_1'] = $semantic_wrapper;

  return $export;
}
