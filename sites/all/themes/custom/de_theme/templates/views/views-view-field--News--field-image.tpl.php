<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

$display = $view->current_display;

$default_img = drupal_get_path('theme', 'de_theme') . '/img/news-default.png';
if ($display != 'page') {
  $default_img = drupal_get_path('theme', 'de_theme') . '/img/news-default-lrg.png';
}

?>
<?php $check = trim($output); if (!empty($check)) { ?>
  <?php print $output; ?>
<?php } else { ?>
  <?php
    $path = $default_img;
    $image = array(
      'path' => $path,
      'alt' => $row->node_title,
      'width' => '645',
      'height' => '345',
      'attributes' => array('typeof' => 'foaf:Image'),
    ); ?>
  <div class="field field-name-field-image field-type-image field-label-hidden">
    <div class="field-items">
      <div class="field-item even" rel="og:image rdfs:seeAlso" resource="<?php print file_create_url($path); ?>">
        <?php print theme_image($image); ?>
      </div>
    </div>
  </div>
<?php } ?>
