<?php
// $Id$
global $base_url;
global $dita_path;
$dita_path = $base_url . '/' . drupal_get_path('module', 'dita') . '/' . variable_get('dita_selected_dtd', 'dtd/1.2/technicalContent');

define('DITA_TOPIC_DOCTYPE', 'topic');
define('DITA_TOPIC_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER',
  '-//OASIS//DTD DITA Topic//EN');
define('DITA_TOPIC_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER',
   $dita_path . '/dtd/topic.dtd');
   
define('DITA_CONCEPT_DOCTYPE', 'concept');
define('DITA_CONCEPT_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER',
  '-//OASIS//DTD DITA Concept//EN');
define('DITA_CONCEPT_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER',
   $dita_path . '/dtd/concept.dtd');

define('DITA_TASK_DOCTYPE', 'task');
define('DITA_TASK_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER',
  '-//OASIS//DTD DITA Task//EN');
define('DITA_TASK_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER',
  $dita_path . '/dtd/task.dtd');

define('DITA_REFERENCE_DOCTYPE', 'reference');
define('DITA_REFERENCE_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER',
  '-//OASIS//DTD DITA Reference//EN');
define('DITA_REFERENCE_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER',
  $dita_path . '/dtd/reference.dtd');
//@Todo test reference while there were no samples for it in OT

define('DITA_TO_EMEDDED_XHTML_DIR', 'xslt_lib/');
define('DITA_TO_EMEDDED_XHTML_FILENAME', 'dita2xhtml_emb.xsl');

/**
 * Transforms a dita topic to xhtml
 *
 * @param string $xml valid xml string
 * @return string valid xml
 */
function dita_filter_transform($xml) {
  if (!$xml) {
    return FALSE;
  }
  module_load_include('export.inc', 'dita');

  $xslt_dir = drupal_get_path('module', 'dita') . '/' . DITA_TO_EMEDDED_XHTML_DIR;
  if (file_exists($xslt_dir . DITA_TO_EMEDDED_XHTML_FILENAME)) {
    $xml = dita_apply_xslt(dita_rewrite_dtd($xml), file_get_contents($xslt_dir .
            DITA_TO_EMEDDED_XHTML_FILENAME), TRUE, $xslt_dir);
  }
  return $xml;
}


/**
 * Sets the subset identifiers for a dita topic, to avoid problems with relative
 * paths to the dtds
 *
 * @param string $xml valid xml string
 * @param string if not FALSE, forces the doctype to be 'concept'/'reference'/'task'
 * @return string valid xml string
 */
function dita_rewrite_dtd($xml, $forced_doctype = FALSE) {
  global $dita_path;

  if (!$forced_doctype) {
    $doctype = dita_get_doctype($xml);
  }
  else {
    $doctype = $forced_doctype;
  }

  switch ($doctype) {
    case 'concept':
      $public_id = DITA_CONCEPT_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER;
      $system_id = DITA_CONCEPT_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER;
      break;
    case 'task':
      $public_id = DITA_TASK_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER;
      $system_id = DITA_TASK_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER;
      break;
    case 'reference':
      $public_id = DITA_REFERENCE_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER;
      $system_id = DITA_REFERENCE_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER;
      break;
    case 'topic':
      $public_id = DITA_TOPIC_EXTERNAL_SUBSET_PUBLIC_IDENTIFIER;
      $system_id = DITA_TOPIC_EXTERNAL_SUBSET_SYSTEM_IDENTIFIER;
      break;
    default:
      // TODO Make this work by reading the DTD
      // Handle doctypes defined in custom DTDs.
      $types = variable_get('dita_selected_dtd_custom_topic_types', '');
      $types = explode(',', $types);
      foreach($types as $type) {
        $type = trim($type);
        
        if($type == $doctype) {
          $public_id = dita_get_public_id_from_dtd($type);
          $system_id = $dita_path . '/dtd/' . $type . '.dtd';        
        }
      }
      
      if(!isset($public_id)) {
        drupal_set_message(t('Failed to recognize DOCTYPE "'.$doctype.'".'), 'error');
        return FALSE;      
      }
  }
  $xml_object = dita_create_xml_object($xml, $doctype, $public_id, $system_id);
  if (!$xml_object) {
    return FALSE;
  }

  return $xml_object->saveXML();
}
