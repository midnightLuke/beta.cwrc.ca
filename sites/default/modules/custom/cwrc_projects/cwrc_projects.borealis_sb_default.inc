<?php
/**
 * @file
 * cwrc_projects.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_projects_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_projects_project_context_logo';
  $semantic_wrapper->module = 'cwrc_projects';
  $semantic_wrapper->delta = 'project_context_logo';
  $semantic_wrapper->semantics = 'div';
  $export['cwrc_projects_project_context_logo'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'fieldblock_874a8e164b51a4d1eddd5b90118eb12f';
  $semantic_wrapper->module = 'fieldblock';
  $semantic_wrapper->delta = '874a8e164b51a4d1eddd5b90118eb12f';
  $semantic_wrapper->semantics = 'none';
  $export['fieldblock_874a8e164b51a4d1eddd5b90118eb12f'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_7';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '7';
  $semantic_wrapper->semantics = 'div';
  $export['menu_block_7'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_bf9c2240e79ce3dceb34cdc7101273a5';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'bf9c2240e79ce3dceb34cdc7101273a5';
  $semantic_wrapper->semantics = 'div';
  $export['views_bf9c2240e79ce3dceb34cdc7101273a5'] = $semantic_wrapper;

  return $export;
}
