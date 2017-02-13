<?php
// Render the image as the background of a div.
$item = reset($items);
$path = file_create_url($item['#item']['uri']);
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?> style="background-image: url('<?php print $path; ?>')">
  <?php if($element['#view_mode'] == "homepage_slider" && !empty($element['#object']->field_description)): ?>
    <?php print $element['#object']->field_description[LANGUAGE_NONE][0]['value']; ?>
  <?php endif; ?>
</div>
