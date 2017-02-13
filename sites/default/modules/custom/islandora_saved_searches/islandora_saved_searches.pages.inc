<?php

function islandora_saved_searches_user_listing($form, &$form_state, $account) {
  $searches = islandora_saved_searches_list_searches(null, null);

  // Build processing options.
  $form['enable'] = array(
    '#type' => 'button',
    '#value' => t('Enable selected'),
    '#executes_submit_callback' => true,
  );
  $form['disable'] = array(
    '#type' => 'button',
    '#value' => t('Disable selected'),
    '#executes_submit_callback' => true,
  );
  $form['delete'] = array(
    '#type' => 'button',
    '#value' => t('Delete selected'),
    '#executes_submit_callback' => true,
  );

  // Build search tableselect.
  $header = array(
    'name' => array('data' => t('Name')),
    'created' => array('data' => t('Created')),
    'enabled' => array('data' => t('Enabled')),
  );

  $options = array();
  foreach ($searches as $search) {
    $options[$search->id] = array(
      'name' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $search->name,
          '#href' => $search->path,
          '#options' => array('query' => $search->query),
        ),
      ),
      'created' => format_date($search->created),
      'enabled' => ((bool)$search->enabled) ? t('Yes') : t('No'),
    );
  }

  $form['searches'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No searches saved yet.'),
  );

  return $form;
}

function islandora_saved_searches_user_listing_validate($form, &$form_state) {
  $values = $form_state['values'];
  $selected = array_filter($values['searches']);

  // Nothing to really do...
  if (count($selected) == 0) {
    form_set_error('searches', t('You must select some searches to modify'));
  }
}

function islandora_saved_searches_user_listing_submit($form, &$form_state) {
  $values = $form_state['values'];
  $selected = array_filter($values['searches']);

  switch ($form_state['triggering_element']['#id']) {
    case 'edit-delete':
      $op = 'delete';
      break;
    case 'edit-enable':
      $op = 'enable';
      break;
    case 'edit-disable':
      $op = 'disable';
      break;
  }

  $batch = array(
    'operations' => array(),
    'finished' => 'islandora_saved_searches_batch_finished',
    'title' => t('Processing saved searches'),
    'init_message' => t('Batch is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('An error occured.'),
    'file' => drupal_get_path('module', 'islandora_saved_searches') . '/islandora_saved_searches.pages.inc',
  );

  foreach ($selected as $id) {
    $batch['operations'][] = array('islandora_saved_searches_batch_worker', array($id, $op));
  }
  batch_set($batch);
}

function islandora_saved_searches_batch_worker($id, $op) {
  switch ($op) {
    case 'delete':
      islandora_saved_searches_delete_search($id);
      break;
    case 'enable':
      islandora_saved_searches_enable_search($id);
      break;
    case 'disable':
      islandora_saved_searches_disable_search($id);
      break;
  }
}

function islandora_saved_searches_batch_finished($success, $results, $operations) {
  drupal_set_message(t('Completed processing items.'));
}
