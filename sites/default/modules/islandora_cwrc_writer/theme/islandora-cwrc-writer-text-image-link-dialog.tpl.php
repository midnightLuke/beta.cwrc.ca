<?php

/**
 * @file
 * The dialog box used to create new Text to Image Annotations.
 *
 * Variables available:
 * - $annotation_icons: The images to use for selecting rectangle, circle,
 *   polygon display shapes.
 */
?>
<div id="islandora-cwrc-writer-text-image-link-dialog" style="display: none;">
  <label><?php print t('Description:'); ?></label>
  <input name="description" type="text" />
  <div id="islandora-cwrc-writer-text-image-link-dialog-accordion">
    <h3><?php print t('Create New'); ?></h3>
    <div>
      <div class="icons">
        <?php print $annotation_icons; ?>
      </div>
      <hr/>
      <!-- The title is hard coded to "Text image annotation" -->
      <input name="title" type="text" style="display: none;" value="" />
      <label><?php print t('Type:'); ?></label>
      <?php print $type; ?>
      <div class="color">
        <label><?php print t('Color:'); ?></label>
        <input name="color" type="hidden" value="#91843c" class="color-picker" size="7" />
      </div>
      <div class="stroke">
        <label><?php print t('Stroke Width:'); ?></label>
        <?php print $stroke_width; ?>
      </div>
      <!-- The Annotation is coded to be the highlighted text. -->
      <textarea name="text" style="display: none;" cols="40" rows="5"></textarea>
      <!-- The Canvas this annotation belongs to. -->
      <input name="canvas" type="hidden" />
      <!-- The Shape to use. -->
      <input name="shape" type="hidden" />
    </div>
    <h3><?php print t('Choose Existing'); ?></h3>
    <div>
      <label><?php print t('Choose Existing:'); ?></label>
      <select name="existing">
        <option value="volvo">Volvo</option>
        <option value="saab">Saab</option>
        <option value="mercedes">Mercedes</option>
        <option value="audi">Audi</option>
      </select>
    </div>
  </div>
</div>
