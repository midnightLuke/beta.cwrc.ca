<?php
/**
 * @file
 * Page includes for the DITA integration module.
 */


/**
 * Upload form for DITA topic files.
 */
function dita_upload_form($form_state) {
  $f = array();

  $f['#attributes'] = array('enctype' => 'multipart/form-data');

  $f['dita_topic'] = array(
    '#type' => 'file',
    '#title' => t('DITA topic file'),
  );

  $f['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Upload'),
  );

  return $f;
}


/**
 * Upload handler function.
 *
 * Used by the single file upload, as well as the cron
 * job that takes care of uploaded zip archives of dita topics.
 */
function dita_handle_upload($user, $file_path, $form_state, $quiet = FALSE) {
  global $base_url;
  module_load_include('filter.inc', 'dita');
  $body = file_get_contents($file_path);

  // Use DTD definitions from the module's directory instead of the Internet.
  $body = dita_rewrite_dtd($body);
  if (!$body) {
    return FALSE;
  }

  $node = new stdClass();
  $node->type = 'dita';
  $node->status = 1;
  $node->promote = 1;
  $node->uid = $user->uid;
  $node->name = $user->name;
  $node->comment = variable_get("comment_dita", 0);

  // Load topic author from DITA settings. Otherwise will be used current user.
  $dita_topic_author = variable_get('dita_topic_author', '');
  if (!empty($dita_topic_author)) {
    $user_by_name = user_load_by_name($dita_topic_author);
    if ($user_by_name) {
      $node->uid = $user_by_name->uid;
      $node->name = $user_by_name->name;
    }
  }

  // Extract the document title.
  $sxml = new SimpleXMLElement($body);
  // The title element may have child elements, so get the whole offspring.
  $node->title = html_entity_decode(trim(strip_tags($sxml->title->asxml())));

  // Extract language.
  $attributes = $sxml->attributes('xml', 1);
  $lang = $attributes['lang'];
  $lang = strtolower(substr($lang, 0, strrpos($lang, "-")));
  $node->language = $lang;

  // Extract the id.
  $attributes = $sxml->attributes();
  $id = (string) $attributes['id'];
  $node->node_dita_original_id['und'][0]['value'] = $id;
  // Save DITA topic type.
  $v = taxonomy_vocabulary_machine_name_load('dita_topic_type');
  $tid = 0;
  if ($v) {
    $terms = taxonomy_get_term_by_name(ucfirst($sxml->getName()));
    foreach ($terms as $term) {
      if ($term->vid == $v->vid) {
        $tid = $term->tid;
      }
    }
  }
  else {
    drupal_set_message('DITA topic type vocabulary missing.', 'error');
  }
  if ($tid) {
    $node->node_dita_topic_type['und'][0]['tid'] = $tid;
  }

  // Check for duplicate imports.
  $efq = new EntityFieldQuery();
  $efq
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dita')
    ->propertyCondition('language', $lang, '=')
    ->fieldCondition('node_dita_original_id', 'value', $id, '=');
  $duplicate_nid = dita_check_for_duplicates($efq);

  // Check for the same document in a different language.
  // If found, save the translation node id "tnid" in the node
  // Note the negation operator in propertyCondition.
  $efq = new EntityFieldQuery();
  $efq
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dita')
    ->propertyCondition('language', $lang, '!=')
    ->fieldCondition('node_dita_original_id', 'value', $id, '=');
  $translation_node_nid = dita_check_for_duplicates($efq);
  if ($translation_node_nid) {
    $tnode = node_load($translation_node_nid);
    if ($tnode->tnid) {
      $node->tnid = $tnode->tnid;
    }
    else {
      $node->tnid = $tnode->nid;
      // No translations yet, so we need to add tnid to the found translated
      // node as well.
      //
      // This will incorrectly save a tnid reference to a node that is later
      // determined to _not_ be a translation after all. The value will get
      // fixed once hook_dita_node_import is called below.
      $original_tnode_tnid = $tnode->tnid;
      $tnode->tnid = $tnode->nid;
      node_save($tnode);
    }
  }

  // Running validator.
  $node_form = array();
  $node_form['body_field']['body']['#value'] = $body;
  if (!dita_validate($node, $node_form)) {
    return FALSE;
  }

  // This invokes a hook in DITA map import module. The hook adds the correct
  // taxonomy term to the new node object so that the node can be found in the
  // right place in the menu.
  $tid = module_invoke('ditamap_import', 'ditamap_attach_menu_item', $id, $form_state);
  if ($tid) {
    $node->field_node_dita_ditamap_term_ref['und'][0]['value'] = $tid;

    $term_obj = taxonomy_term_load($tid);
    $node->field_vocabulary_machine_name['und'][0]['value'] = $term_obj->vocabulary_machine_name;
  }

  // Allow custom modules to deal with case specific imports from the XML, for
  // example adding user defined taxonomy terms based on prolog values, or
  // doing further checks on whether the node is a duplicate or not.
  $attributes = module_invoke_all('dita_node_import', $body);
  foreach ($attributes as $key => $value) {
    $node->$key = $value;

    // This takes care of resetting the tnid value on nodes that were considered
    // translations by the main module, but were determined to not be
    // translations by a hook-implementing module.
    if ($key == 'tnid' && $value == 0 && isset($tnode)) {
      // TODO works for now(?), tested by uploading:
      // - en rev 17
      // - de rev 17
      // - en rev 16
      // .. but remember that uploading a 3rd language works different, so that
      // needs to be tested too.
      if (isset($original_tnode_tnid)) {
        $tnode->tnid = $original_tnode_tnid;
        node_save($tnode);
      }
    }
  }


  // Body handling moved here, since the node object needs the custom data in
  // order to be able to add custom URL segments to generated links.
  // Save original XML to the node.
  $node->node_dita_body_xml['und'][0]['value'] = $body;
  $node->node_dita_body_xml['und'][0]['format'] = 'full_html';
  // Parse XML to XHTML.
  $xhtml_body = dita_filter_transform($body);

  // Alter img element src attributes so that they point to the right place.
  $xhtml_body = dita_image_links($xhtml_body, $node);

  // Alter anchor element href attributes so that they point to the right place
  // NOTE: This causes a dependency on ditamap importer, it could be refactored
  // into a hook.
  if (isset($form_state['ditamap_importer_vid'])) {
    $ditamap_importer_vid = $form_state['ditamap_importer_vid'];
  }
  else {
    $ditamap_importer_vid = FALSE;
  }
  $xhtml_body = dita_anchor_links($xhtml_body, $node);

  // Save XHTML in node's actual body.
  $node->body['und'][0]['value'] = $xhtml_body;
  $node->body['und'][0]['format'] = 'full_html';


  if (isset($node->dita_import_duplicate)) {
    $duplicate_nid = $node->dita_import_duplicate;
  }

  if ($duplicate_nid) {
    $temp_node = node_load($duplicate_nid);
    foreach ($node as $attr => $value) {
      $temp_node->$attr = $value;
    }
    $node = $temp_node;
  }

  $node = node_submit($node);
  $node->dita_import_duplicate = NULL;

  node_save($node);
  if (!$duplicate_nid) {
    // Creating new node.
    if ($node->tnid) {
      // TODO allow translations.
      $message = 'Created translated <a href="' . $base_url . '/node/' . $node->nid . '/edit">DITA node ' . $node->nid . '</a> from XML document "' . $id . '".';
      if (!$quiet) {
        drupal_set_message($message);
      }
      watchdog('DITA', $message, NULL, WATCHDOG_INFO);
    }
    else {
      // TODO allow translations.
      $message = 'Created <a href="' . $base_url . '/node/' . $node->nid . '/edit">DITA node ' . $node->nid . '</a> from XML document "' . $id . '".';
      if (!$quiet) {
        drupal_set_message($message);
      }
      watchdog('DITA', $message, NULL, WATCHDOG_INFO);
    }

  }
  else {
    // Update existing node.
    // TODO allow translations.
    $message = 'Updated <a href="' . $base_url . '/node/' . $node->nid . '/edit">DITA node ' . $node->nid . '</a> from XML document "' . $id . '"';
    if (!$quiet) {
      drupal_set_message($message, 'warning');
    }
    watchdog('DITA', $message, NULL, WATCHDOG_WARNING);
  }
}


/**
 * Upload handler for DITA topic files.
 */
function dita_upload_form_submit($form, &$form_state) {
  global $user;

  $validators = array(
    'file_validate_extensions' => array('xml', 'dita'),
  );

  $file = file_save_upload('dita_topic', $validators, file_default_scheme() . '://', FILE_EXISTS_REPLACE);

  if (!$file) {
    drupal_set_message(t('File upload failed'), 'error');
    return;
  }

  $absolute_path = drupal_realpath(file_default_scheme() . '://') . '/' . $file->filename;

  dita_handle_upload($user, $absolute_path, $form_state);
}


/**
 * DITA archive processor.
 *
 * Called by cron, this function processes a DITA XML file that was uploaded in
 * a zip archive.
 */
function dita_process_dita_archive_file() {
  global $user;

  if (!$user->uid) {
    $user = user_load(1);
  }

  $path = file_stream_wrapper_get_instance_by_uri('private://')->getDirectoryPath() . '/dita_archive_upload';

  $files = scandir($path);

  // Select the first directory, not counting "." and "..". This will be the
  // earliest uploaded archive, since they're named with timestamps.
  if (!isset($files[2]) || !$files[2]) {
    // Prevent the system from deleting its root storage directory.
    return FALSE;
  }
  $dir = $files[2];

  $dir_path = $path . '/' . $dir;
  // The next segment is the machine name of the vocabulary.
  $subdir = scandir($dir_path);
  if (count($subdir) == 3 && substr($subdir[2], 0, 1) != '.') {

    $vocabulary = $subdir[2];
    $dir_path .= '/' . $vocabulary;
  }
  else {

    watchdog('DITA', 'Unexpected error in DITA upload archive processing: Directory structure mismatch.', NULL, WATCHDOG_ERROR);
  }

  // Get the actual contents of the archive.
  $subdir = scandir($dir_path);

  // Get rid of a silly hidden directory.
  $subdir = array_flip($subdir);
  unset($subdir['__MACOSX']);
  $subdir = array_flip($subdir);

  // Handle both cases: zip contains files, or zip contains a directory with the
  // files.
  if (count($subdir) == 3 && substr($subdir[2], 0, 1) != '.' && is_dir($dir_path . '/' . $subdir[2])) {
    $extra_dir = $dir_path;
    $dir_path .= '/' . $subdir[2];
  }
  // $dir_path now contains the full path to the XML file directory.
  $files = scandir($dir_path);
  // Drop . and ..
  if (isset($files[2])) {
    $file_name = $files[2];
    $v = taxonomy_vocabulary_machine_name_load($vocabulary);
    dita_handle_upload($user, $dir_path . '/' . $file_name, array('ditamap_importer_vid' => $v->vid), TRUE);
    unlink($dir_path . '/' . $file_name);
    return TRUE;
  }
  else {
    // The directory is empty, let's get rid of it.
    // Either "Analysis" or "ditamap_import_def".
    rmdir($dir_path);

    if (isset($extra_dir)) {
      // "ditamap_import_def", if there was no dir in the archive.
      rmdir($extra_dir);
    }

    // The dir named with a timestamp.
    rmdir($path . '/' . $dir);

    return FALSE;
  }
}


/**
 * Upload form for zip archives of DITA topic files.
 */
function dita_upload_archive_form($form_state) {
  $f = array();

  $f['#attributes'] = array('enctype' => 'multipart/form-data');

  $f['file'] = array(
    '#type' => 'file',
    '#title' => t('DITA zip archive'),
    '#description' => t('The archive must contain xml files only, or a single directory containing all the xml files. No nested directories!'),
  );

  $f['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Upload'),
  );

  return $f;
}


/**
 * Validation of file extension and "Final folder name" correctness.
 */
function dita_upload_archive_form_validate($form, &$form_state) {
  $validators = array(
    'file_validate_extensions' => array('zip'),
  );
  // Upload file to  sites/default/files (by default).
  if (($file = file_save_upload('file', $validators, 'private://'))) {
    // Send information about file to fn tekla_dita_graphics_submit().
    $form_state['values']['file'] = $file;
  }
  else {
    form_set_error('file', 'Error uploading file.');
  }
}


/**
 * Submit handler for DITA archive uploader.
 */
function dita_upload_archive_form_submit($form, &$form_state) {
  global $user;

  $file = $form_state['values']['file'];
  // Saving new status.
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);
  $taxonomy = taxonomy_vocabulary_load($form_state['values']['vocabulary']);
  // Save the "root" of the uploaded archive to a separate variable, so we can
  // easily delete the whole thing in case of an error in the upload process.
  $upload_path_part = file_stream_wrapper_get_instance_by_uri('private://')->getDirectoryPath() . "/" . 'dita_archive_upload/' . time() . '_' . $user->uid;
  $upload_path = $upload_path_part . '/' . $taxonomy->machine_name;
  $zip = new ZipArchive();
  $filepath = $zip->open(drupal_realpath($file->uri));
  if ($filepath === TRUE) {
    $dest_dir = $upload_path;
    file_prepare_directory($dest_dir);
    $zip->extractTo($dest_dir, $context = NULL);
    $zip->close();
    // Delete uploaded zip and DB record.
    file_delete($file, $force = FALSE);

    // Check the contents of the zip archive; there may not be nested
    // directories.
    $delete_archive = FALSE;
    $dir = scandir($dest_dir);

    $has_files = array();
    $has_directories = array();
    $has_other = array();
    foreach ($dir as $entry) {
      // Ignore current and parent directory.
      if ($entry != '.' && $entry != '..') {
        if (is_dir($dest_dir . '/' . $entry)) {
          $has_directories[] = $entry;
        }
        elseif (is_file($dest_dir . '/' . $entry)) {
          $has_files[] = $entry;
          $extension = substr($entry, strrpos($entry, '.'));
          if ($extension != '.xml' && $extension != '.dita') {
            drupal_set_message('File named "' . $entry . '" has an illegal extension. Allowed extensions are "dita" and "xml".', 'error');
            $delete_archive = TRUE;
          }
        }
        else {
          $has_other[] = $entry;
        }
      }
    }

    if (!$delete_archive) {
      if (count($has_other)) {
        // There's something weird in the archive. Probably a symlink.
        drupal_set_message('The uploaded archive contained something unexpected (symlinks?) named ' . implode(', ', $has_other) . '.', 'error');
        $delete_archive = TRUE;
      }
      else {
        if (count($has_directories) && count($has_files)) {
          // Has both types. Not good.
          drupal_set_message('The uploaded archive contained mixed files and directories. It may contain a single directory, or files only.', 'error');
          $delete_archive = TRUE;
        }
        elseif (!count($has_files) && count($has_directories)) {
          // Has directories only.
          if (count($has_directories) > 1) {
            drupal_set_message('The uploaded archive contained more than one directory (' . implode(', ', $has_directories) . '). It may contain a single directory, or files only.', 'error');
            $delete_archive = TRUE;
          }
          elseif (count($has_directories) == 1) {
            // Ok, single directory only. Save the path for the check files.
            $subdir = reset($has_directories);
            $dest_dir = $dest_dir . '/' . $subdir;
            $check_files = scandir($dest_dir);
            foreach ($check_files as $check_file) {
              if ($check_file != '.' && $check_file != '..') {
                if (is_dir($dest_dir . '/' . $check_file)) {
                  drupal_set_message('The uploaded archive contained nested directory named "' . $check_file . '".', 'error');
                  $delete_archive = TRUE;
                }
                else {
                  $extension = substr($check_file, strrpos($check_file, '.'));
                  if ($extension != '.xml' && $extension != '.dita') {
                    drupal_set_message('File named "' . $check_file . '" in "' . $subdir . '" has an illegal extension. Allowed extensions are "dita" and "xml".', 'error');
                    $delete_archive = TRUE;
                  }
                }
              }
            }
          }
        }
        else {
          // Ok, has files only.
        }
      }
    }

    if ($delete_archive) {
      dita_rrmdir($upload_path_part);

      drupal_set_message('The uploaded archive has been deleted due to the errors noted above. Please fix the archive, and re-upload.', 'error');
    }
    else {
      drupal_set_message('File(s) was uploaded and extracted successfully.');
    }
  }
  else {
    // Delete uploaded zip and DB record.
    file_delete($file, $force = FALSE);
    drupal_set_message(t('File was not extracted. Please check your PHP settings'), 'warning');
  }
}

/**
 * Status display for uploaded DITA archives being processed.
 *
 * @param Array $form_state
 *   A Drupal form_state array
 */
function dita_upload_archive_status_form($form_state) {
  $f = array();

  $path = file_stream_wrapper_get_instance_by_uri('private://')->getDirectoryPath() . '/dita_archive_upload';
  $files = scandir($path);

  // Drop hidden files.
  foreach ($files as $key => $file) {
    if (substr($file, 0, 1) == '.') {
      unset($files[$key]);
    }
  }
  // Get all the data we need.
  $data = array();
  $file_data = array();
  foreach ($files as $file) {
    $dir_path = $path . '/' . $file;

    $subdir = scandir($dir_path);

    // The next segment is the machine name of the vocabulary.
    if (count($subdir) == 3 && substr($subdir[2], 0, 1) != '.') {
      $vocabulary = $subdir[2];
      $dir_path .= '/' . $vocabulary;
    }
    else {
      drupal_set_message('Error processing archive. File/directory count mismatch at ' . $dir_path . ' . This could be caused by hidden directories like ".DS_Store"', 'error');
      return FALSE;
    }

    // Get the actual contents of the archive:
    $subdir = scandir($dir_path);

    // Get rid of a silly hidden directory.
    $subdir = array_flip($subdir);
    unset($subdir['__MACOSX']);
    $subdir = array_flip($subdir);

    // Handle both cases: zip contains files, or zip contains a directory with
    // the files.
    if (count($subdir) == 3 && substr($subdir[2], 0, 1) != '.') {
      $dir_path .= '/' . $subdir[2];
    }

    // Count files.
    $xml_files = scandir($dir_path);
    foreach ($xml_files as $key => $xml_file) {
      if (substr($xml_file, 0, 1) == '.') {
        unset($xml_files[$key]);
      }
    }
    $file_count = count($xml_files);

    // Parse data.
    $temp = explode('_', $file);
    $user = user_load($temp[1]);
    $v = taxonomy_vocabulary_machine_name_load($vocabulary);
    $data[] = array(
      'upload_time' => date('Y-m-d H:i:s', $temp[0]),
      'upload_user' => $user->name,
      'vocabulary' => $v->name,
      'file_count' => $file_count,
      'file_data' => $xml_files,
    );
  }

  // Generate report table.
  $header = array(
    array('data' => 'Upload time', 'field' => 'upload_time', 'sort' => 'asc'),
    array('data' => 'Uploader', 'field' => 'uploader'),
    array('data' => 'Vocabulary to be uploaded to', 'field' => 'vocabulary'),
    array('data' => 'Files remaining', 'field' => 'files_remaining'),
  );

  $rows = array();
  foreach ($data as $row) {
    $rows[] = array(
      'data' => array(
        $row['upload_time'],
        $row['upload_user'],
        $row['vocabulary'],
        $row['file_count'],
      ),
    );
  }

  $html = theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows,
      'sticky' => TRUE,
      'empty' => 'All uploaded archives finished processing',
    )
  );

  // Create quick debugging table.
  $markup = '<table>';
  foreach ($data as $row) {
    $markup .= "<tr>";
    foreach ($row as $key => $cell) {
      $markup .= "<td>";
      if ($key != 'file_data') {
        $markup .= $cell;
      }
      $markup .= "</td>";
    }
    $markup .= "</tr>\n";
  }
  $markup .= '</table>';

  $f['table'] = array(
    '#type' => 'markup',
    '#markup' => $html,
  );

  return $f;
}
