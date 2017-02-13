<?php
/**
 * @file
 * Template file to style output.
 */
?>

<div class="islandora-object islandora">
  <?php if(isset($viewer)): ?>
    <div id="book-viewer">
      <?php print $viewer; ?>
    </div>
  <?php endif; ?>

  <?php if($display_metadata === 1): ?>
    <div class="islandora-object-metadata islandora-book-metadata">
      <?php print $description; ?>
      <?php if($parent_collections): ?>
    <div>
      <h2><?php print t('In collections'); ?></h2>
      <ul>
        <?php foreach ($parent_collections as $collection): ?>
          <li><?php print l($collection->label, "islandora/object/{$collection->id}"); ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
    <?php endif; ?>
    </div>
  <?php endif; ?>

</div>