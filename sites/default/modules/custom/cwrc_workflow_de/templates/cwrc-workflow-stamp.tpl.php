<?php

/**
 * @file
 * Displays an individual workflow stamp.
 */
?>
<div class="<?php print $classes; ?>">
  <div class="cwrc-workflow-stamp-row activity-category">
    <span class="cwrc-workflow-content"><?php print $activity_category; ?></span>
  </div>
  <div class="cwrc-workflow-stamp-row cwrc-workflow-activity-stamp">
    <span class="cwrc-workflow-label"><?php print t('Stamp'); ?></span>
    <span class="cwrc-workflow-content"><?php print $activity_stamp; ?></span>
  </div>
  <div class="cwrc-workflow-stamp-row cwrc-workflow-stamp-date-time">
    <span class="cwrc-workflow-label"><?php print t('Date/time'); ?></span>
    <span class="cwrc-workflow-content"><?php print $stamp_date_time; ?></span>
  </div>
  <div class="cwrc-workflow-stamp-row cwrc-workflow-stamp-user">
    <span class="cwrc-workflow-label"><?php print t('User'); ?></span>
    <span class="cwrc-workflow-content"><?php print $stamp_user; ?></span>
  </div>
  <div class="cwrc-workflow-stamp-row cwrc-workflow-activity-status">
    <span class="cwrc-workflow-label"><?php print t('Status'); ?></span>
    <span class="cwrc-workflow-content"><?php print $activity_status; ?></span>
  </div>
  <?php if ($activity_note) { ?>
    <div class="cwrc-workflow-stamp-row cwrc-workflow-activity-note">
      <span class="cwrc-workflow-label"><?php print t('Note'); ?></span>
      <span class="cwrc-workflow-content"><?php print $activity_note; ?></span>
    </div>
  <?php } ?>
  <?php if ($assigned_message_recipient) { ?>
    <div class="cwrc-workflow-stamp-row cwrc-workflow-assigned-message-recipient">
      <span class="cwrc-workflow-label"><?php print t('Assigned to'); ?></span>
      <span class="cwrc-workflow-content"><?php print $assigned_message_recipient; ?></span>
    </div>
  <?php } ?>
  <?php if ($assigned_category) { ?>
    <div class="cwrc-workflow-stamp-row cwrc-workflow-assigned-category">
      <span class="cwrc-workflow-label"><?php print t('Assigned category'); ?></span>
      <span class="cwrc-workflow-content"><?php print $assigned_category; ?></span>
    </div>
  <?php } ?>
  <?php if ($assigned_note) { ?>
    <div class="cwrc-workflow-stamp-row cwrc-workflow-assigned-note">
      <span class="cwrc-workflow-label"><?php print t('Assigned note'); ?></span>
      <span class="cwrc-workflow-content"><?php print $assigned_note; ?></span>
    </div>
  <?php } ?>
</div>
