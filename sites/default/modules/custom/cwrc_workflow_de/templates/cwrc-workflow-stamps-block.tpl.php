<?php

/**
 * @file
 * Displays a block with a list of workflow stamps.
 */
?>
<div class="<?php echo $classes; ?>">
  <?php foreach ($stamps as $stamp) { ?>
    <?php print render($stamp); ?>
  <?php } ?>

  <div class="cwrc-workflow-history-link-wrapper">
    <a href="<?php print url('islandora/object/' . $object->id . '/view/history'); ?>">
      <?php print t('See all workflow stamps'); ?>
    </a>
  </div>
</div>
