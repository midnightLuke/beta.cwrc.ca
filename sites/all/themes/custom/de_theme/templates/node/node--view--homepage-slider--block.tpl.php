<?php
/**
 * Created by PhpStorm.
 * User: admin
 * Date: 2016-05-12
 * Time: 1:43 PM
 */


$bgimg = file_create_url(drupal_get_path('theme', 'de_theme') . '/img/new-banner.jpg');
if (!empty($field_banner_image)) {
  $bgimg = file_create_url($field_banner_image[0]['uri']);
}

$link_path = $field_link[0]['url'];
$link_text = $field_link[0]['title'];

?>

<img src="<?php print $bgimg; ?>" class="homepage-slider-background" style="display:none;">

<div class="homepage-slider-left slider-float">

  <?php if (!empty($field_logo_image)): ?>
    <?php print l(render($content['field_logo_image']), $link_path, array('html' => TRUE)); ?>
  <?php endif; ?>

  <?php print render($content['field_text']); ?>

</div>


<div class="homepage-slider-right slider-float">
  <?php print render($content['field_image']); ?>
    <div class="image-information">
      <?php print render($content['field_description']); ?>
      <div class="cta-btn"><?php print l($link_text, $link_path); ?></div>
    </div>
</div>

