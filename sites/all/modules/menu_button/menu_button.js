/**
 * @file
 * Client-side behaviors for the menu_button module.
 */
(function ($) {
  Drupal.behaviors.menu_button = {
    attach: function (context, settings) {
      "use strict";

      // Loop through each menu button block widget added to the page.
      $('.block-menu-button', context).each(function (index) {
        var $block_wrapper = $(this);

        // Initially hide its contents.
        $block_wrapper.attr('data-state', 'collapsed');

        // Find its triggering element. Add an event listener to the triggering
        // element to hide/show the sub-menu on click.
        $block_wrapper.find('.menu_button_trigger').once('menu_button_add_trigger_listener').click(function () {
          // When this function runs, the current element (this) will be the
          // trigger, and $block_wrapper from the parent scope will be set to
          // the last $block_wrapper element encountered by JavaScript while the
          // page was being loaded, so we'll have to re-define it to be the
          // current element's closest parent that matches the selector
          // '.block-menu-button'.
          var $block_wrapper = $(this).closest('.block-menu-button');

          // If the block is currently collapsed, expand it.
          if ($block_wrapper.attr('data-state') === 'collapsed') {
            $block_wrapper.attr('data-state', 'expanded');
          }
          // Otherwise, collapse it. Note that its default state should be
          // collapsed, so we're using an "else" instead of an "elseif" so any
          // funky state values result in it being collapsed.
          else {
            $block_wrapper.attr('data-state', 'collapsed');
          }
        });
      });
    }
  };

})(jQuery);
