<?php

/**
 * @file
 * Generate responses for the solr rest end point.
 */

/**
 * Responds to a SOLR GET request.
 *
 * @param array $parameters
 *   An associative array containing relevent data for this request.
 *   - path: The GET parameters from the URL path.
 *     - query: The SOLR query.
 *   - request: The request parameters passed onto SOLR.
 *     - See the SOLR documentation for more information.
 *
 * @return array
 *   The un-encoded response containing the generated SOLR results.
 */
function islandora_rest_solr_get_response(array $parameters) {
  $query = $parameters['path']['query'];
  $request = $parameters['request'];

  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);

  // Grab XACML restrictions if the module exists. Note because of how PHP
  // handles parsing of $_GET parameters with the same name, multiple query
  // parameters need to be logically chained together or passed in array form.
  if (module_exists('islandora_xacml_api')) {
    $obj = new stdClass();
    islandora_xacml_api_islandora_solr_query($obj);
    $xacml_fq = reset($obj->solrParams['fq']);
    if (isset($request['fq'])) {
      if (is_array($request['fq'])) {
        $request['fq'][] = $xacml_fq;
      }
      else {
        $request['fq'] .= "AND $xacml_fq";
      }
    }
    else {
      $request['fq'] = $xacml_fq;
    }
  }
  // Query is executed.
  try {
    $results = $solr->search($query, 0, isset($request['limit']) ? $request['limit'] : 10, $request, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message(check_plain(t('Error searching Solr index')) . ' ' . $e->getMessage(), 'error');
    return NULL;
  }
  return json_decode($results->getRawResponse(), TRUE);
}
