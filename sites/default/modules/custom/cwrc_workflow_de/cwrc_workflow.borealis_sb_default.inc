<?php
/**
 * @file
 * cwrc_workflow.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_workflow_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_workflow_recent_stamps';
  $semantic_wrapper->module = 'cwrc_workflow';
  $semantic_wrapper->delta = 'recent_stamps';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_workflow_recent_stamps'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_workflow_stamp_form';
  $semantic_wrapper->module = 'cwrc_workflow';
  $semantic_wrapper->delta = 'stamp_form';
  $semantic_wrapper->semantics = 'div';
  $export['cwrc_workflow_stamp_form'] = $semantic_wrapper;

  return $export;
}
