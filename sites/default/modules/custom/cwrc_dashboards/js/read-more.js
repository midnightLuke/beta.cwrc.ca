/**
 * @file
 * Client-side scripts to display read-more rows.
 */

(function ($) {
  Drupal.behaviors.cwrcDashboardsReadMore = {
    attach: function (context, settings) {
      // Markup for "Show all" button.
      var show_more = '<a class="btn read-more-button hidden" style="color: white; margin-top: 1em;" href="#">' + Drupal.t('Show all') + '</a>';

      // Grab any tables marked as "read-more" and hide rows after the 5th.
      $('table.read-more').once('read-more', function () {
        var rows = $(this).find('tbody tr');

        // This should only apply if there are more than 5 rows.
        if (rows.length > 5) {

          // Get rows to hide and hide them initially.
          var hidden = rows.splice(5, rows.length - 1);
          $(hidden).each(function () {
            $(this).addClass('read-more-row');
            $(this).hide();
          });

          // Create "Show all" button and add after table.
          var show_more_element = $(this).after(show_more).siblings('.read-more-button');

          // Add click handler for the "Show all" button.
          $(show_more_element).click(function (e) {
            e.preventDefault();

            // Get rows to show/hide.
            var rows = $(this).siblings('table.read-more').find('tr.read-more-row');

            // Rows are hidden, show them.
            if ($(this).hasClass('hidden')) {
              rows.show();
              $(this).removeClass('hidden');
              $(this).html(Drupal.t('Show less'));

            // Rows are shown, hide them.
            }
else {
              rows.hide();
              $(this).addClass('hidden');
              $(this).html(Drupal.t('Show all'));
            }
          });

          // When someone clicks the "select all" checkbox, unhide all the rows
          // so they know _everything_ is selected.
          $('.select-all', this).click(function (e) {
            $(this).closest('table.read-more').find('tr.read-more-row').show();
            $(show_more_element).removeClass('hidden');
            $(show_more_element).html(Drupal.t('Show less'));
          });
        }
      });
    }
  };
})(jQuery);
