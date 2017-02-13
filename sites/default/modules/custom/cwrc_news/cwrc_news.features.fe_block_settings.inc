<?php
/**
 * @file
 * cwrc_news.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cwrc_news_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-News-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'News-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'news/*
events',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-News-block_1'] = array(
    'cache' => -1,
    'css_class' => 'homepage-news-event',
    'custom' => 0,
    'delta' => 'News-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -23,
      ),
    ),
    'title' => 'News',
    'visibility' => 1,
  );

  $export['views-News-block_2'] = array(
    'cache' => -1,
    'css_class' => 'homepage-news-event',
    'custom' => 0,
    'delta' => 'News-block_2',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'de_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'de_theme',
        'weight' => -22,
      ),
    ),
    'title' => 'News',
    'visibility' => 1,
  );

  return $export;
}
