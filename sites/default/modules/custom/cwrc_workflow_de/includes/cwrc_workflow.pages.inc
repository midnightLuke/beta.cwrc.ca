<?php

/**
 * @file
 * Pages defined by cwrc_workflow.
 */

/**
 * Page callbacK: Displays a list of workflow stamps for an object.
 *
 * @see cwrc_workflow_menu()
 */
function cwrc_workflow_object_history_page() {
  $stamps = cwrc_workflow_get_stamps();
  if ($stamps['total'] > 0) {
    return theme('cwrc_workflow_stamps', array('stamps' => $stamps['stamps'], 'object' => $stamps['object']));
  }
  else {
    return t('No workflow stamps found for this object.');
  }
}
