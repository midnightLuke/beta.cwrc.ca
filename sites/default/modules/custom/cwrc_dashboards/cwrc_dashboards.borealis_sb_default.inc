<?php
/**
 * @file
 * cwrc_dashboards.borealis_sb_default.inc
 */

/**
 * Implements hook_default_semantic_wrapper().
 */
function cwrc_dashboards_default_semantic_wrapper() {
  $export = array();

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'block_2';
  $semantic_wrapper->module = 'block';
  $semantic_wrapper->delta = '2';
  $semantic_wrapper->semantics = 'zip';
  $export['block_2'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'block_3';
  $semantic_wrapper->module = 'block';
  $semantic_wrapper->delta = '3';
  $semantic_wrapper->semantics = 'zip';
  $export['block_3'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'block_4';
  $semantic_wrapper->module = 'block';
  $semantic_wrapper->delta = '4';
  $semantic_wrapper->semantics = 'zip';
  $export['block_4'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_project_locked_objects';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'project_locked_objects';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_project_locked_objects'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_project_recently_edited';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'project_recently_edited';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_project_recently_edited'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_project_utilities';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'project_utilities';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_project_utilities'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_project_workflow_reports';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'project_workflow_reports';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_project_workflow_reports'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_user_assigned_to_me';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'user_assigned_to_me';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_user_assigned_to_me'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_user_bookmark_lists';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'user_bookmark_lists';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_user_bookmark_lists'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_user_privatemsg';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'user_privatemsg';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_user_privatemsg'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_user_recently_edited';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'user_recently_edited';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_user_recently_edited'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'cwrc_dashboards_user_workflow_reports';
  $semantic_wrapper->module = 'cwrc_dashboards';
  $semantic_wrapper->delta = 'user_workflow_reports';
  $semantic_wrapper->semantics = 'zip';
  $export['cwrc_dashboards_user_workflow_reports'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'islandora_saved_searches_saved_searches';
  $semantic_wrapper->module = 'islandora_saved_searches';
  $semantic_wrapper->delta = 'saved_searches';
  $semantic_wrapper->semantics = 'zip';
  $export['islandora_saved_searches_saved_searches'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'user_online';
  $semantic_wrapper->module = 'user';
  $semantic_wrapper->delta = 'online';
  $semantic_wrapper->semantics = 'zip';
  $export['user_online'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_my_projects-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'my_projects-block';
  $semantic_wrapper->semantics = 'zip';
  $export['views_my_projects-block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_pending_applications-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'pending_applications-block';
  $semantic_wrapper->semantics = 'zip';
  $export['views_pending_applications-block'] = $semantic_wrapper;

  $semantic_wrapper = new stdClass();
  $semantic_wrapper->disabled = FALSE; /* Edit this to true to make a default semantic_wrapper disabled initially */
  $semantic_wrapper->api_version = 1;
  $semantic_wrapper->uid = 'views_project_members-block';
  $semantic_wrapper->module = 'views';
  $semantic_wrapper->delta = 'project_members-block';
  $semantic_wrapper->semantics = 'zip';
  $export['views_project_members-block'] = $semantic_wrapper;

  return $export;
}
