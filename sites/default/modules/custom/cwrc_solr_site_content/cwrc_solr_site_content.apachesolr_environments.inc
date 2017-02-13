<?php
/**
 * @file
 * cwrc_solr_site_content.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function cwrc_solr_site_content_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Drupal site content search';
  $environment->url = 'http://localhost:8080/solr/drupal_apachesolr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_direct_commit' => 1,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'event',
      2 => 'page',
      3 => 'project',
      4 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
