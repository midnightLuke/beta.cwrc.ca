<?php
/**
 * @file
 * cwrc_theme_compat.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_theme_compat_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_theme_compat_sponsors_homepage_block';
  $semantic_wrapper->module = 'cwrc_theme_compat';
  $semantic_wrapper->delta = 'sponsors_homepage_block';
  $semantic_wrapper->semantics = 'div';
  $export['cwrc_theme_compat_sponsors_homepage_block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_theme_compat_user_picture_block';
  $semantic_wrapper->module = 'cwrc_theme_compat';
  $semantic_wrapper->delta = 'user_picture_block';
  $semantic_wrapper->semantics = 'none';
  $export['cwrc_theme_compat_user_picture_block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'locale_language';
  $semantic_wrapper->module = 'locale';
  $semantic_wrapper->delta = 'language';
  $semantic_wrapper->semantics = 'none';
  $export['locale_language'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_1';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '1';
  $semantic_wrapper->semantics = 'div';
  $export['menu_block_1'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_2';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '2';
  $semantic_wrapper->semantics = 'div';
  $export['menu_block_2'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_3';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '3';
  $semantic_wrapper->semantics = 'div';
  $export['menu_block_3'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_5';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '5';
  $semantic_wrapper->semantics = 'none';
  $export['menu_block_5'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_6';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '6';
  $semantic_wrapper->semantics = 'none';
  $export['menu_block_6'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'menu_block_9';
  $semantic_wrapper->module = 'menu_block';
  $semantic_wrapper->delta = '9';
  $semantic_wrapper->semantics = 'div';
  $export['menu_block_9'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'system_management';
  $semantic_wrapper->module = 'system';
  $semantic_wrapper->delta = 'management';
  $semantic_wrapper->semantics = 'div';
  $export['system_management'] = $semantic_wrapper;

  return $export;
}
