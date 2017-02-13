/*jshint browser: true*/
/*global jQuery, Drupal, setupLayoutAndModules, CwrcApi:true*/
/**
 * @file
 * Loads the CWRC-Writer.
 */
/**
 * CWRC-Writer global callback used to configure the CWRC-Writer.
 *
 * @param Writer
 * @param Delegator
 */
Drupal.CWRCWriter = Drupal.CWRCWriter || {};
(function ($) {
  'use strict';

  // Triggers the loading of CWRC-Writer if the script is not present, we do
  // this as a behaviour as Drupal doesn't allow us to set data attributes with
  // the.
  Drupal.behaviors.cwrcWriterLoad = {
    attach: function (context, settings) {
      var script;
      if ($('script[data-main]').length === 0) {
        // We have to set the height explicitly since the CWRC-Writer assumes it
        // has the full body.
        $('#cwrc_wrapper').height(1000);
        // We can't use jQuery to create the element since all of jQuery's
        // insertion methods use a domManip function.
        script = document.createElement('script');
        script.type = 'text/javascript';
        script.src = '/sites/all/libraries/CWRC-Writer/src/js/lib/require/require.js';
        script.setAttribute('data-main', '/sites/all/libraries/CWRC-Writer/src/js/config.js');
        document.head.appendChild(script);
      }
    }
  };

  // Attach behavior to the select field in the header so the user can change
  // documents.
  Drupal.behaviors.cwrcWriterDocumentSelect = {
    attach: function (context, settings) {
      // @todo use once here.
      var $select = $('#islandora-cwrc-document-select');
      if (!$select.hasClass('processed')) {
        // Any time this element changes reload the document.
        $select.change(function (e) {
          if (Drupal.CWRCWriter.writer !== undefined) {
            Drupal.CWRCWriter.writer.fileManager.loadDocument($('option:selected', this).val());
          }
        });
        $select.addClass('processed');
      }
    }
  };
  // This handle the navigation links, and makes use of the select field for
  // updating the document.
  Drupal.behaviors.cwrcWriterDocumentNavigation = {
    attach: function (context, settings) {
      // @todo use once here.
      var $navigation = $('#islandora-cwrc-document-nav'),
        $select = $('#islandora-cwrc-document-select');
      // Handle the navigation links.
      if (!$navigation.hasClass('processed')) {
        // Update the disable class based on the value of the select field.
        $select.change(function (e) {
          var $selected = $('option:selected', this);
          $('li a', $navigation).removeClass('disabled');
          if ($selected.is('option:last-child')) {
            $('li.next a', $navigation).addClass('disabled');
          }
          if ($selected.is('option:first-child')) {
            $('li.prev a', $navigation).addClass('disabled');
          }
        });
        $('li.prev a', $navigation).click(function (event) {
          $('option:selected', $select).prev().attr('selected', 'selected');
          $select.change();
          event.preventDefault();
        });
        $('li.next a', $navigation).click(function (event) {
          $('option:selected', $select).next().attr('selected', 'selected');
          $select.change();
          event.preventDefault();
        });
        $navigation.addClass('processed');
      }
    }
  };
}(jQuery));

/**
 * CWRC-Writer global callback used to configure the CWRC-Writer.
 *
 * @param {jQuery} $
 * @param Writer
 * @param Delegator
 */
// @ignore style_camel_case:function
function cwrcWriterInit($, Writer, Delegator) {
  'use strict';
  var writer, config;
  // Replace the CwrcAPI with our own constructor which can handle how we
  // deal with entities.
  CwrcApi = Drupal.CWRCWriter.api.CwrcApi;

  config = Drupal.settings.CWRCWriter;
  config.id = 'editor';
  config.delegator = Delegator;
  writer = new Writer(config);
  // We have to replace the baseUrl after object construction since it ise
  // hard-coded.
  writer.baseUrl = config.baseUrl;
  // Hold onto a reference for safe keeping.
  Drupal.CWRCWriter.writer = writer;
  writer.event('writerInitialized').subscribe(function (writer) {
    // When we change the schema we should update the document.
    writer.event('schemaChanged').subscribe(function (schemaId) {
      $.ajax({
        url: writer.baseUrl + 'editor/documents/' + writer.currentDocId +'/schema',
        type: 'POST',
        data: writer.schemaManager.schemas[schemaId],
        error: function() {
          writer.dialogManager.show('message', {
            title: 'Error',
            msg: 'An error occurred while trying to change the documents default schema.',
            type: 'error'
          });
        }
      });
      writer.schemaManager.loadSchema(schemaId, false, function() {
        var defaultTEI =
          '<TEI xmlns="http://www.tei-c.org/ns/1.0">' +
          '<teiHeader>' +
          '<fileDesc>' +
          '<titleStmt>' +
          '<title></title>' +
          '</titleStmt>' +
          '<publicationStmt>' +
          '<p/>' +
          '</publicationStmt>' +
          '<sourceDesc>' +
          '<p></p>' +
          '</sourceDesc>' +
          '</fileDesc>' +
          '</teiHeader>' +
          '<text>' +
          '<body><p>Paste or type your text here</p></body>' +
          '</text>' +
          '</TEI>';
        var defaultXML;
        var root;
        var defaultDoc;
        var doc;
        var parser = new DOMParser();
        // We have to parse as HTML as HTML entities will break XML parsing in
        // firefox.
        doc = parser.parseFromString(writer.editor.getContent(), 'text/html');
        // Embeds the document in the body tag.
        root = doc.body.firstElementChild.getAttribute('_tag');
        switch (writer.root) {
          case 'TEI':
            if (root !== 'TEI') {
              defaultDoc = parser.parseFromString(defaultTEI, 'text/xml');
              writer.converter.doProcessing(defaultDoc);
            }
            break;
          default:
            if (root !== writer.root) {
              defaultXML = '<'+ writer.root + '></'+ writer.root + '>';
              defaultDoc = parser.parseFromString(defaultXML, 'text/xml');
              writer.converter.doProcessing(defaultDoc);
            }
            break;
        }
      });
    });
    // load modules then do the setup
    require(['jquery', 'modules/entitiesList', 'modules/relations', 'modules/selection',
      'modules/structureTree', 'modules/validation'],
      function ($, EntitiesList, Relations, Selection, StructureTree, Validation) {
        // The function setupLayoutAndModules() is provided by layout.js, this
        // function assumes it was already loaded before it's called.
        setupLayoutAndModules(writer, EntitiesList, Relations, Selection, StructureTree, Validation);
        // Replace the show loader with our own function which can handle how we
        // load documents, such that it will be drupal aware.
        writer.dialogManager.filemanager.showLoader = Drupal.CWRCWriter.dialogManager.filemanager.showLoader($, writer);
        // Log all loaded documents.
        writer.event('documentLoaded').subscribe(function () {
          // Update the select field with the new value if possible.
          var $select = $('#islandora-cwrc-document-select'),
            $navigation = $('#islandora-cwrc-document-nav');
          $select.val(Drupal.CWRCWriter.writer.currentDocId);
          $('li a', $navigation).removeClass('disabled');
          if ($('option:selected', $select).is('option:last-child')) {
            $('li.next a', $navigation).addClass('disabled');
          }
          if ($('option:selected', $select).is('option:first-child')) {
            $('li.prev a', $navigation).addClass('disabled');
          }
          // Force resize, as it's needed when the layout is done in an iframe as
          // it expects.
          setTimeout(writer.layout.resizeAll, 500);
        });
        if (config.documents.length) {
          window.location.hash = (window.location.hash !== "") ? window.location.hash : config.documents[0];
        }
        if (window.location.hash) {
          writer.fileManager.loadInitialDocument(window.location.hash);
        }
      });
  });
}
