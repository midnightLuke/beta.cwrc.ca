<?php
/**
 * @file
 * cwrc_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cwrc_permissions_user_default_permissions() {
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

  // Exported permission: 'Islandora CWRC BASEX Query'.
  $permissions['Islandora CWRC BASEX Query'] = array(
    'name' => 'Islandora CWRC BASEX Query',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_cwrc_basexdb',
  );

  // Exported permission: 'List XML Forms'.
  $permissions['List XML Forms'] = array(
    'name' => 'List XML Forms',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'Orlando User' => 'Orlando User',
      'administrator' => 'administrator',
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

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all saved reports'.
  $permissions['access all saved reports'] = array(
    'name' => 'access all saved reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_workflow_rest',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access user dashboard'.
  $permissions['access user dashboard'] = array(
    'name' => 'access user dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cwrc_dashboards',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
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

  // Exported permission: 'add or remove islandora object lock'.
  $permissions['add or remove islandora object lock'] = array(
    'name' => 'add or remove islandora object lock',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_object_lock',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer Islandora BagIt'.
  $permissions['administer Islandora BagIt'] = array(
    'name' => 'administer Islandora BagIt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_bagit',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(),
    'module' => 'block_class',
  );

  // Exported permission: 'administer block semantics'.
  $permissions['administer block semantics'] = array(
    'name' => 'administer block semantics',
    'roles' => array(),
    'module' => 'borealis_sb',
  );

  // Exported permission: 'administer blockify'.
  $permissions['administer blockify'] = array(
    'name' => 'administer blockify',
    'roles' => array(),
    'module' => 'blockify',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'administer compound relationships'.
  $permissions['administer compound relationships'] = array(
    'name' => 'administer compound relationships',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_compound_object',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer contextual help'.
  $permissions['administer contextual help'] = array(
    'name' => 'administer contextual help',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'de_contextual_help',
  );

  // Exported permission: 'administer encrypt'.
  $permissions['administer encrypt'] = array(
    'name' => 'administer encrypt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'encrypt',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer google tag manager'.
  $permissions['administer google tag manager'] = array(
    'name' => 'administer google tag manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'google_tag',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
    'module' => 'imce',
  );

  // Exported permission: 'administer islandora entities'.
  $permissions['administer islandora entities'] = array(
    'name' => 'administer islandora entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_entities',
  );

  // Exported permission: 'administer islandora object locking'.
  $permissions['administer islandora object locking'] = array(
    'name' => 'administer islandora object locking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_object_lock',
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

  // Exported permission: 'administer islandora_xquery'.
  $permissions['administer islandora_xquery'] = array(
    'name' => 'administer islandora_xquery',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_xquery',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modernizr'.
  $permissions['administer modernizr'] = array(
    'name' => 'administer modernizr',
    'roles' => array(),
    'module' => 'modernizr',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer openid provider'.
  $permissions['administer openid provider'] = array(
    'name' => 'administer openid provider',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'openid_provider',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer quicktabs'.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quicktabs',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'administer saved islandora searches'.
  $permissions['administer saved islandora searches'] = array(
    'name' => 'administer saved islandora searches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_saved_searches',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'administer xacml inheritance'.
  $permissions['administer xacml inheritance'] = array(
    'name' => 'administer xacml inheritance',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_xacml_editor',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'annotate CWRC datastreams'.
  $permissions['annotate CWRC datastreams'] = array(
    'name' => 'annotate CWRC datastreams',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_cwrc_document',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass recipient message limit'.
  $permissions['bypass recipient message limit'] = array(
    'name' => 'bypass recipient message limit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_limits',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'configure openid connect clients'.
  $permissions['configure openid connect clients'] = array(
    'name' => 'configure openid connect clients',
    'roles' => array(),
    'module' => 'openid_connect',
  );

  // Exported permission: 'create Islandora Bags'.
  $permissions['create Islandora Bags'] = array(
    'name' => 'create Islandora Bags',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_bagit',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create child collection'.
  $permissions['create child collection'] = array(
    'name' => 'create child collection',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'create critical edition'.
  $permissions['create critical edition'] = array(
    'name' => 'create critical edition',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition',
  );

  // Exported permission: 'create critical editions'.
  $permissions['create critical editions'] = array(
    'name' => 'create critical editions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition_advanced',
  );

  // Exported permission: 'create datastreams'.
  $permissions['create datastreams'] = array(
    'name' => 'create datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'create entity'.
  $permissions['create entity'] = array(
    'name' => 'create entity',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cwrc_entities',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create field_research_space'.
  $permissions['create field_research_space'] = array(
    'name' => 'create field_research_space',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_level_collection'.
  $permissions['create field_top_level_collection'] = array(
    'name' => 'create field_top_level_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'create objects'.
  $permissions['create objects'] = array(
    'name' => 'create objects',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'create open annotations'.
  $permissions['create open annotations'] = array(
    'name' => 'create open annotations',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cwrc_entities',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create private message tags'.
  $permissions['create private message tags'] = array(
    'name' => 'create private message tags',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create relationships'.
  $permissions['create relationships'] = array(
    'name' => 'create relationships',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'create slider_content content'.
  $permissions['create slider_content content'] = array(
    'name' => 'create slider_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any slider_content content'.
  $permissions['delete any slider_content content'] = array(
    'name' => 'delete any slider_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete critical edition'.
  $permissions['delete critical edition'] = array(
    'name' => 'delete critical edition',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition',
  );

  // Exported permission: 'delete critical editions'.
  $permissions['delete critical editions'] = array(
    'name' => 'delete critical editions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition_advanced',
  );

  // Exported permission: 'delete datastreams'.
  $permissions['delete datastreams'] = array(
    'name' => 'delete datastreams',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'delete fedora objects and datastreams'.
  $permissions['delete fedora objects and datastreams'] = array(
    'name' => 'delete fedora objects and datastreams',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'delete objects'.
  $permissions['delete objects'] = array(
    'name' => 'delete objects',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own slider_content content'.
  $permissions['delete own slider_content content'] = array(
    'name' => 'delete own slider_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'delete relationships'.
  $permissions['delete relationships'] = array(
    'name' => 'delete relationships',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit CWRC'.
  $permissions['edit CWRC'] = array(
    'name' => 'edit CWRC',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_critical_edition',
  );

  // Exported permission: 'edit CWRC datastreams'.
  $permissions['edit CWRC datastreams'] = array(
    'name' => 'edit CWRC datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_cwrc_document',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any slider_content content'.
  $permissions['edit any slider_content content'] = array(
    'name' => 'edit any slider_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
    'module' => 'node',
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

  // Exported permission: 'edit field_research_space'.
  $permissions['edit field_research_space'] = array(
    'name' => 'edit field_research_space',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_level_collection'.
  $permissions['edit field_top_level_collection'] = array(
    'name' => 'edit field_top_level_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_research_space'.
  $permissions['edit own field_research_space'] = array(
    'name' => 'edit own field_research_space',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_level_collection'.
  $permissions['edit own field_top_level_collection'] = array(
    'name' => 'edit own field_top_level_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own slider_content content'.
  $permissions['edit own slider_content content'] = array(
    'name' => 'edit own slider_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit scholar metadata'.
  $permissions['edit scholar metadata'] = array(
    'name' => 'edit scholar metadata',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_entities',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit views basic settings'.
  $permissions['edit views basic settings'] = array(
    'name' => 'edit views basic settings',
    'roles' => array(),
    'module' => 'views_ui_basic',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
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

  // Exported permission: 'filter private messages'.
  $permissions['filter private messages'] = array(
    'name' => 'filter private messages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'flag favourite_projects'.
  $permissions['flag favourite_projects'] = array(
    'name' => 'flag favourite_projects',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate datastream token'.
  $permissions['generate datastream token'] = array(
    'name' => 'generate datastream token',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'ingest fedora objects'.
  $permissions['ingest fedora objects'] = array(
    'name' => 'ingest fedora objects',
    'roles' => array(
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

  // Exported permission: 'list relationships'.
  $permissions['list relationships'] = array(
    'name' => 'list relationships',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'manage collection policy'.
  $permissions['manage collection policy'] = array(
    'name' => 'manage collection policy',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'manage critical edition'.
  $permissions['manage critical edition'] = array(
    'name' => 'manage critical edition',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition_advanced',
  );

  // Exported permission: 'manage deleted objects'.
  $permissions['manage deleted objects'] = array(
    'name' => 'manage deleted objects',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'manage islandora object lock'.
  $permissions['manage islandora object lock'] = array(
    'name' => 'manage islandora object lock',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_object_lock',
  );

  // Exported permission: 'manage lock duration'.
  $permissions['manage lock duration'] = array(
    'name' => 'manage lock duration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_object_lock_length',
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

  // Exported permission: 'manage own openid sites'.
  $permissions['manage own openid sites'] = array(
    'name' => 'manage own openid sites',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
    ),
    'module' => 'openid_provider',
  );

  // Exported permission: 'manage own openid_connect accounts'.
  $permissions['manage own openid_connect accounts'] = array(
    'name' => 'manage own openid_connect accounts',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'openid_connect',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'migrate collection members'.
  $permissions['migrate collection members'] = array(
    'name' => 'migrate collection members',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_basic_collection',
  );

  // Exported permission: 'modify critical editions'.
  $permissions['modify critical editions'] = array(
    'name' => 'modify critical editions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition_advanced',
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

  // Exported permission: 'modify object properties'.
  $permissions['modify object properties'] = array(
    'name' => 'modify object properties',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'modify workflow datastreams'.
  $permissions['modify workflow datastreams'] = array(
    'name' => 'modify workflow datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_workflow_rest',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'openid_connect set own password'.
  $permissions['openid_connect set own password'] = array(
    'name' => 'openid_connect set own password',
    'roles' => array(),
    'module' => 'openid_connect',
  );

  // Exported permission: 'publish button publish any content types'.
  $permissions['publish button publish any content types'] = array(
    'name' => 'publish button publish any content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any content types'.
  $permissions['publish button unpublish any content types'] = array(
    'name' => 'publish button unpublish any content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read critical editions'.
  $permissions['read critical editions'] = array(
    'name' => 'read critical editions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'islandora_critical_edition_advanced',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
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

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(),
    'module' => 'features',
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

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(),
    'module' => 'privatemsg',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
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

  // Exported permission: 'save islandora searches'.
  $permissions['save islandora searches'] = array(
    'name' => 'save islandora searches',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_saved_searches',
  );

  // Exported permission: 'search and replace with xquery'.
  $permissions['search and replace with xquery'] = array(
    'name' => 'search and replace with xquery',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_xquery',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
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

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
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

  // Exported permission: 'tag private messages'.
  $permissions['tag private messages'] = array(
    'name' => 'tag private messages',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unflag favourite_projects'.
  $permissions['unflag favourite_projects'] = array(
    'name' => 'unflag favourite_projects',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use CWRC'.
  $permissions['use CWRC'] = array(
    'name' => 'use CWRC',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_critical_edition',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
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

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'view CWRC datastreams'.
  $permissions['view CWRC datastreams'] = array(
    'name' => 'view CWRC datastreams',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_cwrc_document',
  );

  // Exported permission: 'view critical edition'.
  $permissions['view critical edition'] = array(
    'name' => 'view critical edition',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_critical_edition',
  );

  // Exported permission: 'view datastreams'.
  $permissions['view datastreams'] = array(
    'name' => 'view datastreams',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
  );

  // Exported permission: 'view entity'.
  $permissions['view entity'] = array(
    'name' => 'view entity',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cwrc_entities',
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

  // Exported permission: 'view field_research_space'.
  $permissions['view field_research_space'] = array(
    'name' => 'view field_research_space',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_level_collection'.
  $permissions['view field_top_level_collection'] = array(
    'name' => 'view field_top_level_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view image annotations'.
  $permissions['view image annotations'] = array(
    'name' => 'view image annotations',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_image_annotation',
  );

  // Exported permission: 'view objects'.
  $permissions['view objects'] = array(
    'name' => 'view objects',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_rest',
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

  // Exported permission: 'view open annotations'.
  $permissions['view open annotations'] = array(
    'name' => 'view open annotations',
    'roles' => array(
      'Orlando User' => 'Orlando User',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cwrc_entities',
  );

  // Exported permission: 'view own field_research_space'.
  $permissions['view own field_research_space'] = array(
    'name' => 'view own field_research_space',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_level_collection'.
  $permissions['view own field_top_level_collection'] = array(
    'name' => 'view own field_top_level_collection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view roles recipients'.
  $permissions['view roles recipients'] = array(
    'name' => 'view roles recipients',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'view saved reports'.
  $permissions['view saved reports'] = array(
    'name' => 'view saved reports',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_workflow_rest',
  );

  // Exported permission: 'view technical metadata'.
  $permissions['view technical metadata'] = array(
    'name' => 'view technical metadata',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'islandora_fits',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'DHSI 2014' => 'DHSI 2014',
      'Documentation' => 'Documentation',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'write privatemsg to roles'.
  $permissions['write privatemsg to roles'] = array(
    'name' => 'write privatemsg to roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_roles',
  );

  return $permissions;
}
