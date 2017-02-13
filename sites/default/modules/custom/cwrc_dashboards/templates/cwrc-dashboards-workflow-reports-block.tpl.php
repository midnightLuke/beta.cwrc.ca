<?php

/**
 * @file
 * Display a list of workflow reports.
 */
if (count($reports) > 0) { ?>
  <ul class="user-workflow-report-list lists-with-actions">
    <?php foreach ($reports as $report) { ?>
      <li><span class="txt-item-in-list"><?php echo $report['view']; ?></span>
      <?php if (isset($report['edit']) || isset($report['delete'])) { ?>
        <ul class="actions-list-group">
          <?php if ($report['edit']) { ?>
            <li class="actions-list-group-item action-edit">
              <a href="<?php echo $report['edit']; ?>"><span class="edit-icon no-txt"></span><span class="txt-icon"><?php echo t('Edit report'); ?></span></a>
            </li>
          <?php } ?>
          <?php if ($report['delete']) { ?>
            <li class="actions-list-group-item action-delete">
              <a href="<?php echo $report['delete']; ?>"><span class="delete-icon no-txt"></span><span class="txt-icon"><?php echo t('Delete report'); ?></span></a>
            </li>
          <?php } ?>
        </ul>
      <?php } ?>
      </li>
    <?php } ?>
  </ul>
<?php } else { ?>
  <span class="no-results"><?php print t('No reports available'); ?></span>
<?php } ?>

<?php if ($admin_access) { ?>
  <div class="admin-access-wrapper">
    <a href="<?php print url('islandora_workflow_rest/reports'); ?>">
      <?php print t('Workflow report admin'); ?>
    </a>
  </div>
<?php } ?>
