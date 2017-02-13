/*jshint browser: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Hack the settings to use the document in the fragment identifier's source.
 */
(function ($) {
  'use strict';
  // Since we don't know server side what the fragment identifier is we must
  // correct the settings here, so we load the appropriate source object. This
  // must run before Drupal.attachBehaviours() of image annotation.
  function get_settings(widget) {
    var document, index, source, settings;
    document = (window.location.hash !== "") ? window.location.hash.replace(/#/g, '') : Drupal.settings.CWRCWriter.documents[0];
    index = $.inArray(document, Drupal.settings.islandoraCWRCWriterImageAnnotation.documents);
    if (Drupal.settings.islandoraCWRCWriterImageAnnotation.sources[index] !== undefined) {
      source = Drupal.settings.islandoraCWRCWriterImageAnnotation.sources[index];
      settings = Drupal.settings.islandoraCWRCWriterImageAnnotation[source];
      return settings[widget];
    }
    // use the defaults.
    return Drupal.settings[widget];
  }
  // We only do this nonsense for the Image Annotation.
  $.each(['islandoraImageAnnotation', 'islandoraImageAnnotationCanvas', 'islandoraImageAnnotationList', 'islandoraImageAnnotationDialog'],
    function (index, widget) {
      var originalAttach = Drupal.behaviors[widget].attach;
      Drupal.behaviors[widget].attach = function () {
        Drupal.settings[widget] = get_settings(widget);
        originalAttach.apply(this, arguments);
      };
    });
}(jQuery));
