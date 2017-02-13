<?php

/**
 * @file
 * Display Suite 1 column template.
 */

// Find the correct logo and alt text to use for this slider item
$logo_uri = NULL;
$logo_alt = "";

if (!empty($field_featured_objects)) {
  if (isset($field_featured_objects[$language][0]['value'])) {
    $featitem = field_collection_item_load($field_featured_objects[$language][0]['value']);
    if ($featitem && !empty($featitem->field_image)) {
      $lang = $language;
      if (!array_key_exists($lang, $featitem->field_image)) $lang = LANGUAGE_NONE;

      $logo_uri = $featitem->field_image[$lang][0]['uri'];
      $logo_alt = $featitem->field_image[$lang][0]['alt'];
    }
  }
}

if ($logo_uri == NULL && !empty($field_logo)) {
  $logo_uri = $field_logo[0]['uri'];
  $logo_alt = $field_logo[0]['alt'];
}

if ($logo_uri == NULL) {
  $logo_uri = file_create_url(drupal_get_path('theme', 'de_theme') . '/img/project-carousel-default.png');
} else {
  $logo_uri = image_style_url('featured_project_carousel_image', $logo_uri);
}

$banner_img = NULL;
if (!empty($field_banner_image)) {
  $banner_img = file_create_url($field_banner_image[$language][0]['uri']);
}
if ($banner_img == NULL) {
  $banner_img = file_create_url(drupal_get_path('theme', 'de_theme') . '/img/new-banner.jpg');
}

?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix" data-background="<?php print $banner_img; ?>">

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<a href="<?php print url('node/' . $nid); ?>">
  <div class="field field-name-field-logo field-type-image field-label-hidden">
    <div class="field-items">
      <div class="field-item- even">
        <img typeof="foaf:Image" src="<?php print $logo_uri; ?>" alt="<?php print $logo_alt; ?>">
      </div>
    </div>
  </div>
</a>

<div class="field field-name-title field-type-ds field-label-hidden">
  <div class="field-items">
    <div class="field-item even" property="dc:title">
      <?php print $elements['title'][0]['#markup']; ?>
    </div>
  </div>
</div>

<div class="field field-name-body field-type-text-with-summary field-label-hidden">
  <div class="field-items">
    <div class="field-item even" property="content:encoded">
      <?php if (!empty($field_project_intro)) print strip_tags($elements['field_project_intro'][0]['#markup']); ?>
    </div>
  </div>
</div>

<div class="field field-name-node-link field-type-ds field-label-hidden">
  <div class="field-items">
    <div class="field-item even">
      <?php print $elements['node_link'][0]['#markup']; ?>
    </div>
  </div>
</div>

<?php //print $ds_content; ?>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
