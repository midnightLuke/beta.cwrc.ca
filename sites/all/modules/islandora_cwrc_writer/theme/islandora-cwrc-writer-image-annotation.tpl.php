<?php
/**
 * @file
 * Renders the Image Annotation portion of the CWRC-Writer eastern panel.
 *
 * Variables available:
 * - $canvas: The shared canvases.
 * - $dialog_box: The dialog box for adding new Image Annotations, it is
 *   initially hidden.
 * - $text_image_link_dialog_box: The dialog box for adding new text to image
 *   Links, it is initially hidden.
 * - $text_image_link_button: The button used to trigger opening of the text to
 *   image dialog box, it is initially hidden. Gets moved by javascript code
 *    to the appropriate location
 */
?>
<?php if (user_access(ISLANDORA_IMAGE_ANNOTATION_CREATE)): ?>
  <button id="islandora-image-annotation-create-annotation-button"><?php print t('Annotate'); ?></button>
<?php endif; ?>
<div id="islandora-image-annotation">
  <?php print $canvas; ?>
  <?php print $dialog_box; ?>
  <?php print $text_image_link_dialog_box; ?>
</div>
<?php print $text_image_link_button; ?>
