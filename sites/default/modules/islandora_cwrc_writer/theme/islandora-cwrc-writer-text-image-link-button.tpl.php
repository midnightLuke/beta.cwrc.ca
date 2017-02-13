<?php

/**
 * @file
 * The Button used to open the text to image linking dialog box.
 *
 * Variables available:
 * - $icon: The image to use for the text to image linking button.
 */
?>
<a id="editor_addTextImageLink" style="display: none;" class="mceButton wideButton mceButtonEnabled addtextimganno" title="<?php t('Tag Text Annotation'); ?>" aria-labelledby="editor_addTextImageLink" onmousedown="return false;" href="javascript:;" role="button" tabindex="-1">
  <span class="mceIcon wideButton">
    <?php print $icon; ?>
  </span>
  <span class="mceVoiceLabel mceIconOnly" id="editor_schemaTagsButton_voice" style="display: none;"><?php t('Text Image Linking'); ?></span>
</a>