<?php

/**
 * @file
 * This implements most of the form /admin/config/contextual_help.
 */

/* Form handlers. */

/**
 * Page callback: Form constructor for Rules form for Contextual Help.
 *
 * @see contextual_help_rules_admin_form_validate()
 * @see contextual_help_rules_admin_form_submit()
 *
 * @ingroup forms
 */
function contextual_help_rules_admin_form($form) {
  $contextual_help_rules = contextual_help_rules();
  $form['#tree'] = TRUE;
  $form['#prefix'] = nl2br(variable_get("contextual_help_admin_prefix", ""));

  $max_weight = 0;
  foreach ($contextual_help_rules as $rid => $rvalue) {
    $form['chrules'][$rvalue->rule_id]['url_pattern'] = array(
      '#type' => 'textfield',
      '#default_value' => $rvalue->url_pattern,
      '#required' => TRUE,
    );
    $form['chrules'][$rvalue->rule_id]['link_destination'] = array(
      '#type' => 'textfield',
      '#default_value' => $rvalue->link_destination,
      '#required' => TRUE,
    );
    $form['chrules'][$rvalue->rule_id]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight for @title', array('@title' => $rid)),
      '#title_display' => 'invisible',
      '#default_value' => $rvalue->weight,
    );
    $max_weight = $rvalue->weight;
  }
  // Add New Rule Form.
  $form['new_chrule']['new']['url_pattern'] = array(
    '#type' => 'textfield',
    '#default_value' => '',
    '#title' => t('Enter a new URL pattern'),
  );
  $form['new_chrule']['new']['link_destination'] = array(
    '#type' => 'textfield',
    '#default_value' => '',
    '#title' => t('Enter a new destination'),
  );
  $form['new_chrule']['new']['weight'] = array(
    '#type' => 'weight',
    '#title_display' => 'invisible',
    '#default_value' => ($max_weight + 1),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );
  return $form;
}

/**
 * Form submission handler for theme_contextual_help_rules_admin_form().
 *
 * @see contextual_help_rules_admin_form_validate()
 */
function contextual_help_rules_admin_form_submit($form, &$form_state) {
  // Update Rules that have already been created.
  foreach ($form_state['values']['chrules'] as $id => $data) {
    if (is_array($data) && isset($data['weight'])) {
      // Only update if this is a form element with weight.
      db_update('contextual_help_rules')
        ->fields(array(
          'weight' => $data['weight'],
          'url_pattern' => $data['url_pattern'],
          'link_destination' => $data['link_destination'],
        ))
        ->condition('rule_id', $id)
        ->execute();
    }
  }
  // Save New Rules.
  $new_chrule = $form_state['values']['new_chrule']['new'];
  if (!empty($new_chrule['url_pattern'])) {
    $new_chrule = (object) $new_chrule;
    contextual_help_rule_save($new_chrule);
  }
  drupal_set_message(t('The Contextual Help Rules have been saved.'));
}

/**
 * Form validation handler for theme_contextual_help_rules_admin_form().
 *
 * @see contextual_help_rules_admin_form_submit()
 */
function contextual_help_rules_admin_form_validate($form, &$form_state) {
  _contextual_help_rules_admin_new_form_validate_add_new($form, $form_state);
}

/* Theme functions. */

/**
 * Returns HTML for the text format administration overview form.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: The form to be rendered.
 *
 * @ingroup themeable
 */
function theme_contextual_help_rules_admin_form($variables) {
  $form = $variables['form'];
  $rows = array();
  // Render our rules into a draggable table.
  foreach (element_children($form['chrules']) as $id) {
    $form['chrules'][$id]['weight']['#attributes']['class'] = array('text-contextual-help-order-weight');
    $rows[] = array(
      'data' => array(
        drupal_render($form['chrules'][$id]['rules']),
        drupal_render($form['chrules'][$id]['url_pattern']),
        drupal_render($form['chrules'][$id]['link_destination']),
        drupal_render($form['chrules'][$id]['weight']),
      ),
      'class' => array('draggable'),
    );
  }
  // Add one more row in our draggable table, where new rules can be entered.
  $rows[] = array(
    'data' => array(
      drupal_render($form['new_chrule']['new']['rules']),
      drupal_render($form['new_chrule']['new']['url_pattern']),
      drupal_render($form['new_chrule']['new']['link_destination']),
      drupal_render($form['new_chrule']['new']['weight']),
    ),
    'class' => array('draggable'),
  );
  // Build the markup.
  $header = array(t('Order'), t('Rules'), t('Link Destination'), t('Weight'));
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'id' => 'text-contextual-help-order',
    ),
  ));
  $output .= drupal_render_children($form);
  drupal_add_tabledrag('text-contextual-help-order', 'order', 'sibling', 'text-contextual-help-order-weight');
  return $output;
}

/* Helper functions. */

/**
 * Helper function to validate when new rules are entered.
 *
 * @see contextual_help_rules_admin_form_validate()
 */
function _contextual_help_rules_admin_new_form_validate_add_new($form, &$form_state) {
  $new_chrule = $form_state['values']['new_chrule']['new'];
  if (array_filter(array($new_chrule['url_pattern'], $new_chrule['link_destination']))) {
    if (!$new_chrule['url_pattern']) {
      form_set_error('new_chrule][new][url_pattern', t('There must be both a URL Pattern and a Link Destination'));
    }
    if (!$new_chrule['link_destination']) {
      form_set_error('new_chrule][new][link_destination', t('There must be both a URL Pattern and a Link Destination'));
    }
  }
}
