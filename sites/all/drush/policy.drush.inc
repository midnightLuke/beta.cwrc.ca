<?php

/**
 * Implement of drush_hook_sql_sync_validate().
 *
 * Prevent catastrophe.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if ($destination != '@self') {
    return drush_set_error(dt('Per policy.drush.inc you may only sync to "@self".'));
  }
}
