<?php
/**
 * @file
 * cwrc_homepage_slider.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_homepage_slider_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_homepage_slider_collecting';
  $semantic_wrapper->module = 'cwrc_homepage_slider';
  $semantic_wrapper->delta = 'collecting';
  $semantic_wrapper->semantics = 'div';
  $export['cwrc_homepage_slider_collecting'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_homepage_slider_writing';
  $semantic_wrapper->module = 'cwrc_homepage_slider';
  $semantic_wrapper->delta = 'writing';
  $semantic_wrapper->semantics = 'div';
  $export['cwrc_homepage_slider_writing'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_homepage_slider-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'homepage_slider-block';
  $semantic_wrapper->semantics = 'div';
  $export['views_homepage_slider-block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_what_we_are_sharing-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'what_we_are_sharing-block';
  $semantic_wrapper->semantics = 'div';
  $export['views_what_we_are_sharing-block'] = $semantic_wrapper;

  return $export;
}
