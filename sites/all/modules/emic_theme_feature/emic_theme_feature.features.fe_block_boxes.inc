<?php
/**
 * @file
 * emic_theme_feature.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function emic_theme_feature_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Featured Links Frontpage';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'featured_links';
  $fe_block_boxes->body = '<ul>
<li class="editions"><a href="/islandora/search/RELS_EXT_hasModel_uri_mt:&quot;criticalEditionContainerCModel&quot;?sort=fgs_label_ss%20asc"></a></li>
<li class="coop"><a href="/co-op"></a></li>
<li class="workbench"><a href="/workbench"></a></li>
</ul>';

  $export['featured_links'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer Logo\'s and Info';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_content';
  $fe_block_boxes->body = '<div id="footer-logo">&nbsp;</div><div class="footer-info">
<div class="footer-left">
<p>EMiC is funded by a Strategic Knowledge Cluster grant from the <a href="http://www.sshrc.ca/">Social Sciences and Humanities Research Council of Canada</a>.</p><p class="cc"><a class="cc-img" href="http://creativecommons.org/licenses/by-nc-nd/4.0/" rel="license"><img alt="Creative Commons License" src="http://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" style="border-width:0" /></a> Unless indicated otherwise, editions hosted by the Modernist Commons are licensed under:<br /><br /><a href="http://creativecommons.org/licenses/by-nc-nd/4.0/" rel="license">Creative Commons Attribution-    NonCommercial-NoDerivatives 4.0 International License</a></p>
</div>
<div>
<div class="footer-right">&nbsp;</div>
<div class="footer-right footer-right-second">&nbsp;</div>
</div>
</div><p>&nbsp;</p>';

  $export['footer_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Social Links';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'social_links';
  $fe_block_boxes->body = '<ul><li class="fbook">&nbsp;</li><li class="twit">&nbsp;</li><li class="rss">&nbsp;</li></ul>';

  $export['social_links'] = $fe_block_boxes;

  return $export;
}
