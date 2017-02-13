<?php

/**
 * @file
 * Displays an iframe for a visualization.
 *
 * Available variables:
 * - $classes: A set of classes to apply to the iframe element.
 * - $url: The URL to use for the iframe source.
 */
?>
<div class="iframe-wrapper">
  <iframe class="<?php print $classes ?>" src="<?php print $url; ?>"></iframe>
</div>
<div class="fullscreen-link-wrapper">
  <a href="<?php print $url; ?>" target="_blank"><?php print t('Open fullscreen'); ?></a>
</div>
