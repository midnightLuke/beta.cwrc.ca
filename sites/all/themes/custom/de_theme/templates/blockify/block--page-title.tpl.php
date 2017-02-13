<?php
/**
 * This is the only way that will reliably change the search title for this
 * block.
 */
?>
<h1 id="page-title" class="title">
  <?php if (current_path() == 'islandora/search') {
      $parameters = drupal_get_query_parameters();
      if (isset($parameters['display'])
      && $parameters['display'] == 'xquery') {
        $page_title = t('Find and Replace');
      }
    } ?>
  <?php print $page_title; ?>
</h1>
