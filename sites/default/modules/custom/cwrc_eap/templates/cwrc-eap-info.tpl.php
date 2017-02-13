<?php

/**
 * @file
 * Displays a piece of EAP information.
 *
 * Available variables:
 * - $label: HTML for a label.
 * - $elements: A render array of elements to display.
 */
?>
<div class="info-content">
  <h4 class="info-label"><?php print $label ?></h4>
  <?php print render($elements); ?>
</div>
