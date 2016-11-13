<?php
// $Id$

function ctools_ajax_command_addclass($selector, $class) {
  return array(
    'command' => 'addClass',
    'selector' => $selector,
    'data' => $class,
  );
}

function ctools_ajax_command_removeclass($selector, $class) {
  return array(
    'command' => 'removeClass',
    'selector' => $selector,
    'data' => $class,
  );
}
