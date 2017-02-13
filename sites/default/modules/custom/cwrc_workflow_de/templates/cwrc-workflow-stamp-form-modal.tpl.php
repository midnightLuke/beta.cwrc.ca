<?php

/**
 * @file
 * Displays a workflow stamp modal.
 *
 * Available variables:
 * - $message: The workflow stamp message.
 * - $form: The workflow stamp form.
 */
?>
<div class="cwrc-workflow-stamp-form-modal remodal" data-remodal-id="cwrc-workflow-modal">
  <button data-remodal-action="close" class="remodal-close"></button>
  <h1>Add workflow stamp</h1>
  <div class="cwrc-workflow-modal-message">
    <?php print $message; ?>
  </div>
  <div class="cwrc-workflow-modal-form">
    <?php print render($form); ?>
  </div>
  <button data-remodal-action="cancel" class="remodal-cancel"><?php print t('Add later'); ?></button>
</div>
