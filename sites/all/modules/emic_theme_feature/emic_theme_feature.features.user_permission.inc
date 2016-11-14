<?php
/**
 * @file
 * emic_theme_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function emic_theme_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Associate XML Forms'.
  $permissions['Associate XML Forms'] = array(
    'name' => 'Associate XML Forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'xml_form_builder',
  );

  // Exported permission: 'Create XML Forms'.
  $permissions['Create XML Forms'] = array(
    'name' => 'Create XML Forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'xml_form_builder',
  );

  // Exported permission: 'Delete XML Forms'.
  $permissions['Delete XML Forms'] = array(
    'name' => 'Delete XML Forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'xml_form_builder',
  );

  // Exported permission: 'Edit XML Forms'.
  $permissions['Edit XML Forms'] = array(
    'name' => 'Edit XML Forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'xml_form_builder',
  );

  // Exported permission: 'Edit existing OCR stream'.
  $permissions['Edit existing OCR stream'] = array(
    'name' => 'Edit existing OCR stream',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_paged_content',
  );

  // Exported permission: 'List XML Forms'.
  $permissions['List XML Forms'] = array(
    'name' => 'List XML Forms',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'xml_form_builder',
  );

  // Exported permission: 'Manage CSL Citations'.
  $permissions['Manage CSL Citations'] = array(
    'name' => 'Manage CSL Citations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'csl',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'add collation'.
  $permissions['add collation'] = array(
    'name' => 'add collation',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'collation',
  );

  // Exported permission: 'add fedora datastreams'.
  $permissions['add fedora datastreams'] = array(
    'name' => 'add fedora datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'administer critical edition'.
  $permissions['administer critical edition'] = array(
    'name' => 'administer critical edition',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'emicdora',
  );

  // Exported permission: 'administer islandora entities'.
  $permissions['administer islandora entities'] = array(
    'name' => 'administer islandora entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_entities',
  );

  // Exported permission: 'administer islandora plupload'.
  $permissions['administer islandora plupload'] = array(
    'name' => 'administer islandora plupload',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_plupload',
  );

  // Exported permission: 'administer islandora solr'.
  $permissions['administer islandora solr'] = array(
    'name' => 'administer islandora solr',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_solr',
  );

  // Exported permission: 'administer islandora_bookmark'.
  $permissions['administer islandora_bookmark'] = array(
    'name' => 'administer islandora_bookmark',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_bookmark',
  );

  // Exported permission: 'administer islandora_solr_metadata'.
  $permissions['administer islandora_solr_metadata'] = array(
    'name' => 'administer islandora_solr_metadata',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_solr_metadata',
  );

  // Exported permission: 'administer islandora_xacml_api'.
  $permissions['administer islandora_xacml_api'] = array(
    'name' => 'administer islandora_xacml_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_xacml_api',
  );

  // Exported permission: 'administer islandora_xacml_editor'.
  $permissions['administer islandora_xacml_editor'] = array(
    'name' => 'administer islandora_xacml_editor',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_xacml_editor',
  );

  // Exported permission: 'administer xacml inheritance'.
  $permissions['administer xacml inheritance'] = array(
    'name' => 'administer xacml inheritance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_xacml_editor',
  );

  // Exported permission: 'consolidate tei'.
  $permissions['consolidate tei'] = array(
    'name' => 'consolidate tei',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'versionable_object_viewer',
  );

  // Exported permission: 'create child collection'.
  $permissions['create child collection'] = array(
    'name' => 'create child collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'create image annotations'.
  $permissions['create image annotations'] = array(
    'name' => 'create image annotations',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_image_annotation',
  );

  // Exported permission: 'delete fedora objects and datastreams'.
  $permissions['delete fedora objects and datastreams'] = array(
    'name' => 'delete fedora objects and datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'edit collation'.
  $permissions['edit collation'] = array(
    'name' => 'edit collation',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'collation',
  );

  // Exported permission: 'edit fedora metadata'.
  $permissions['edit fedora metadata'] = array(
    'name' => 'edit fedora metadata',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'edit metadata'.
  $permissions['edit metadata'] = array(
    'name' => 'edit metadata',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'repository',
  );

  // Exported permission: 'edit mvds'.
  $permissions['edit mvds'] = array(
    'name' => 'edit mvds',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'collationtools',
  );

  // Exported permission: 'edit scholar metadata'.
  $permissions['edit scholar metadata'] = array(
    'name' => 'edit scholar metadata',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_entities',
  );

  // Exported permission: 'export islandora bookmarks'.
  $permissions['export islandora bookmarks'] = array(
    'name' => 'export islandora bookmarks',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_bookmark',
  );

  // Exported permission: 'ingest fedora objects'.
  $permissions['ingest fedora objects'] = array(
    'name' => 'ingest fedora objects',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'islandora_batch_manage_queue'.
  $permissions['islandora_batch_manage_queue'] = array(
    'name' => 'islandora_batch_manage_queue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_batch',
  );

  // Exported permission: 'manage collection policy'.
  $permissions['manage collection policy'] = array(
    'name' => 'manage collection policy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'manage critical edition'.
  $permissions['manage critical edition'] = array(
    'name' => 'manage critical edition',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'emicdora',
  );

  // Exported permission: 'manage deleted objects'.
  $permissions['manage deleted objects'] = array(
    'name' => 'manage deleted objects',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'manage object properties'.
  $permissions['manage object properties'] = array(
    'name' => 'manage object properties',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'migrate collection members'.
  $permissions['migrate collection members'] = array(
    'name' => 'migrate collection members',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'modify datastreams'.
  $permissions['modify datastreams'] = array(
    'name' => 'modify datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'regenerate derivatives for an object'.
  $permissions['regenerate derivatives for an object'] = array(
    'name' => 'regenerate derivatives for an object',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'replace a datastream with new content, preserving version history'.
  $permissions['replace a datastream with new content, preserving version history'] = array(
    'name' => 'replace a datastream with new content, preserving version history',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'revert to old datastream'.
  $permissions['revert to old datastream'] = array(
    'name' => 'revert to old datastream',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'search islandora solr'.
  $permissions['search islandora solr'] = array(
    'name' => 'search islandora solr',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_solr',
  );

  // Exported permission: 'share islandora bookmarks'.
  $permissions['share islandora bookmarks'] = array(
    'name' => 'share islandora bookmarks',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_bookmark',
  );

  // Exported permission: 'use islandora_bookmark'.
  $permissions['use islandora_bookmark'] = array(
    'name' => 'use islandora_bookmark',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_bookmark',
  );

  // Exported permission: 'use version viewer'.
  $permissions['use version viewer'] = array(
    'name' => 'use version viewer',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'versionable_object_viewer',
  );

  // Exported permission: 'view collation tools'.
  $permissions['view collation tools'] = array(
    'name' => 'view collation tools',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'collationtools',
  );

  // Exported permission: 'view datastreams'.
  $permissions['view datastreams'] = array(
    'name' => 'view datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'view fedora repository objects'.
  $permissions['view fedora repository objects'] = array(
    'name' => 'view fedora repository objects',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'view image annotations'.
  $permissions['view image annotations'] = array(
    'name' => 'view image annotations',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_image_annotation',
  );

  // Exported permission: 'view metadata'.
  $permissions['view metadata'] = array(
    'name' => 'view metadata',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'repository',
  );

  // Exported permission: 'view old datastream versions'.
  $permissions['view old datastream versions'] = array(
    'name' => 'view old datastream versions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'view technical metadata'.
  $permissions['view technical metadata'] = array(
    'name' => 'view technical metadata',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_fits',
  );

  // Exported permission: 'view visualizations'.
  $permissions['view visualizations'] = array(
    'name' => 'view visualizations',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'repository',
  );

  return $permissions;
}
