<?php

/**
 * @file
 * Display a "What We Are Writing" or "What We Are Collecting" block.
 */
?>
<div class="what-block">
  <div class="icon-<?php print $icon ?>"></div>
  <?php foreach ($items as $item) { ?>
    <div class="item">
      <div class="label"><?php print render($item['label']); ?></div>
      <div class="date"><?php print render($item['date']); ?></div>
    </div>
  <?php } ?>
</div>
