<?php

/**
 * @file
 * Documentation for the cwrc_eap API.
 */

/**
 * JSON output callback to build an EAP page for a given URI.
 *
 * @param string $uri
 *    CWRC entity URI to base EAP upon.
 * @param bool $return
 *    If set to TRUE will return the results, rather than rendering them.
 *
 * @return string
 *   The JSON to build an EAP page.
 */
function cwrc_eap_xmldb_json($uri, $return = FALSE) {
  // This line is for local debugging of the EAPs, will use the test data from
  // the data folder.
  $debug = variable_get('cwrc_eap_debug', FALSE);
  if ($debug) {
    $json_results = file_get_contents(drupal_get_path('module', 'cwrc_eap') . '/data/test.json');
  }
  else {
    $json_results = "";
  }

  // Load endpoints and query the xml database.
  module_load_include('inc', 'islandora_cwrc_basexdb', 'includes/xmldb_endpoints');
  if (isset($uri) && empty($json_results)) {
    $keyValue = array("ENTITY_URI" => "$uri");
    $json_results = islandora_cwrc_exec_xquery(ISLANDORA_EAP_XQUERY_ID, $keyValue);
  }

  // Return the results as array.
  if ($return) {
    return json_decode($json_results, TRUE);
  }

  // Render the results for api usage.
  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  echo $json_results;
}
