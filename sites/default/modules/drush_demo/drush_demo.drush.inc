<?php

/**
 * Implements hook_drush_command().
 */
function drush_demo_drush_command() {
  
  $items['drush-demo-command'] = array(
    'description' => 'Demonstrate how Drush commands work.',
    'aliases' => array('ddc'),
    'arguments' => array(
      'type' => 'The type of statement (error or success).',
    ),
    'options' => array(
      'repeat' => 'The number of statement repeats.',
    ),
    'examples' => array(
      'drush ddc error' => 'Prints the statement once with the error flag.',
      'drush ddc success --repeat=10' => 'Prints the statement 10 times with the success flag.',
    ),
  );
  
  return $items;
}

/**
 * Callback for the drush-demo-command command
 */
function drush_drush_demo_command($type = FALSE) {
  
  // Check for existence of argument
  if (!$type) {
    $options = array(
      'success' => dt('Success'),
      'error' => dt('Error'),
    );
    $type = drush_choice($options, dt('What kind of message you\'d like to print?'));
  }
  
  // Check for correct argument
  $correct_args = array('error', 'success');
  if (!in_array($type, $correct_args)) {
    return drush_set_error(dt('"@type" is not a valid statement type. Please choose between "success" and "error".', array('@type' => $type)));
  }
  
  // Option
  $repeat = drush_get_option('repeat', 1);
  if ($repeat > 1 && is_numeric($repeat)) {
    for ($i=0; $i < $repeat; $i++) { 
      demo_drush_print_statement($type);
    }
  }
  else {
    demo_drush_print_statement($type);
  }
  
}
