// (function ($, Drupal, window, document) {

jQuery(function($) {
    $('.field-name-body table tr:even').addClass('even');
    $('.field-name-body table tr:odd').addClass('odd');
});


// (function ($) {
//     $('table tr:even').addClass('even');
//     $('table tr:odd').addClass('odd');
// })(jQuery);


  ssm.addState({
    minWidth: 768,
    onEnter: function(){
      $('.landing-page.grid-display .views-row:nth-child(3n+3)').addClass('row-end-third');
    },
    onLeave: function(){
      $('.landing-page.grid-display .views-row:nth-child(3n+3)').removeClass('row-end-third');
    }
  });

  ssm.addState({
    minWidth: 960,
    onEnter: function(){
      $('.landing-page.grid-display .views-row:nth-child(4n+4)').addClass('row-end-fourth');
    },
    onLeave: function(){
      $('.landing-page.grid-display .views-row:nth-child(4n+4)').removeClass('row-end-fourth');
    }
  });

// })(jQuery, Drupal, this, this.document);
