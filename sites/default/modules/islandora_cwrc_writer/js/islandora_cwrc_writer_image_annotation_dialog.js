/*jshint browser: true*/
/*global jQuery, Drupal, UUID, IIAUtils*/
/**
 * @file
 * @todo Document.
 */
(function ($) {
  'use strict';

  /**
   *  Wrap the Image Annotation Dialogs in a div.
   *
   *  Makes the Islandora Image Annotation Dialog look consistent with the other
   *  CWRC-Writer dialog boxes.
   *
   *  CWRC-Writer styles expects that all dialogs be wrapped in a
   *  <div class="cwrc"/> element.
   */
  Drupal.behaviors.islandoraCWRCDialogs = {
    attach: function (context, settings) {
      /**
       * The DOM elements that represents the dialog element.
       * @type {[string]}
       */
      var dialogs = [
        '#islandora-image-annotation-dialog',
        '#islandora-cwrc-writer-text-image-link-dialog'
      ];
      $.each(dialogs, function (index, base) {
        $(base, context).once('islandoraCWRCImageAnnotationDialog ', function () {
          $(this).on('dialogcreate', function (event, ui) {
            $(base).parent('.ui-dialog').wrap('<div class="cwrc" />');
          });
        });
      });
    }
  };

  /**
   * Initialize the Create Annotation Dialog Box.
   *
   * We can only have one Create Annotation Dialog Box per page.
   */
  Drupal.behaviors.islandoraTextImageLinkDialog = {
    attach: function (context, settings) {
      /**
       * The DOM element that represents the Singleton Instance of this class.
       * @type {string}
       */
      var base = '#islandora-cwrc-writer-text-image-link-dialog';
      $(base, context).once('islandoraTextImageLinkDialog', function () {
        // Initialize the accordion view.
        var $accordion = $('#islandora-cwrc-writer-text-image-link-dialog-accordion');
        $accordion.accordion();
        // We can then override the show / save functionality.
        Drupal.IslandoraImageAnnotationDialog[base] = new Drupal.IslandoraImageAnnotationDialog(base, settings.islandoraImageAnnotationDialog);
        // Override the show function to handle the Text to Image use case.
        Drupal.IslandoraImageAnnotationDialog[base].show = function (data) {
          var that = this,
            $dialog = $(base),
            result = data.writer.utilities.isSelectionValid();
          if (result === data.writer.NO_SELECTION) {
            data.writer.dialogManager.show('message', {
              title: Drupal.t('Error'),
              msg: Drupal.t('Please select some text before adding a text to image link.'),
              type: 'error'
            });
            return;
          }
          $dialog.dialog($.extend(this.defaultDialogProperties, {
            title: Drupal.t('Text/Image Annotation'),
            height: 400,
            open: function () {
              var annotations, canvas, $existing;
              // Clear the form to be safe.
              that.clearForm();
              // Populate the form with the given annotation.
              that.setFormValues({
                title: 'Text image annotation',
                type: 'TextImageLink',
                text: data.query,
                shape: 'rectangle'
              });
              // Populate the Existing annotations field.
              $existing = $dialog.find('select[name="existing"]');
              $existing.html('');
              annotations = Drupal.IslandoraImageAnnotation.getInstance().getAnnotationsByType('comment');
              $.each(annotations, function (index, annotation) {
                var option = $('<option />', {
                  value: annotation.id
                }).html(annotation.body.value);
                $existing.append(option);
              });
              // Initialize the Canvas.
              canvas = Drupal.IslandoraImageAnnotationCanvas.getInstance();
              canvas.startAnnotating(canvas.getCurrentCanvas(), that.getAnnotationProperties);
              // Resize the accordion.
              $accordion.accordion('refresh');
            },
            close: function () {
              // Stop all annotations.
              var canvas = Drupal.IslandoraImageAnnotationCanvas.getInstance();
              canvas.stopAnnotating(canvas.getCurrentCanvas());
              // Reset to defaults.
              that.clearForm();
            },
            buttons: [{
              text: 'Save',
              // Assumes only one canvas with a valid 'canvas' attribute.
              click: function () {
                var values, annotation, uuid;
                values = that.getFormValues();
                // Create New.
                if ($accordion.accordion('option', 'active') === 0) {
                  // Also the user must have actually marked up the image.
                  if (values.shapes.length < 1) {
                    alert(Drupal.t('You must draw a shape around the target.'));
                    return 0;
                  }

                  // Set default type if not specified.
                  values.type = (values.type === '' || values.type === null) ? Drupal.t('TextImageLink') : values.type;

                  // Create RDFa representing the current annotation, all the
                  // parameters are required. Except entityID, entityLabel, it also
                  // generates identifiers for the annotation and it's content.
                  annotation = that.createAnnotation(values);
                  uuid = jQuery(annotation).attr('about');
                  Drupal.IslandoraImageAnnotation.on('processedAnnotation', function (event, annotation) {
                    if (annotation.id === uuid) {
                      data.writer.tagger.finalizeEntity('textimagelink', {
                        cwrcInfo: {
                          repository: 'cwrc',
                          name: data.query,
                          id: 'cwrc_' + IIAUtils.urnComponents(annotation.id).nss,
                          description: values.description
                        },
                        attributes: annotation
                      });
                      $(this).off(event);
                    }
                  });
                  // The ingest will eventually trigger the 'processAnnotation'
                  // event above.
                  that.ingestAnnotation(annotation);
                } else {
                  // Use Existing.
                  annotation = Drupal.IslandoraImageAnnotation.getInstance().getAnnotation(values.existing);
                  // @todo Used to remove unused values?
                  data.writer.tagger.finalizeEntity('textimagelink', {
                    cwrcInfo: {
                      repository: 'cwrc',
                      name: data.query,
                      id: 'cwrc_' + IIAUtils.urnComponents(annotation.id).nss,
                      description: values.description
                    },
                    attributes: annotation
                  });
                }
                $dialog.dialog('close');
              }
            }, {
              text: 'Cancel',
              click: function () {
                $dialog.dialog('close');
              }
            }]
          }));
        };
      });
    }
  };
}(jQuery));
