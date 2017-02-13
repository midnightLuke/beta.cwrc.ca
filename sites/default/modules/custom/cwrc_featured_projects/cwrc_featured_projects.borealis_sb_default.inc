<?php
/**
 * @file
 * cwrc_featured_projects.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_featured_projects_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_66553d96d3282749a55e20a1851a2cac';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = '66553d96d3282749a55e20a1851a2cac';
  $semantic_wrapper->semantics = 'div';
  $export['views_66553d96d3282749a55e20a1851a2cac'] = $semantic_wrapper;

  return $export;
}
