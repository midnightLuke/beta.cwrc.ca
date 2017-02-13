<?php

/**
 * @file
 * Helper functions to build and map different EAP entities.
 */

/**
 * Helper function to perform additional preprocessing for person entities.
 *
 * @param array &$build
 *   The finished build array, should be modified directly by this function.
 */
function _cwrc_eap_build_person(&$build) {
  $object = $build['#object'];

  // Get SimpleXMLElement for the "PERSON" datastream.
  try {
    $xml = @new SimpleXMLElement($object['PERSON']->content);
  }
  catch (Exception $e) {
    drupal_set_message(t('Unable to parse entity datastream, XML is malformed.'), 'error');
    return;
  }

  // Get info arrays.
  $recordInfo = $xml->person->recordInfo;
  $identity = $xml->person->identity;
  $description = $xml->person->description;

  // Base item list for use below.
  $list_base = array(
    '#theme' => 'cwrc_eap_info',
    '#elements' => array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => array(),
      '#title' => NULL,
      '#attributes' => array(),
    ),
  );

  // Access conditions.
  $build['#info_record']['accessConditions'] = array(
    '#theme' => 'cwrc_eap_info',
    '#label' => t('Access Conditions'),
    '#elements' => strip_tags($recordInfo->accessCondition->asXML(), '<a>'),
  );
  if (isset($recordInfo->accessCondition['type'])) {
    $build['#info_record']['accessConditions']['#elements'] .= ' (' . $recordInfo->accessCondition['type'] . ')';
  }

  // Contributing Project(s).
  if (isset($recordInfo->originInfo->projectId)) {
    $build['#info_record']['originInfo'] = array('#label' => t('Contributing Project(s)')) + $list_base;
    foreach ($recordInfo->originInfo->projectId as $project) {
      $build['#info_record']['originInfo']['#elements']['#items'][] = (string) $project;
    }
  }

  // Person types.
  if (isset($recordInfo->personTypes)) {
    $build['#info_record']['personTypes'] = array('#label' => t('Person Type(s)')) + $list_base;
    foreach ($recordInfo->personTypes->personType as $personType) {
      $build['#info_record']['personTypes']['#elements']['#items'][] = _cwrc_eap_map_person_type($personType);
    }
  }

  // Preferred names.
  if (isset($identity->preferredForm)) {
    $build['#info_identity']['preferredForm'] = array('#label' => t('Preferred Name(s)')) + $list_base;
    foreach ($identity->preferredForm->namePart as $namePart) {
      $content = (string) $namePart;
      if (isset($namePart['partType'])) {
        $content .= ' (<em>' . _cwrc_eap_map_name_type($namePart['partType']) . '</em>)';
      }
      $build['#info_identity']['preferredForm']['#elements']['#items'][] = $content;
    }
  }

  // Display label.
  if (isset($identity->displayLabel)) {
    $build['#info_identity']['displayLabel'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Display Label'),
      '#elements' => (string) $identity->displayLabel,
    );
  }

  // Variant names.
  if (isset($identity->variantForms)) {
    $build['#info_identity']['variantForms'] = array('#label' => t('Variant Name(s)')) + $list_base;
    foreach ($identity->variantForms->variant as $variantForm) {
      // Variant names is a complex data-type, build in portions then render.
      $content = array();
      $content['namePart'] = array(
        '#markup' => $variantForm->namePart,
        '#prefix' => '<div class="info-part">',
        '#suffix' => '</div>',
      );

      // Has a partType definition.
      if (isset($variantForm->namePart['partType'])) {
        $content['namePart']['#markup'] .= ' (<em>' . _cwrc_eap_map_name_type($variantForm->namePart['partType']) . '</em>)';
      }

      // Variant type.
      if (isset($variantForm->variantType)) {
        $content['variantType'] = array(
          '#markup' => '<strong>' . t('Variant Type') . '</strong><br />' . _cwrc_eap_map_variant_type($variantForm->variantType),
          '#prefix' => '<div class="info-part">',
          '#suffix' => '</div>',
        );
      }

      // Prefferred by projects.
      if (isset($variantForm->authorizedBy)) {
        $content['authorizedBy'] = array(
          '#theme' => 'item_list',
          '#attributes' => array(),
          '#items' => array(),
          '#prefix' => '<div class="info-part"><strong>' . t('Prefferred By') . '</strong>',
          '#suffix' => '</div>',
        );
        foreach ($variantForm->authorizedBy as $authorizedBy) {
          $content['authorizedBy']['#items'][] = $authorizedBy->projectId;
        }
      }
      $build['#info_identity']['variantForms']['#elements']['#items'][] = render($content);
    }
  }

  // Same as.
  if (isset($identity->sameAs)) {
    $build['#info_identity']['sameAs'] = array('#label' => t('Same As')) + $list_base;
    foreach ($identity->sameAs as $sameAs) {
      if (valid_url($sameAs, TRUE)) {
        $content = l($sameAs, $sameAs);
      }
      else {
        $content = (string) $sameAs;
      }

      // Certainty was specified.
      if (isset($sameAs['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($sameAs['cert']) . '</em>)';
      }
      $build['#info_identity']['sameAs']['#elements']['#items'][] = $content;
    }
  }

  // Date(s) of existence.
  if (isset($description->existDates)) {
    $build['#info_description']['existDates'] = array('#label' => t('Date(s) of Existence')) + $list_base;
    foreach ($description->existDates->dateSingle as $dateSingle) {
      $content = '<strong>' . _cwrc_eap_map_date_type($dateSingle->dateType) . '</strong>: ';
      $content .= $dateSingle->standardDate;
      if (isset($dateSingle['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($dateSingle['cert']) . '</em>)';
      }
      if (isset($dateSingle->note)) {
        $content .= '<p><strong>Note:</strong> ' . $dateSingle->note . '</p>';
      }
      $build['#info_description']['existDates']['#elements']['#items'][] = render($content);
    }
  }

  // Factuality.
  if (isset($description->factuality)) {
    $build['#info_description']['factuality'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Factuality'),
      '#elements' => array(
        '#markup' => _cwrc_eap_map_factuality($description->factuality),
      ),
    );
  }

  // Gender(s).
  if (isset($description->genders)) {
    $build['#info_description']['genders'] = array('#label' => t('Gender(s)')) + $list_base;
    foreach ($description->genders->gender as $gender) {
      $content = (string) $gender;
      if (isset($gender['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($gender['cert']) . '</em>)';
      }
      $build['#info_description']['genders']['#elements']['#items'][] = $content;
    }
  }

  // Occupation(s).
  if (isset($description->occupations)) {
    $build['#info_description']['occupations'] = array('#label' => t('Occupation(s)')) + $list_base;
    foreach ($description->occupations->occupation as $occupation) {
      $content = (string) $occupation->term;
      if (isset($occupation->term['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($occupation->term['cert']) . '</em>)';
      }
      if (isset($occupation->note)) {
        $content .= '<p><strong>Note:</strong> ' . $occupation->note . '</p>';
      }
      $build['#info_description']['occupations']['#elements']['#items'][] = $content;
    }
  }

  // Activities.
  if (isset($description->activities)) {
    $build['#info_description']['activities'] = array('#label' => t('Activities')) + $list_base;
    foreach ($description->activities->activity as $activity) {
      $content = (string) $activity->term;
      if (isset($activity->term['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($activity->term['cert']) . '</em>)';
      }
      $build['#info_description']['activities']['#elements']['#items'][] = $content;
    }
  }

  // Research Interests.
  if (isset($description->researchInterests)) {
    $build['#info_description']['researchInterests'] = array('#label' => t('Research Interests')) + $list_base;
    foreach ($description->researchInterests->interest as $interest) {
      $content = (string) $interest->term;
      if (isset($interest->term['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($interest->term['cert']) . '</em>)';
      }
      $build['#info_description']['researchInterests']['#elements']['#items'][] = $content;
    }
  }

  // Descriptive Notes.
  if (isset($description->descriptiveNotes)) {
    $build['#info_description']['descriptiveNotes'] = array('#label' => t('Descriptive Notes')) + $list_base;
    foreach ($description->descriptiveNotes->note as $note) {
      $build['#info_description']['descriptiveNotes']['#elements']['#items'][] = (string) $note;
    }
  }

  // Related Resources.
  if (isset($description->relatedResources)) {
    $build['#info_description']['relatedResources'] = array('#label' => t('Related Resources')) + $list_base;
    foreach ($description->relatedResources->resource as $resource) {
      $build['#info_description']['relatedResources']['#elements']['#items'][] = (string) $resource;
    }
  }
}

/**
 * Helper to perform additional preprocessing for organization entities.
 *
 * @param array &$build
 *   The finished build array, should be modified directly by this function.
 */
function _cwrc_eap_build_organization(&$build) {
  $object = $build['#object'];

  // Get SimpleXMLElement for the "ORGANIZATION" datastream.
  try {
    $xml = @new SimpleXMLElement($object['ORGANIZATION']->content);
  }
  catch (Exception $e) {
    drupal_set_message(t('Unable to parse entity datastream, XML is malformed.'), 'error');
    return;
  }

  // Get info arrays.
  $recordInfo = $xml->organization->recordInfo;
  $identity = $xml->organization->identity;
  $description = $xml->organization->description;

  // Base item list for use below.
  $list_base = array(
    '#theme' => 'cwrc_eap_info',
    '#elements' => array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => array(),
      '#title' => NULL,
      '#attributes' => array(),
    ),
  );

  // Access conditions.
  $build['#info_record']['accessConditions'] = array(
    '#theme' => 'cwrc_eap_info',
    '#label' => t('Access Conditions'),
    '#elements' => strip_tags($recordInfo->accessCondition->asXML(), '<a>'),
  );
  if (isset($recordInfo->accessCondition['type'])) {
    $build['#info_record']['accessConditions']['#elements'] .= ' (' . $recordInfo->accessCondition['type'] . ')';
  }

  // Contributing Project(s).
  if (isset($recordInfo->originInfo->projectId)) {
    $build['#info_record']['originInfo'] = array('#label' => t('Contributing Project(s)')) + $list_base;
    foreach ($recordInfo->originInfo->projectId as $project) {
      $build['#info_record']['originInfo']['#elements']['#items'][] = (string) $project;
    }
  }

  // Organization types.
  if (isset($recordInfo->orgTypes)) {
    $build['#info_record']['orgTypes'] = array('#label' => t('Organization Type(s)')) + $list_base;
    foreach ($recordInfo->orgTypes->orgType as $orgType) {
      $build['#info_record']['orgTypes']['#elements']['#items'][] = $orgType;
    }
  }

  // Preferred names.
  if (isset($identity->preferredForm)) {
    $build['#info_identity']['preferredForm'] = array('#label' => t('Preferred Name(s)')) + $list_base;
    foreach ($identity->preferredForm->namePart as $namePart) {
      $build['#info_identity']['preferredForm']['#elements']['#items'][] = (string) $namePart;
    }
  }

  // Variant names.
  if (isset($identity->variantForms)) {
    $build['#info_identity']['variantForms'] = array('#label' => t('Variant Name(s)')) + $list_base;
    foreach ($identity->variantForms->variant as $variantForm) {
      // Variant names is a complex data-type, build in portions then render.
      $content = array();
      $content['namePart'] = array(
        '#markup' => $variantForm->namePart,
        '#prefix' => '<div class="info-part">',
        '#suffix' => '</div>',
      );

      // Has a partType definition.
      if (isset($variantForm->namePart['partType'])) {
        $content['namePart']['#markup'] .= ' (<em>' . _cwrc_eap_map_name_type($variantForm->namePart['partType']) . '</em>)';
      }

      // Variant type.
      if (isset($variantForm->variantType)) {
        $content['variantType'] = array(
          '#markup' => '<strong>' . t('Variant Type') . '</strong><br />' . _cwrc_eap_map_variant_type($variantForm->variantType),
          '#prefix' => '<div class="info-part">',
          '#suffix' => '</div>',
        );
      }

      // Prefferred by projects.
      if (isset($variantForm->authorizedBy)) {
        $content['authorizedBy'] = array(
          '#theme' => 'item_list',
          '#attributes' => array(),
          '#items' => array(),
          '#prefix' => '<div class="info-part"><strong>' . t('Prefferred By') . '</strong>',
          '#suffix' => '</div>',
        );
        foreach ($variantForm->authorizedBy as $authorizedBy) {
          $content['authorizedBy']['#items'][] = $authorizedBy->projectId;
        }
      }
      $build['#info_identity']['variantForms']['#elements']['#items'][] = render($content);
    }
  }

  // Same as.
  if (isset($identity->sameAs)) {
    $build['#info_identity']['sameAs'] = array('#label' => t('Same As')) + $list_base;
    foreach ($identity->sameAs as $sameAs) {
      if (valid_url($sameAs, TRUE)) {
        $content = l($sameAs, $sameAs);
      }
      else {
        $content = (string) $sameAs;
      }

      // Certainty was specified.
      if (isset($sameAs['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($sameAs['cert']) . '</em>)';
      }
      $build['#info_identity']['sameAs']['#elements']['#items'][] = $content;
    }
  }

  // Date(s) of existence.
  if (isset($description->existDates)) {
    $build['#info_description']['existDates'] = array('#label' => t('Date(s) of Existence')) + $list_base;
    foreach ($description->existDates->dateSingle as $dateSingle) {
      $content = '<strong>' . _cwrc_eap_map_date_type($dateSingle->dateType) . '</strong>: ';
      $content .= $dateSingle->standardDate;
      if (isset($dateSingle['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($dateSingle['cert']) . '</em>)';
      }
      if (isset($dateSingle->note)) {
        $content .= '<p><strong>Note:</strong> ' . $dateSingle->note . '</p>';
      }
      $build['#info_description']['existDates']['#elements']['#items'][] = render($content);
    }
  }

  // Factuality.
  if (isset($description->factuality)) {
    $build['#info_description']['factuality'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Factuality'),
      '#elements' => array(
        '#markup' => _cwrc_eap_map_factuality($description->factuality),
      ),
    );
  }

  // Descriptive Notes.
  if (isset($description->descriptiveNotes)) {
    $build['#info_description']['descriptiveNotes'] = array('#label' => t('Descriptive Notes')) + $list_base;
    foreach ($description->descriptiveNotes->note as $note) {
      $build['#info_description']['descriptiveNotes']['#elements']['#items'][] = (string) $note;
    }
  }

  // Related Resources.
  if (isset($description->relatedResources)) {
    $build['#info_description']['relatedResources'] = array('#label' => t('Related Resources')) + $list_base;
    foreach ($description->relatedResources->resource as $resource) {
      $build['#info_description']['relatedResources']['#elements']['#items'][] = (string) $resource;
    }
  }
}

/**
 * Helper function to perform additional preprocessing for place entities.
 *
 * @param array &$build
 *   The finished build array, should be modified directly by this function.
 */
function _cwrc_eap_build_place(&$build) {
  $object = $build['#object'];

  // Get SimpleXMLElement for the "PLACE" datastream.
  try {
    $xml = @new SimpleXMLElement($object['PLACE']->content);
  }
  catch (Exception $e) {
    drupal_set_message(t('Unable to parse entity datastream, XML is malformed.'), 'error');
    return;
  }

  // Get info arrays.
  $recordInfo = $xml->place->recordInfo;
  $identity = $xml->place->identity;
  $description = $xml->place->description;

  // Base item list for use below.
  $list_base = array(
    '#theme' => 'cwrc_eap_info',
    '#elements' => array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => array(),
      '#title' => NULL,
      '#attributes' => array(),
    ),
  );

  // Access conditions.
  $build['#info_record']['accessConditions'] = array(
    '#theme' => 'cwrc_eap_info',
    '#label' => t('Access Conditions'),
    '#elements' => strip_tags($recordInfo->accessCondition->asXML(), '<a>'),
  );
  if (isset($recordInfo->accessCondition['type'])) {
    $build['#info_record']['accessConditions']['#elements'] .= ' (' . $recordInfo->accessCondition['type'] . ')';
  }

  // Contributing Project(s).
  if (isset($recordInfo->originInfo->projectId)) {
    $build['#info_record']['originInfo'] = array('#label' => t('Contributing Project(s)')) + $list_base;
    foreach ($recordInfo->originInfo->projectId as $project) {
      $build['#info_record']['originInfo']['#elements']['#items'][] = (string) $project;
    }
  }

  // Place types.
  if (isset($recordInfo->placeTypes)) {
    $build['#info_record']['placeTypes'] = array('#label' => t('Place Type(s)')) + $list_base;
    foreach ($recordInfo->placeTypes->placeType as $placeType) {
      $build['#info_record']['placeTypes']['#elements']['#items'][] = _cwrc_eap_map_place_type($placeType);
    }
  }

  // Preferred names.
  if (isset($identity->preferredForm)) {
    $build['#info_identity']['preferredForm'] = array('#label' => t('Preferred Name(s)')) + $list_base;
    foreach ($identity->preferredForm->namePart as $namePart) {
      $build['#info_identity']['preferredForm']['#elements']['#items'][] = (string) $namePart;
    }
  }

  // Variant names.
  if (isset($identity->variantForms)) {
    $build['#info_identity']['variantForms'] = array('#label' => t('Variant Name(s)')) + $list_base;
    foreach ($identity->variantForms->variant as $variantForm) {
      // Variant names is a complex data-type, build in portions then render.
      $content = array();
      $content['namePart'] = array(
        '#markup' => $variantForm->namePart,
        '#prefix' => '<div class="info-part">',
        '#suffix' => '</div>',
      );

      // Has a partType definition.
      if (isset($variantForm->namePart['partType'])) {
        $content['namePart']['#markup'] .= ' (<em>' . _cwrc_eap_map_name_type($variantForm->namePart['partType']) . '</em>)';
      }

      // Variant type.
      if (isset($variantForm->variantType)) {
        $content['variantType'] = array(
          '#markup' => '<strong>' . t('Variant Type') . '</strong><br />' . _cwrc_eap_map_variant_type($variantForm->variantType),
          '#prefix' => '<div class="info-part">',
          '#suffix' => '</div>',
        );
      }

      // Prefferred by projects.
      if (isset($variantForm->authorizedBy)) {
        $content['authorizedBy'] = array(
          '#theme' => 'item_list',
          '#attributes' => array(),
          '#items' => array(),
          '#prefix' => '<div class="info-part"><strong>' . t('Prefferred By') . '</strong>',
          '#suffix' => '</div>',
        );
        foreach ($variantForm->authorizedBy as $authorizedBy) {
          $content['authorizedBy']['#items'][] = $authorizedBy->projectId;
        }
      }
      $build['#info_identity']['variantForms']['#elements']['#items'][] = render($content);
    }
  }

  // Same as.
  if (isset($identity->sameAs)) {
    $build['#info_identity']['sameAs'] = array('#label' => t('Same As')) + $list_base;
    foreach ($identity->sameAs as $sameAs) {
      if (valid_url($sameAs, TRUE)) {
        $content = l($sameAs, $sameAs);
      }
      else {
        $content = (string) $sameAs;
      }

      // Certainty was specified.
      if (isset($sameAs['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($sameAs['cert']) . '</em>)';
      }
      $build['#info_identity']['sameAs']['#elements']['#items'][] = $content;
    }
  }

  // Date(s) of existence.
  if (isset($description->existDates)) {
    $build['#info_description']['existDates'] = array('#label' => t('Date(s) of Existence')) + $list_base;
    foreach ($description->existDates->dateSingle as $dateSingle) {
      $content = '<strong>' . _cwrc_eap_map_date_type($dateSingle->dateType) . '</strong>: ';
      $content .= $dateSingle->standardDate;
      if (isset($dateSingle['cert'])) {
        $content .= ' (<em>' . _cwrc_eap_map_certainty($dateSingle['cert']) . '</em>)';
      }
      if (isset($dateSingle->note)) {
        $content .= '<p><strong>Note:</strong> ' . $dateSingle->note . '</p>';
      }
      $build['#info_description']['existDates']['#elements']['#items'][] = render($content);
    }
  }

  // Factuality.
  if (isset($description->factuality)) {
    $build['#info_description']['factuality'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Factuality'),
      '#elements' => array(
        '#markup' => _cwrc_eap_map_factuality($description->factuality),
      ),
    );
  }

  // Latitude.
  if (isset($description->latitude)) {
    $build['#info_description']['latitude'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Latitude'),
      '#elements' => array(
        '#markup' => $description->latitude,
      ),
    );
  }

  // Longitude.
  if (isset($description->longitude)) {
    $build['#info_description']['longitude'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Longitude'),
      '#elements' => array(
        '#markup' => $description->longitude,
      ),
    );
  }

  // Feature Class.
  if (isset($description->featureClass)) {
    $build['#info_description']['featureClass'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Feature Class'),
      '#elements' => array(
        '#markup' => $description->featureClass,
      ),
    );
  }

  // Feature Code Label.
  if (isset($description->featureCodeLabel)) {
    $build['#info_description']['featureCodeLabel'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Feature Code Label'),
      '#elements' => array(
        '#markup' => $description->featureCodeLabel,
      ),
    );
  }

  // Country Name.
  if (isset($description->countryName)) {
    $build['#info_description']['countryName'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Country Name'),
      '#elements' => array(
        '#markup' => $description->countryName,
      ),
    );
  }

  // First-level Administrative Division.
  if (isset($description->firstAdministrativeDivision)) {
    $build['#info_description']['firstAdministrativeDivision'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('First-level Administrative Division'),
      '#elements' => array(
        '#markup' => $description->firstAdministrativeDivision,
      ),
    );
  }

  // Second-level Administrative Division.
  if (isset($description->secondAdministrativeDivision)) {
    $build['#info_description']['secondAdministrativeDivision'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Second-level Administrative Division'),
      '#elements' => array(
        '#markup' => $description->secondAdministrativeDivision,
      ),
    );
  }

  // Elevation.
  if (isset($description->elevation)) {
    $build['#info_description']['elevation'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Elevation'),
      '#elements' => array(
        '#markup' => $description->elevation,
      ),
    );
  }

  // Average Elevation.
  if (isset($description->averageElevation)) {
    $build['#info_description']['averageElevation'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Average Elevation'),
      '#elements' => array(
        '#markup' => $description->averageElevation,
      ),
    );
  }

  // Time Zone UTC Offset.
  if (isset($description->timeZoneOffset)) {
    $build['#info_description']['timeZoneOffset'] = array(
      '#theme' => 'cwrc_eap_info',
      '#label' => t('Time Zone UTC Offset'),
      '#elements' => array(
        '#markup' => $description->timeZoneOffset,
      ),
    );
  }

  // Descriptive Notes.
  if (isset($description->descriptiveNotes)) {
    $build['#info_description']['descriptiveNotes'] = array('#label' => t('Descriptive Notes')) + $list_base;
    foreach ($description->descriptiveNotes->note as $note) {
      $build['#info_description']['descriptiveNotes']['#elements']['#items'][] = (string) $note;
    }
  }

  // Related Resources.
  if (isset($description->relatedResources)) {
    $build['#info_description']['relatedResources'] = array('#label' => t('Related Resources')) + $list_base;
    foreach ($description->relatedResources->resource as $resource) {
      $build['#info_description']['relatedResources']['#elements']['#items'][] = (string) $resource;
    }
  }
}

/**
 * Helper function that statically maps keys to values for certainty selects.
 */
function _cwrc_eap_map_certainty($key) {
  $certainties = &drupal_static(__FUNCTION__);
  if (!isset($certainties)) {
    $certainties = array(
      '1' => t('Speculative'),
      '2' => t('Probable'),
      '3' => t('Reasonably Certain'),
      '4' => t('Definite'),
    );
  }

  $key = (string) $key;

  return isset($certainties[$key]) ? $certainties[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for person type selects.
 */
function _cwrc_eap_map_person_type($key) {
  $type = &drupal_static(__FUNCTION__);
  if (!isset($type)) {
    $type = array(
      'creator' => t('Creator'),
      'writer' => t('Writer'),
      'critic' => t('Critic'),
      'canwwr:creator' => t('Creator (CanWWr)'),
      'canwwr:critic' => t('Critic (CanWWr)'),
      'orl:BWW' => t('British Woman Writer (Orlando)'),
      'orl:IBW' => t('International-British Women Writer (Orlando)'),
      'orl:IWW' => t('International Women Writer (Orlando)'),
      'orl:MW' => t('Male Writer (Orlando)'),
    );
  }

  $key = (string) $key;

  return isset($type[$key]) ? $type[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for name type selects.
 */
function _cwrc_eap_map_name_type($key) {
  $type = &drupal_static(__FUNCTION__);
  if (!isset($type)) {
    $type = array(
      'family' => t('Family Name'),
      'fullName' => t('Full Name (inverse order)'),
      'fullNameInverted' => t('Full Name (inverse order)'),
      'fullNameDirect' => t('Full Name (direct order)'),
      'given' => t('Given Names'),
      'termsOfAddress' => t('Terms of Address'),
    );
  }

  $key = (string) $key;

  return isset($type[$key]) ? $type[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for date type selects.
 */
function _cwrc_eap_map_date_type($key) {
  $type = &drupal_static(__FUNCTION__);
  if (!isset($type)) {
    $type = array(
      'birth' => t('Birth'),
      'death' => t('Death'),
      'flourish' => t('Flourish'),
      'establishment' => t('Establishment'),
      'dissolution' => t('Dissolution'),
    );
  }

  $key = (string) $key;

  return isset($type[$key]) ? $type[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for factuality selects.
 */
function _cwrc_eap_map_factuality($key) {
  $factualities = &drupal_static(__FUNCTION__);
  if (!isset($factualities)) {
    $factualities = array(
      'real' => t('Real'),
      'fictional' => t('Fictional'),
      'both' => t('Both'),
    );
  }

  $key = (string) $key;

  return isset($factualities[$key]) ? $factualities[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for variant type selects.
 */
function _cwrc_eap_map_variant_type($key) {
  $type = &drupal_static(__FUNCTION__);
  if (!isset($type)) {
    $type = array(
      'birthName' => t('Birth Name'),
      'marriedName' => t('Married Name'),
      'indexedName' => t('Indexed Name'),
      'pseudonym' => t('Pseudonym'),
      'usedForm' => t('Used Form'),
      'nickname' => t('Nickname'),
      'religiousName' => t('Religious'),
      'royalName' => t('Royal'),
      'selfConstructedName' => t('Self Constructed'),
      'styledName' => t('Styled'),
      'titledName' => t('Titled'),
      'orlandoStandardName' => t('Orlando Standard Name'),
    );
  }

  $key = (string) $key;

  return isset($type[$key]) ? $type[$key] : $key;
}

/**
 * Helper function that statically maps keys to values for place type selects.
 */
function _cwrc_eap_map_place_type($key) {
  $type = &drupal_static(__FUNCTION__);
  if (!isset($type)) {
    $type = array(
      'currentHumanPlace' => t('current populated place or administrative boundary place name'),
      'historicalHumanPlace' => t('historical populated place or administrative boundary place name'),
      'currentNaturalPlace' => t('current natural geographic feature place name'),
      'historicalNaturalPlace' => t('historical natural geographic feature place name'),
    );
  }

  $key = (string) $key;

  return isset($type[$key]) ? $type[$key] : $key;
}
