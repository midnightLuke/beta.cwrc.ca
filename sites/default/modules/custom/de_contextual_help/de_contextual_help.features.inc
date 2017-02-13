<?php

/**
 * @file
 * Features hook implementations.
 */

/**
 * Implements hook_features_export_options().
 */
function de_contextual_help_config_features_export_options() {
  // This hook will alert features of which specific items of this component may
  // be exported. For instances, in this case, we want to make available all the
  // existing items.  If there are no items to be exported, this component will
  // not be made available in the features export page.
  $field_types = array(
    'all_rules' => t('All Contextual Help rules.'),
  );
  return $field_types;
}

/**
 * Implements hook_features_export().
 */
function de_contextual_help_config_features_export($data, &$export, $module_name = '') {
  // This is a component hook, rather then a module hook, therefore this is the
  // callback from hook_features_api which relates to the specific component we
  // are looking to export. When a specific instance of the component we are
  // looking to export is selected, this will include the necessariy item, plus
  // any dependencies into our export array.
  $export['dependencies']['de_contextual_help'] = 'de_contextual_help';

  foreach ($data as $component) {
    $export['features']['de_contextual_help_config'][$component] = $component;
  }
}

/**
 * Implements hook_features_export_render().
 */
function de_contextual_help_config_features_export_render($module_name, $data, $export = NULL) {
  // This hook will be invoked in order to export Component hook. The hook
  // should be implemented using the name of the component, not the module, e.g.
  // [component]_features_export() rather than [module]_features_export().
  //
  // Render one or more component objects to code.
  $code = array();
  if (in_array('all_rules', $data)) {
    $code = contextual_help_rules();
  }

  $code = '  return ' . features_var_export($code) . ';';
  return array('de_contextual_help_config_features_default_settings' => $code);
}

/**
 * Implements hook_features_revert().
 */
function de_contextual_help_config_features_revert($module) {
  de_contextual_help_config_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function de_contextual_help_config_features_rebuild($module) {
  $items = module_invoke($module, 'de_contextual_help_config_features_default_settings');
  if (!empty($items)) {
    db_delete('contextual_help_rules')
      ->execute();
  }
  // Loop over the items we need to recreate.
  foreach ($items as $item) {
    $chrule = new stdClass();
    $chrule->url_pattern = $item['url_pattern'];
    $chrule->link_destination = $item['link_destination'];
    $chrule->weight = (int) $item['weight'];
    $chrule->status = (int) $item['status'];
    contextual_help_rule_save($chrule);
  }
}
