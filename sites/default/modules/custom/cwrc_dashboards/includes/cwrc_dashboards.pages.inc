<?php

/**
 * @file
 * Define dashboard pages.
 */

/**
 * Display an empty page for a user dashboard.
 */
function cwrc_dashboards_user_dashboard($user) {
  return '';
}

/**
 * Display an empty page for a project dashboard.
 */
function cwrc_dashboards_project_dashboard($node) {
  drupal_set_title($node->title);
  return '';
}
