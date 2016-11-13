<?php
// $Id$

/**
 * Implements hook_drush_command().
 *
 * @return array
 */
function dita_drush_command() {
  $commands = array();

  $commands['dita-convert-ditamap'] = array(
    'description' => 'Converts a DITA map to a selected format',
    'arguments' => array(
      'ditamap' => 'DITA map XML file',
    ),
    'options' => array(
      '--type' => 'Set the output type. ' .
        'Choices: xhtml, htmlhelp, pdf2, eclipsehelp ' .
        'Default: pdf2',
      '--working-directory' => 'Path to the DITA OT distribution. Default is .',
      '--output-dir' => 'The output directory.',
      '--basedir' => 'Basedir',
    ),
  );

  $commands['dita-convert-scheduled'] = array(
    'description' => 'Convert the scheduled DITA maps',
    'options' => array(
      '--continue' => 'Continue the processing when an error occours.',
      '--max' => 'Maximum number of converts.',
      '--dry-run' => 'Print the generated commands.',
    ),
  );

  $commands['dita-list-output-types'] = array(
    'description' => 'List the supported output types',
  );

  return $commands;
}

/**
 * Implements the 'dita-list-output-types' command.
 */
function drush_dita_list_output_types() {
  foreach (dita_get_output_types() as $type => $data) {
    print "{$type}\n";
  }
}

/**
 * Implements the 'dita-convert-ditamap' command.
 *
 * @param string $ditamap The path for the .ditamap file.
 */
function drush_dita_convert_ditamap($ditamap) {
  dita_get_output_converter(
    drush_get_option('type', 'pdf2'),
    $ditamap,
    array(
    'dir' => drush_get_option('working-directory', '.'),
    'output_dir' => drush_get_option('output-dir', '.'),
    'basedir' => drush_get_option('basedir', '.'),
  ))->__invoke();
}

/**
 * Implements the 'dita-convert-scheduled' command.
 */
function drush_dita_convert_scheduled() {
  if (!module_exists('dita')) {
    return drush_set_error(DRUSH_FRAMEWORK_ERROR, dt('DITA module is not enabled.'));
  }

  $continue = (bool) drush_get_option('continue', FALSE);
  $max = (int) drush_get_option('max', 0);
  if ($max == 0) {
    $max = INF;
  }
  $dry_run = (bool) drush_get_option('dry-run', FALSE);

  $i = 0;

  $res = db_query('SELECT dtid, ditamap, prefix, type, output_dir, basedir
    FROM {dita_task}
    WHERE enabled = 1 AND status = 0
    ORDER BY priority, dtid');
  while ($i < $max && $row = db_fetch_object($res)) {
    $converter = dita_get_output_converter($row->type, $row->ditamap, array(
      'output_dir' => rtrim($row->output_dir, '/') . "/{$row->prefix}/",
      'basedir' => $row->basedir,
      'dir' => dita_get_working_directory($row->type),
    ));

    if ($dry_run) {
      $dir = getcwd();
      $converter->preInvoke();
      print $converter->getConvertCommand() . "\n\n";
      chdir($dir);
    }
    else {
      $result = $converter->__invoke();
      if (!$result && !$continue) {
        break;
      }

      db_query('UPDATE {dita_task} SET status = %d, enabled = 0 WHERE dtid = %d', array(
        ($converter->shell_status << 1) | 1,
        $row->dtid,
      ));
    }

    unset($converter);
    $i++;
  }
}

