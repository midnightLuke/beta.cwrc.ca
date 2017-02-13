<?php

/**
 * @file
 * Menu callbacks and hooks that are part of the CWRC-Writer Entity API.
 */

/**
 * Conducts a search for the given $type.
 *
 * As of this version of CWRC-Writer v0.8 Searches are formatted for SOLR, and
 * results are expected to be JSON encoded SOLR results.
 *
 * Although from reading the cD.js code it would seem we only need to provide
 * 'PID', and 'object_label' for it to work.
 *
 * So each responded to this
 *
 * @param string $type
 *   A string representing the type of entity being searched for.
 */
function islandora_cwrc_writer_cwrc_api_entity_search($type) {
  $query_params = drupal_get_query_parameters();
  $query = $query_params['query'];
  $limit = $query_params['limit'];
  $page = $query_params['page'];
  $objects = islandora_cwrc_writer_entity_search($query, $type, $page, $limit);
  // Correct for any weird CWRC-Writer expectations, this is likely to change in
  // the near future.
  foreach ($objects as &$object) {
    $object = array(
      'PID' => $object['pid'],
      'object_label' => $object['label'],
    );
  }
  drupal_json_output(array(
    'response' => array(
      'objects' => $objects,
    ),
  ));
}

/**
 * Search for an entity.
 *
 * @param string $query
 *   Search Query.
 * @param string $type
 *   The type of entity to search for.
 * @param int $page
 *   The offset in the search results to return.
 * @param int $limit
 *   The number of results to limit the results to.
 *
 * @return array
 *   The results of the search.
 */
function islandora_cwrc_writer_entity_search($query, $type, $page, $limit) {
  $valid_types = islandora_cwrc_writer_valid_entity_types();
  $content_model = $valid_types[$type];
  if (!module_exists('islandora_solr') || !isset($valid_types[$type])) {
    return array();
  }
  $model_field = variable_get('islandora_solr_content_model_field', 'RELS_EXT_hasModel_uri_ms');
  $params = array(
    'fl' => 'PID, fgs_label_s',
    'defType' => 'dismax',
    'fq' => $model_field . ':info\\:fedora/' . str_replace(':', '\\:', $content_model),
  );
  $url = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  // Use Solr directly rather than the wrapper as it's easier to return JSON,
  // and entities are likely to be filtered out by the default config.
  $solr = new Apache_Solr_Service($url['host'], $url['port'], $url['path'] . '/');
  $solr->setCreateDocuments(0);
  try {
    $results = $solr->search($query, 0, $_GET['limit'], $params);
    $results = json_decode($results->getRawResponse(), TRUE);
    $objects = array();
    foreach ($results['response']['docs'] as $doc) {
      $objects[] = array(
        'pid' => $doc['PID'],
        'label' => $doc['fgs_label_s'],
      );
    }
    return $objects;
  }
  catch (Exception $exception) {
    watchdog_exception('islandora_cwrc_writer', $exception, 'Got an exception while searching.', array(), WATCHDOG_ERROR);
  }
  return array();
}

/**
 * Handles all the CWRC-API Entity requests.
 *
 * The validation of the $type argument is handled by the menu access callback.
 *
 * @param string $type
 *   The type of entity to get/update/delete. Expected to be 'person', 'place',
 *   'title' or 'organization'.
 * @param string $value
 *   The PID of the entity in which to perform the request upon.
 */
function islandora_cwrc_writer_cwrc_api_entity($type, $value = NULL) {
  // @ignore security_17:function
  module_load_include('inc', 'islandora_rest', 'includes/utilities');
  module_load_include('inc', 'islandora_rest', 'includes/datastream');
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $request_method = islandora_rest_get_request_method();
  try {
    // Fetch the requested resource. Throws 404, if the resource is not found.
    $resource = islandora_rest_get_requested_resource($value);
    // Check Drupal Permissions. Throws 401, 403, if access is denied.
    islandora_rest_require_access('object', $request_method, $resource);
    // Generate the Response, we don't implement POST / DELETE as we don't
    // currently allow the user to make new documents or remove them.
    switch ($request_method) {
      case 'GET':
        $response = islandora_cwrc_writer_cwrc_api_get_entity($resource);
        break;

      case 'PUT':
        // The PUT is actually a POST, it's method is specified as POST data.
        $response = islandora_cwrc_writer_cwrc_api_update_entity($resource, $_POST['data']);
        break;

      case 'POST':
        $response = islandora_cwrc_writer_cwrc_api_create_entity($type, $_POST['data']);
        break;

      default:
        throw new Exception('Not Implemented', 500);
    }
  }
  catch (Exception $e) {
    drupal_add_http_header('Status', $e->getCode());
    // CWRC-Writer currently ignores the response aside from the status code,
    // when an error occurs.
    $response = array('message' => $e->getMessage());
  }
  $encode = is_array($response) || is_object($response);
  if ($encode) {
    // Responses that don't generate objects or arrays, must set their own
    // content types. Not calling drupal_json_output because we are setting
    // encoding.
    drupal_add_http_header('Content-Type', 'application/json; utf-8');
    drupal_json_output($response);
  }
  else {
    echo $response;
  }
  drupal_exit();
}

/**
 * Fetch the Entity's content.
 *
 * @param AbstractObject $object
 *   Gets the given entity's content.
 *
 * @return string
 *   The entities content.
 */
function islandora_cwrc_writer_cwrc_api_get_entity(AbstractObject $object) {
  $dsid = islandora_cwrc_writer_entity_content_datastream_id($object);
  drupal_add_http_header('Content-Type', 'text/xml; utf-8');
  return isset($object[$dsid]) ? $object[$dsid]->content : '';
}

/**
 * Update the given Entity with the given content.
 *
 * @throws Exception
 *
 * @param AbstractObject $object
 *   The Entity object to update.
 * @param string $content
 *   The content to update the entity with.
 *
 * @return array
 *   The response the CWRC-Writer expected.
 */
function islandora_cwrc_writer_cwrc_api_update_entity(AbstractObject $object, $content) {
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $dsid = islandora_cwrc_writer_entity_content_datastream_id($object);
  if (empty($object[$dsid])) {
    $message = t('Could not update Entity: %label (%pid)', array(
      '%label' => $object->label,
      '%pid' => $object->id,
    ));
    throw new Exception($message, 404);
  }
  // Update the Content.
  $object[$dsid]->content = $content;
  $type = islandora_cwrc_writer_get_entity_type($object);
  // Update the label.
  $object->label = islandora_cwrc_writer_cwrc_api_get_entity_label($type, $content);
  return array(
    'pid' => $object->id,
  );
}

/**
 * Creates a new entity from the given content.
 *
 * @param string $type
 *   The type of entity to create.
 * @param string $content
 *   The datastream content for the new entity.
 *
 * @return array
 *   An associative array containing the 'pid' of the newly created entity.
 */
function islandora_cwrc_writer_cwrc_api_create_entity($type, $content) {
  module_load_include('inc', 'islandora_cwrc_writer', 'includes/utilities');
  $valid_types = islandora_cwrc_writer_valid_entity_types();
  $content_model = $valid_types[$type];
  $tuque = islandora_get_tuque_connection();
  $object = $tuque->repository->constructObject('cwrc', TRUE);
  $object->models = array($content_model);
  $object->label = islandora_cwrc_writer_cwrc_api_get_entity_label($type, $content);
  $collection_pid = islandora_cwrc_writer_default_entity_collection($type);
  if ($collection_pid) {
    $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $collection_pid);
  }
  $dsid = islandora_cwrc_writer_entity_content_datastream_id($object);
  $datastream = $object->constructDatastream($dsid, 'M');
  $datastream->mimetype = 'text/xml';
  $datastream->setContentFromString($content);
  $object->ingestDatastream($datastream);
  $object = $tuque->repository->ingestObject($object);
  return array(
    'pid' => $object->id,
  );
}

/**
 * Parses the given entity's $content for a suitable label based on its $type.
 *
 * @param string $type
 *   The type of entity, used to interpret the $content.
 * @param string $content
 *   An entities content to parse for the label.
 *
 * @return string
 *   The label as extracted from the given content.
 */
function islandora_cwrc_writer_cwrc_api_get_entity_label($type, $content) {
  $get_label_functions = array(
    'person' => 'islandora_cwrc_writer_cwrc_api_get_person_label',
    'organization' => 'islandora_cwrc_writer_cwrc_api_get_organization_label',
    'place' => 'islandora_cwrc_writer_cwrc_api_get_place_label',
    'title' => 'islandora_cwrc_writer_cwrc_api_get_title_label',
  );
  $type = strtolower($type);
  if (isset($get_label_functions[$type])) {
    return call_user_func($get_label_functions[$type], $content);
  }
  return '';
}

/**
 * Gets a suitable label from the given content.
 *
 * @param string $content
 *   An entities content to parse for the label.
 *
 * @return string
 *   The label as extracted from the given content.
 */
function islandora_cwrc_writer_cwrc_api_get_person_label($content) {
  // The CWRC-Writer Entity XML, is expected to have an <?xml-model>
  // declaration which Simple XML can't handle without generating warnings, so
  // we just ignore all warnings.
  $xml = @simplexml_load_string($content);
  $name_parts = $xml->person[0]->identity[0]->preferredForm[0]->namePart;
  $forename = $surname = '';
  foreach ($name_parts as $name_part) {
    if (strcmp($name_part['partType'], 'surname') == 0) {
      $surname = $surname . ' ' . (string) $name_part;
    }
    elseif (strcmp($name_part['partType'], 'forename') == 0) {
      $forename = $forename . ' ' . (string) $name_part;
    }
    else {
      $surname = $surname . ' ' . (string) $name_part;
    }
  }
  trim($surname);
  trim($forename);
  if (strlen($forename) > 0) {
    return (strlen($surname) > 0) ? $surname . ', ' . $forename : $forename;
  }
  return $surname;
}

/**
 * Gets a suitable label from the given content.
 *
 * @param string $content
 *   An entities content to parse for the label.
 *
 * @return string
 *   The label as extracted from the given content.
 */
function islandora_cwrc_writer_cwrc_api_get_organization_label($content) {
  // The CWRC-Writer Entity XML, is expected to have an <?xml-model>
  // declaration which Simple XML can't handle without generating warnings, so
  // we just ignore all warnings.
  $xml = @simplexml_load_string($content);
  return (string) $xml->organization[0]->identity[0]->preferredForm[0]->namePart;
}

/**
 * Gets a suitable label from the given content.
 *
 * @param string $content
 *   An entities content to parse for the label.
 *
 * @return string
 *   The label as extracted from the given content.
 */
function islandora_cwrc_writer_cwrc_api_get_place_label($content) {
  // The CWRC-Writer Entity XML, is expected to have an <?xml-model>
  // declaration which Simple XML can't handle without generating warnings, so
  // we just ignore all warnings.
  $xml = @simplexml_load_string($content);
  return (string) $xml->place[0]->identity[0]->preferredForm[0]->namePart;
}

/**
 * Gets a suitable label from the given content.
 *
 * @param string $content
 *   An entities content to parse for the label.
 *
 * @return string
 *   The label as extracted from the given content.
 */
function islandora_cwrc_writer_cwrc_api_get_title_label($content) {
  // The CWRC-Writer Entity XML, is expected to have an <?xml-model>
  // declaration which Simple XML can't handle without generating warnings, so
  // we just ignore all warnings.
  $xml = @simplexml_load_string($content);
  $prime_title = '';
  $plain_title = '';
  $prime_set = FALSE;
  foreach ($xml->titleInfo as $title_info) {
    // Check for primary title.
    if (isset($title_info['usage']) && $title_info['usage'] = 'Primary') {
      $prime_title = (string) $title_info->title;
      $prime_set = TRUE;
    }
    // Ignore alternatives.
    elseif (isset($title_info['type']) && $title_info['type'] = 'alternative') {
    }
    else {
      $plain_title = (string) $title_info->title;
    }
  }
  return $prime_set ? $prime_title : $plain_title;
}
