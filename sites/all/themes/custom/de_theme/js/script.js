/**
 * @file
 * A JavaScript file for the theme.
 */

(function ($) {
  Drupal.behaviors.de_theme_cwrc_featured_projects = {
    attach: function (context, settings) {
      "use strict";

      $('.view-nodequeue-projects-featured', context).each(function (index) {

        var slickContainer = "de_theme_cwrc_featured_projects_slickify-processed";

        $(this).find('.view-content').once('de_theme_cwrc_featured_projects_slickify').slick();

        $(this).find('.view-content').once(slickContainer).on('beforeChange', function(event, slick, currentSlide, nextSlide) {
          setSlickBackground(nextSlide);
        });

        setTimeout(function() { setSlickBackground(0); }, 10);

        function setSlickBackground(currentSlide) {
          var slickC = $("." + slickContainer);
          var slideElem = slickC.find("[data-slick-index=" + currentSlide + "]").find('.node-project');

          slickC.parent().css('background-image', 'url(' + slideElem.data('background') + ')');
        }

      });
    }
  };

  Drupal.behaviors.de_theme_cwrc_homepage_slider = {
    attach: function (context, settings) {
      "use strict";

      $('.view-homepage-slider', context).each(function (index) {

        var slickContainer = "de_theme_cwrc_homepage_slider_slickify-processed";

        $(this).find('.view-content').once('de_theme_cwrc_homepage_slider_slickify').slick();

        $(this).find('.view-content').once(slickContainer).on('beforeChange', function(event, slick, currentSlide, nextSlide) {
          setSlickBackground(nextSlide);
        });
        setTimeout(function() { setSlickBackground(0); }, 10);

        function setSlickBackground(currentSlide) {
          var slickC = $("." + slickContainer);
          var slideElem = slickC.find("[data-slick-index=" + currentSlide + "]");
          var imgElem = slideElem.find('img.homepage-slider-background');
          slickC.parent().css('background-image', 'url(' + imgElem.attr('src') + ')');
        }

      });
    }
  };

  Drupal.behaviors.de_theme_cwrc_eap = {
    attach: function (context, settings) {
      "use strict";

      $('.associations-collapsible:not(.assoc-collapsible-processed)', context).each(function () {

        $(this).addClass('assoc-collapsible-processed');
        $('h2.collapsiblock a', $(this)).click(function(e) {
          if (!$(this).parent().hasClass("collapsiblockCollapsed")) {
            // Close it
            $(this).parent().addClass("collapsiblockCollapsed");
            $('div.content', $(this).parent().parent()).animate({
              height: 'hide',
              opacity: 'hide'
            }, parseInt(settings.collapsiblock.slide_speed,10));
          } else {
            // open it
            $(this).parent().removeClass('collapsiblockCollapsed');
            $('div.content', $(this).parent().parent()).animate({
              height: 'show',
              opacity: 'show'
            }, parseInt(settings.collapsiblock.slide_speed,10));
          }

          e.stopPropagation();
          return false;
        });
      });

    }
  };

  Drupal.behaviors.de_theme_cwrc_hamburger = {
    attach: function (context, settings) {
      "use strict";

      $('*[data-toggle=collapse]', context).click(function(e) {
        var target = $(this).data('target');

        if ($(this).hasClass("collapsed")) {
          // open it
          $(this).removeClass("collapsed");
          $("#" + target).removeClass("collapsed");
        } else {
          $(this).addClass("collapsed");
          $("#" + target).addClass("collapsed");
        }

        e.stopPropagation();
        return false;
      });

      $(window).resize(function() {
        var isMobile = $("button.navbar-toggle[data-target=main-navbar]").is(":visible");
        if (isMobile) {
          $("div#tabs").addClass("hamburger");
        } else {
          $("div#tabs").removeClass("hamburger");
        }
      });
    }
  };

  $(function() {
      $('.cwrc-search-wrapper .grid-layout li').matchHeight();
      $('.islandora-basic-collection-grid .grid-layout li').matchHeight();
      $('.islandora-solr-grid .solr-grid-field').matchHeight();
      $('.cwrc-project-homepage .group-footer .field-collection-container .field-items .field-item').matchHeight();
      $('.view-events .views-row').matchHeight();
      $('.views-row .slider-float').matchHeight();
      $('.front .homepage-news-event').matchHeight();
      $('.front .what-we-are-homepage').matchHeight();
      $('.main-prefix-section-wrapper .region').matchHeight();
  });



})(jQuery);
