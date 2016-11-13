// $Id$

(function($) {
  Drupal = Drupal || {};
  Drupal.CTools = Drupal.CTools || {};
  Drupal.CTools.AJAX = Drupal.CTools.AJAX || {};
  Drupal.CTools.AJAX.commands = Drupal.CTools.AJAX.commands || {};

  Drupal.CTools.AJAX.commands.addClass = function(data) {
    $(data.selector).addClass(data.data);
    Drupal.attachBehaviors($(data.selector));
  };

  Drupal.CTools.AJAX.commands.removeClass = function(data) {
    $(data.selector).removeClass(data.data);
    Drupal.attachBehaviors($(data.selector));
  };
})(jQuery);
