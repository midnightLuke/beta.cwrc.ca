<?php

/**
 * @file
 * Display a user's dashboard lists.
 */
?>
<div class="heading-before-list my-lists"><h2><?php print t('My Lists'); ?></h2>
<span class="new-bookmark"><?php print l(t('New list'), 'islandora-bookmark/add'); ?></span></div>
<ul class="user-owned-bookmark-lists-list lists-with-actions">
  <?php if (count($owned) == 0) { ?>
    <span class="no-results"><?php print t("You don't have any bookmark lists yet."); ?></span>
  <?php } ?>
  <?php foreach ($owned as $list) { ?>
    <li>
      <span class="bookmark-list-view txt-item-in-list"><?php print l($list['listname'], 'islandora-bookmark/listid/' . $list['listid'] . '/view'); ?></span>
      <span class="bookmark-list-count txt-item-in-list">(<?php print $list['num_items']; ?>)</span>
      <ul class="actions-list-group">
        <li class="actions-list-group-item action-edit"><?php print l(t('<span class="edit-icon no-txt"></span>') . '<span class="txt-icon">Edit list</span>', 'islandora-bookmark/listid/' . $list['listid'] . '/manage', array('html' => TRUE)); ?></li>
        <li class="actions-list-group-item action-delete"><?php print l(t('<span class="delete-icon no-txt"></span>') . '<span class="txt-icon">Delete list</span>', 'islandora-bookmark/delete-bookmark/' . $list['listid'], array('html' => TRUE)); ?></li>
      </ul>
    </li>
  <?php } ?>
</ul>

<div class="heading-before-list shared-w-me"><h2><?php print t('Shared with me'); ?></h2></div>
<ul class="user-shared-bookmark-lists-list lists-with-actions">
  <?php if (count($shared) == 0) { ?>
    <span class="no-results"><?php print t('No bookmark lists have been shared with you yet.'); ?></span>
  <?php } ?>
  <?php foreach ($shared as $list) { ?>
    <li>
      <span class="bookmark-list-view"><?php print l($list['listname'], 'islandora-bookmark/listid/' . $list['listid'] . '/view'); ?></span>
      <span class="bookmark-list-count">(<?php print $list['num_items']; ?>)</span>
    </li>
  <?php } ?>
</ul>
