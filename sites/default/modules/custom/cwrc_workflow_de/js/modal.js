/**
 * @file
 * Client-side script to open a remodal diagram.
 */

(function ($) {
  Drupal.behaviors.cwrcWorkflowStampFormModal = {
    attach: function (context) {

      // Open the remodal dialog.
      $(document).ready(function () {
        var inst = $('[data-remodal-id=cwrc-workflow-modal]').remodal();
        inst.open();
      });

    }
  };
})(jQuery);
