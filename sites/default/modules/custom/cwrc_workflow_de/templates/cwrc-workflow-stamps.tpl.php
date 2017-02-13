<?php

/**
 * @file
 * Displays a list of workflow stamps.
 */
?>
<div class="<?php echo $classes; ?>">
  <?php foreach ($stamps as $stamp) { ?>
    <?php print render($stamp); ?>
  <?php } ?>
</div>
