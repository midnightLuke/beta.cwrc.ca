<?php
// $Id$

/**
 * Page callback for admin/content/dita.
 * Callback for drupal_get_form().
 */
function dita_admin_form() {
  $form = array();

  foreach (dita_get_output_converters() as $converter) {
    $varname = call_user_func(array($converter, 'getVariableName'));
    if (!empty($varname)) {
      $f[$varname] = array(
        '#title' => call_user_func(array($converter, 'getWorkingDirectoryName')),
        '#description' => t('Please provide an absolute path.'),
        '#type' => 'textfield',
        '#default_value' => variable_get($varname, ''),
      );
    }
  }

  $form['dita_output_dir'] = array(
    '#title' => t('Output directory'),
    '#type' => 'textfield',
    '#default_value' => variable_get('dita_output_dir', ''),
  );
  
  $form['dita_ot_dir'] = array(
    '#title' => t('OT directory'),
    '#type' => 'textfield',
    '#default_value' => variable_get('dita_ot_dir', ''),
  );

  $form['dita_web_dir'] = array(
    '#title' => t('Output dir in the basepath'),
    '#type' => 'textfield',
    '#default_value' => variable_get('dita_web_dir', ''),
  );

  $form['dita_basedir'] = array(
    '#title' => t('DITA basedir'),
    '#type' => 'textfield',
    '#default_value' => variable_get('dita_basedir', ''),
  );
  
  $form['dita_selected_dtd'] = array(
    '#type' => 'textfield',
    '#title' => t('DTD to use'),
    '#default_value' => variable_get('dita_selected_dtd', 'dtd/1.2/technicalContent'),
    '#description' => 'If you wish to use a DTD other than the default one, save your DTD directory in the dtd directory in the module directory root, and define the directory path here.',
  );
  
  // TODO: Get this information by parsing the DTD.
  $form['dita_selected_dtd_custom_topic_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom topic types'),
    '#default_value' => variable_get('dita_selected_dtd_custom_topic_types', ''),
    '#description' => 'Enter the machine-readable names of any custom topic types defined by your custom DTD here, as a comma-separated list.',
  );
  
  $form['dita_cron_number_of_files'] = array(
    '#type' => 'textfield',
    '#title' => t('Cron files per run'),
    '#default_value' => variable_get('dita_cron_number_of_files', 5),
    '#description' => 'How many uploaded DITA XML files uploaded in a zip archive should be run with one cron call? Try to select a number that can be processed in less than a minute.',
  );
  
  $form['dita_topic_author'] = array(
    '#type' => 'textfield',
    '#title' => t('Topic author'),
    '#default_value' => variable_get('dita_topic_author', ''),
    '#autocomplete_path' => 'admin/dita/dita_settings/autocomplete',
    '#description' => 'Author of uploaded DITA topics. If field is empty - will be used current user',
  );

  return system_settings_form($form);
}

/**
 * Validation callback for 'dita_admin_form'.
 */
function dita_admin_form_validate($form, &$form_state) {
  foreach (dita_get_output_converters() as $converter) {
    $varname = call_user_func(array($converter, 'getVariableName'));
    if (!empty($varname) && !call_user_func(array($converter, 'validateWorkingDirectory'), $form_state['values'][$varname])) {
      form_set_error($varname, t('Invalid @dirname', array(
        '@dirname' => call_user_func(array($converter, 'getWorkingDirectoryName')),
      )));
    }
  }
  foreach (array('dita_output_dir', 'dita_basedir') as $d) {
    if (!is_writable($form_state['values'][$d])) {
      form_set_error($d, t('Directory "' . $form_state['values'][$d] . '" is not writable.'));
    }
  }
}

function _dita_task_status_to_string($status) {
  switch ($status) {
    case 0:
      return t('In queue');
    case 1:
      return t('Completed successfully');
    default:
      return t('Failed: %error-code', array(
        '%error-code' => $status >> 1,
      ));
  }
}

function dita_admin_export_page($node = NULL) {
  module_load_include('inc', 'dita');

  $nid = (is_object($node) && isset($node->nid)) ? $node->nid : 0;

  $headers = array(
    t('Map name'),
    t('Reltable vocabulary'),
    t('Status'),
    t('Link'),
    '&nbsp;',
  );
  $rows = array();

  $res = pager_query('SELECT * FROM {dita_task} WHERE nid = %d OR 0 = %d ORDER BY dtid DESC',
    10, 0, NULL, $nid, $nid);
  while ($row = db_fetch_object($res)) {
    $node = node_load($row->nid);
    $handler = dita_get_output_handler($row->type, $row);
    $rows[] = array(
      $node->title,
      dita_taxonomy_vocabulary_name($row->vocabularies),
      _dita_task_status_to_string($row->status),
      $row->status == 1 ? l(t('Output'), $handler->getOutputDocumentPath()) : t('No output'),
      ($row->status > 1) ?
        l(t('Reschedule'), 'admin/content/dita/reschedule/' . $row->dtid) :
        '&nbsp;',
    );
  }

  return theme('table', $headers, $rows) . theme('pager');
}

/**
 * Callback for admin/content/dita/reschedule/%
 */
function dita_admin_reschedule_form($form_state, $dtid) {
  $form = array();

  $form['dtid'] = array(
    '#type' => 'value',
    '#value' => $dtid,
  );

  return confirm_form($form,
    t('Are you sure that you want to reschedule the task?'),
    'admin/content/dita/export',
    t('Only do it if you corrected the error'),
    t('Reschedule'), t('Cancel'));
}

function dita_admin_reschedule_form_submit($form, &$form_state) {
  db_query('UPDATE {dita_task} SET status = 0 WHERE dtid = %d',
    $form_state['values']['dtid']);

  drupal_set_message('Task is rescheduled.');

  drupal_goto('admin/content/dita/export');
}


/**
 * Autocomplete db query
 * 
 * @param string $string - input string
 */
function dita_settings_author_autocomplete($string) {
  // Query for users
  $result = db_select('users', 'u')
    ->fields('u', array('name'))
    ->condition('name', '%' . db_like($string) . '%', 'LIKE')
    ->orderBy('u.created', 'ASC')
    ->range(0, 10)
    ->execute();

  $matches = array();

  if(count($result)) {
    foreach ($result as $row) {
      $matches[$row->name] = check_plain($row->name);
    }
  }

  drupal_json_output($matches);
}