<?php

/**
 * @file
 * Displays an EAP material.
 *
 * Available variables:
 * - $classes: A string of classes to apply to the material.
 * - $image: An image representing the material.
 * - $pid: The Fedora object ID of the material.
 * - $label: A label representing the material.
 * - $summary: A summary of the material.
 */
?>
<div class="<?php print $classes ?>">
  <?php if ($image) { ?>
    <div class="image">
      <div class="img-wrapper">
        <a href="<?php print url('islandora/object/' . $pid); ?>"><?php print $image; ?></a>
      </div>
    </div>
  <?php } else { ?>
    <div class="no-image"></div>
  <?php } ?>
  <div class="text-wrapper">
    <div class="label">
      <a href="<?php print url('islandora/object/' . $pid); ?>"><?php print $label; ?></a>
    </div>
    <?php if ($summary) { ?>
      <div class="summary">
        <?php print truncate_utf8($summary, 200, TRUE, TRUE); ?>
      </div>
    <?php } ?>
  </div>
</div>
