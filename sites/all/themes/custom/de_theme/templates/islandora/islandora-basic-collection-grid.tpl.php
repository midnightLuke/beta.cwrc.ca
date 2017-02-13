<?php

/**
 * @file
 * islandora-basic-collection.tpl.php
 *
 * @TODO: needs documentation about file and variables
 */
?>

<div class="islandora islandora-basic-collection">
  <?php print render($order_by); ?>
  <div class="islandora-basic-collection-grid clearfix">
    <?php print render($collection_results); ?>
  </div>
</div>
