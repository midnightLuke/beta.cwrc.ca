<?php

/**
 * @file
 * Emicdora modifications.
 */

/**
 * Get a collation.
 */
function collationtools_get_edited_collation($document_id) {
  module_load_include('inc', 'collation', 'includes/calliope');
  // Get a stored collation if one exists.
  $file_query = array(
    'emic_data.collation' => $document_id,
    'emic_data.version1' => $_GET['version1'],
    'emic_data.version2' => $_GET['version2'],
    'emic_data.diff_kind' => $_GET['diff_kind'],
  );
  $file = emicdora_calliope_get_collation_file($file_query);
  if ($file) {
    echo $file['emic_data']['contents'];
    drupal_exit();
  }
  // Fall back to creating a new collation.
  global $base_url;
  // Sanitized unicode Object replacement character.
  $br_token = json_decode('"\uFFFC"');
  $calliope_url = 'html/comparison';
  $path = "$base_url/$calliope_url/$document_id";
  $url = url($path, array('query' => array(
      '_dc' => $_GET['_dc'],
      'version1' => $_GET['version1'],
      'version2' => $_GET['version2'],
      'diff_kind' => $_GET['diff_kind'],
  )));
  $raw_contents = file_get_contents($url);
  // The MVD engine breaks br's where we don't want them broken.
  // Replacing with tokens makes it all work.
  $contents = str_replace($br_token, '<br />', $raw_contents);
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->loadHTML(mb_convert_encoding($contents, 'HTML-ENTITIES', 'UTF-8'));
  $bodies = $dom->getElementsByTagName('body');
  $body = $bodies->item(0);
  // Get rid of comment nodes.
  foreach ($dom->childNodes as $node) {
    // XXX: There can only be one comment per MVD containing unused CSS.
    if ($node->nodeType === XML_COMMENT_NODE) {
      $node->parentNode->removeChild($node);
    }
  }
  $all_nodes = $body->childNodes;
  foreach ($all_nodes as $node) {
    // Convert text nodes to spans.
    // XXX: Austese can return content with orphaned text nodes. As such, let's
    // wrap them in spans as they were meant to be.
    if ($node->nodeType === XML_TEXT_NODE) {
      $new_span = $dom->createElement('span', $node->nodeValue);
      $new_span->setAttribute('class', $_GET['diff_kind']);
      $parent = $node->parentNode;
      $parent->replaceChild($new_span, $node);
    }
  }
  // Save fixed content.
  $file_params = array(
    'collation' => $document_id,
    'version1' => $_GET['version1'],
    'version2' => $_GET['version2'],
    'diff_kind' => $_GET['diff_kind'],
    'emicdora_count' => 0,
  );
  $collation_dom = collationtools_add_ids($dom, $_GET['diff_kind']);
  $collation = $collation_dom->saveXML();
  emicdora_calliope_write_collation($file_params, $collation);
  echo $collation;
}

/**
 * Add IDs to the spans in a collation.
 *
 * @param DomDocument $dom
 *   A collation.
 * @param string $type
 *   'delete' or 'added'.
 *
 * @return DOMDocument
 *   XML now with IDs for easier access.
 */
function collationtools_add_ids(DOMDocument $dom, $type) {
  $spans = $dom->getElementsByTagName('span');
  $counter = 1;
  foreach ($spans as $span) {
    if ($span->getAttribute('id') == '') {
      $span->setAttribute('id', $type . $counter);
      $counter++;
    }
  }
  return $dom;
}
