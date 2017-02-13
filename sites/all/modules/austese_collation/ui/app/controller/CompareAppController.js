Ext.define('TableApparatusApp.controller.CompareAppController', {
  extend: 'Ext.app.Controller',
  toggleFullscreen: function(button, e, options) {
    button.up('window').toggleMaximize();
    if (button.iconCls == 'exitFullscreenIcon') {
      button.setIconCls('fullscreenIcon');
    } else {
      button.setIconCls('exitFullscreenIcon');
      // set height of placeholder to 0 to prevent overflow in browser window
      var placeholder = Ext.get('uiplaceholder');
      placeholder.setHeight(0);
      Ext.getBody().scrollTo('top', 0);
    }
  },
  onDocumentIdChange: function(t, newVal, oldVal, opts) {
    // update the list of versions when the document id changes (this will trigger version views to update)
    var versionListStore = Ext.getStore("VersionListStore");
    versionListStore.getProxy().url = '/emicdora/json/list/' + newVal;
    this.versionListInit = false;
    versionListStore.load();
  },
  initSelectDocument: function() {
    var docombo = Ext.ComponentQuery.query('#documentSelector')[0];
    //var urlsplit = document.location.href.split('#');
    var hashsplit = document.location.href.split('#');
    var slashsplit = hashsplit[1].split('/');
    var mvd = slashsplit[0];
    var crit_ed = slashsplit[1];
    var docstore = Ext.getStore('DocumentListStore');
    if (slashsplit.length > 1) {
      var docpath = decodeURIComponent(mvd);
      var rec = docstore.findRecord('documentId', docpath);
      if (!rec || rec == -1) {
        // add to document list if it is not already in the list
        rec = docstore.add({documentId: docpath});
      }
      docombo.select(rec);
    } else {
      // set default init value for document if one wasn't provided
      docstore.add({documentId: 'english/shakespeare/kinglear/act1/scene1'});
      docombo.setValue('english/shakespeare/kinglear/act1/scene1');
    }
  },
  onVersionListLoad: function(store, records) {
    // ensure first and last record are loaded into versionSelector combos and force select event to fire
    // this will ensure that the other views are updated
    var versionSelector1 = Ext.ComponentQuery.query('#versionSelector1')[0];
    var versionSelector2 = Ext.ComponentQuery.query('#versionSelector2')[0];
    if (records && records.length > 0) {
      if (!this.versionListInit) {
        versionSelector1.select(records[0]);
        versionSelector2.select(records[records.length - 1]);
        this.versionListInit = true;
      }
      versionSelector2.fireEvent('select', versionSelector1, records);
    }
  },
  viewRecord: function(button, event) {
    var docstore = Ext.getStore('DocumentListStore');
    var docombo = Ext.ComponentQuery.query('#documentSelector')[0];
    var docpath = docombo.getValue();
    var docrecord = docstore.getById(docpath);
    var resname;
    if (button.itemId == "viewRecordBtn1") {
      // left hand side
      var version1 = Ext.ComponentQuery.query('#versionSelector1')[0].getValue();
      resname = version1.split('/');
    } else {
      var version2 = Ext.ComponentQuery.query('#versionSelector2')[0].getValue();
      var resname = version2.split('/');

    }
    // the name of the version will be in either one of these positions e.g. could be path/Base/vname or path/vname/add0 etc
    if (resname.length > 1) {
      var resname1 = resname[resname.length - 1];
    }
    if (resname.length > 2) {
      var resname2 = resname[resname.length - 2];
    }

    var resuuid = resname;
    var resources = docrecord.get("resources");
    for (var i = 0; i < resources.length; i++) {
      var res = resources[i];
      if (res.name && (res.name == resname1 || res.name == resname2)) {
        resuuid = res.id;
      }
    }

    var dataId = this.baseurl + "/repository/resources/" + resuuid;
    document.location.href = dataId;
  },

  onVersionSelectionChange: function(combo, records, options) {
    var rec = records[0];
    var controller = this;
    if (rec) {
      var versionName = rec.get("version");
      var versions = Ext.ComponentQuery.query('versionview');
      var counterLabels = Ext.ComponentQuery.query('variantcountlabel');
      var version1 = Ext.ComponentQuery.query('#versionSelector1')[0].getValue();
      var version2 = Ext.ComponentQuery.query('#versionSelector2')[0].getValue();
      var documentId = Ext.ComponentQuery.query('#documentSelector')[0].getValue();
      var baseurl = this.baseurl;
      // update left hand side
      versions[0].body.load({
        url: '/collationtools/get_edits/' + documentId,
        method: 'GET',
        params: {
          'version1': version1,
          'version2': version2,
          'diff_kind': 'deleted'
        },
        scope: controller,
        success: function(response) {
         // controller.attachSyncActions(versions[0], versions[1], counterLabels[0], counterLabels[1], "deleted");

          if (!response.responseText) {
            var resname = version1.split('/');
            resname = resname[resname.length - 1];
            var docstore = Ext.getStore('DocumentListStore');
            var docrecord = docstore.getById(documentId);
            var resuuid = resname;
            var resources = docrecord.get("resources");
            for (var i = 0; i < resources.length; i++) {
              var res = resources[i];
              if (res.name && res.name == resname) {
                resuuid = res.id;
              }
            }
            var dataId = baseurl + "/repository/resources/" + resuuid + "/content";
            if (response && response.target) {
              var bodyEl = response.target.dom;
              bodyEl.annotationsEnabled = false;
            }
          }
        }
      });
      // update right hand side
      versions[1].body.load({
        url: '/collationtools/get_edits/' + documentId,
        method: 'GET',
        params: {
          'version1': version2,
          'version2': version1,
          'diff_kind': 'added'
        },
        scope: controller,
        success: function(response) {
         // controller.attachSyncActions(versions[1], versions[0], counterLabels[1], counterLabels[0], "added");

          if (!response.responseText) {
            var resname = version2.split('/');
            resname = resname[resname.length - 1];
            var docstore = Ext.getStore('DocumentListStore');
            var docrecord = docstore.getById(documentId);
            var resuuid = resname;
            var resources = docrecord.get("resources");
            for (var i = 0; i < resources.length; i++) {
              var res = resources[i];
              if (res.name && res.name == resname) {
                resuuid = res.id;
              }
            }

            var dataId = baseurl + "/repository/resources/" + resuuid + "/content";
            if (response && response.target) {
              var bodyEl = response.target.dom;
              bodyEl.annotationsEnabled = false;
            }
          }
        }
      });
    }
  },
  syncScroll: function(event, scrolledView) {
    var syncButton = Ext.ComponentQuery.query("#syncButton")[0];
    if (!syncButton.pressed) {
      return;
    }
    var views = Ext.ComponentQuery.query("versionview");
    var otherView;
    if (scrolledView == views[0]) {
      otherView = views[1]
    } else {
      otherView = views[0];
    }
    otherView.suspendEvents();
    // FIXME: write version that uses ExtJS
    synchroScroll(scrolledView.body.dom, otherView.body.dom)
    otherView.resumeEvents();
  },
  resizeUI: function(w, h) {
    // force resize and repositioning of app when window resizes
    var uiPanel = Ext.ComponentQuery.query("compareviewer")[0];
    var placeholder = Ext.get('uiplaceholder');
    var placeWidth = placeholder.getX() * 2;
    var newHeight = h - (placeholder.getY()) - 70;
    var newWidth = (w - placeWidth) * 1.35;
    placeholder.setHeight(newHeight);
    uiPanel.setHeight(newHeight);
    placeholder.setWidth(newWidth);
    uiPanel.setWidth(newWidth);
    uiPanel.showAt(placeholder.getX(), placeholder.getY());
  },
  init: function(application) {
    //this.baseurl = jQuery('#metadata').data('baseurl');
    this.baseurl = jQuery('#metadata').data('baseurl');
    Ext.EventManager.onWindowResize(this.resizeUI, this);
    this.control({
      "#configureButton": {
        click: this.showConfigureOptions
      },
      "#toggleFullscreenButton": {
        click: this.toggleFullscreen
      },
      "#versionSelector1, #versionSelector2": {
        select: this.onVersionSelectionChange
      },
      "#documentSelector": {
        change: this.onDocumentIdChange
      },
      "#viewRecordBtn1, #viewRecordBtn2": {
        click: this.viewRecord
      },
      "compareviewer": {
        restore: function() {
          this.resizeUI(Ext.Element.getViewportWidth(), Ext.Element.getViewportHeight());
        },
        afterrender: function() {
          this.resizeUI(Ext.Element.getViewportWidth(), Ext.Element.getViewportHeight());
        }
      }

    });
    Ext.getStore('DocumentListStore').on('load', this.initSelectDocument, this);
    Ext.getStore('VersionListStore').on('load', this.onVersionListLoad, this);
  }

});
