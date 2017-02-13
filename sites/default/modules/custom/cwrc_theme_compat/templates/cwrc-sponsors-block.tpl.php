<?php

/**
 * @file
 * Displays a sponsors block.
 */
?>
<ul class="sponsors">
  <li class="sponsor-1"><img src="<?php print file_create_url(drupal_get_path('module', 'cwrc_theme_compat') . '/img/INN_CFI_ENB_2C_RGB.png'); ?>" alt="Canada Foundation for Innovation"></li>
  <li class="sponsor-2"><img src="<?php print file_create_url(drupal_get_path('module', 'cwrc_theme_compat') . '/img/sshrc.png'); ?>" alt="Social Sciences and Humanities Research Council of Canada"></li>
</ul>
<span class="more-sponsors"><?php print l(t('More Sponsors'), 'sponsors'); ?></span>
