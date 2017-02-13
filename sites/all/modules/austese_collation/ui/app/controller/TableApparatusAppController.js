Ext.define('TableApparatusApp.controller.TableApparatusAppController', {
  extend: 'Ext.app.Controller',
  getConfigWindow: function() {
    if (!this.configWindow) {
      this.configWindow = Ext.ComponentQuery.query('#tableappwindow')[0];
    }
    return this.configWindow;
  },
  showConfigureOptions: function(button, e, options) {
    this.getConfigWindow().show();
  },
  cancelConfigureOptions: function(button, e, options) {
    button.up('window').hide();
  },
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
  /*
   * Reads config options from form and grid in the options window
   */
  getTableViewConfig: function() {
    var configWindow = this.getConfigWindow();
    var params = configWindow.down('form').getForm().getValues();
    var selectedVersions = configWindow.down('grid').getSelectionModel().getSelection();
    var selectedVersionsParam = '';
    Ext.Array.forEach(selectedVersions, function(r, i) {
      selectedVersionsParam += r.get('version');
      if (i < selectedVersions.length - 1) {
        selectedVersionsParam += ",";
      }
    });
    if (selectedVersionsParam) {
      params['SELECTED_VERSIONS'] = selectedVersionsParam;
      params['SOME_VERSIONS'] = 1;
    } else {
      params['SELECTED_VERSIONS'] = 'all';
    }
    // TODO calculate this and display sliding window for table only
    params['FIRSTID'] = '1';
    var versionSelector = Ext.ComponentQuery.query('#versionSelector');
    if (versionSelector.length > 0) {
      params['version1'] = versionSelector[0].getSubmitValue();
    }
    return params;
  },
  applyOptions: function() {
    var tableView = Ext.ComponentQuery.query('#tableView')[0];
    var documentId = Ext.ComponentQuery.query('#documentSelector')[0].getValue();
    var url = '/html/table/' + documentId;
    var params = this.getTableViewConfig();
    // reload the table view with the new config options
    tableView.body.load({
      url: url,
      method: 'GET',
      params: params,
      success: function() {
        // Add a tool tip.
        var blah = jQuery('.siglumleft');
        jQuery(blah).each(function(){
          jQuery(this).attr('title', jQuery(this).text());
        });
      },
    });

    this.getConfigWindow().hide();
  },
  viewRecord: function(button, event) {
    var docstore = Ext.getStore('DocumentListStore');
    var docombo = Ext.ComponentQuery.query('#documentSelector')[0];
    var docpath = docombo.getValue();
    var docrecord = docstore.getById(docpath);

    var version1 = Ext.ComponentQuery.query('#versionSelector')[0].getValue();
    var resname = version1.split('/');
    resname = resname[resname.length - 1];
    var resuuid = resname;
    var resources = docrecord.get("resources");
    for (var i = 0; i < resources.length; i++) {
      var res = resources[i];
      if (res.name && res.name == resname) {
        resuuid = res.id;
      }
    }
    var dataId = this.baseurl + "/repository/resources/" + resuuid;
    document.location.href = dataId;
  },
  onDocumentIdChange: function(t, newVal, oldVal, opts) {
    // update the list of versions when the document id changes (this will trigger version view to update)
    var versionListStore = Ext.getStore("VersionListStore");
    // TODO: update to /json/list when id is included in json
    versionListStore.getProxy().url = '/emicdora/json/list/' + newVal;

    // after version list has loaded, reset the table view version selection options
    versionListStore.load({scope: this, callback: function() {
        this.getConfigWindow().down('grid').getSelectionModel().selectAll();
      }});
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
    // ensure first record is loaded into versionSelector combo and force select event to fire
    // this will ensure that the other views are updated
    var versionSelector = Ext.ComponentQuery.query('#versionSelector')[0];
    if (records && records.length > 0) {
      versionSelector.select(records[0]);
      versionSelector.fireEvent('select', versionSelector, records);
    }
  },
  onVersionSelectionChange: function(combo, records, options) {
    var rec = records[0];
    if (rec) {
      var versionName = rec.get("version");
      var documentId = Ext.ComponentQuery.query('#documentSelector')[0].getValue();
      // load selected version into versionView
      var versionView = Ext.ComponentQuery.query('versionview')[0];
      var params = this.getTableViewConfig();
      var baseurl = this.baseurl;
      versionView.body.load({
        url: '/html/' + documentId,
        method: 'GET',
        params: {
          'version1': versionName,
          'SELECTED_VERSIONS': params['SELECTED_VERSIONS'] || 'all'
        },
        success: function(response, options) {
          // Weirdly, this function is called twice.
          // First for AJAX response success, then after the content is loaded.
          // We're only interested in after the content is loaded
          if (!response.responseText) {
            var resname = versionName.split('/');
            resname = resname[resname.length - 1];
            var docstore = Ext.getStore('DocumentListStore');
            var docrecord = docstore.getById(documentId);
            var resuuid = resname;
            if (docrecord) {
              var resources = docrecord.get("resources");
              for (var i = 0; i < resources.length; i++) {
                var res = resources[i];
                if (res.name && res.name == resname) {
                  resuuid = res.id;
                }
              }
            }
            var dataId = baseurl + "/repository/resources/" + resuuid + "/content";
            var bodyEl = this.target.dom;
            bodyEl.annotationsEnabled = false;
          }
        }
      });
      // reload table view (with this version as base)
      var tableView = Ext.ComponentQuery.query('#tableView')[0];
      if (tableView && tableView.body) {
        this.applyOptions();
      } else if (tableView) {
        tableView.on('render', this.applyOptions);
      }
    }
  },
  // delayed tasks for highlighting version and table elems (to prevent multiple highlights)
  // it would be better to attach buffer to listener, but ext does not currently allow this within control function
  highlightFirst: new Ext.util.DelayedTask(function(args) {
    args.elem.highlight("ffff9c", {attr: 'backgroundColor', duration: 1000});
  }),
  highlightTableFirst: new Ext.util.DelayedTask(function(args) {
    args.elem.highlight("ffff9c", {attr: 'backgroundColor', duration: 1000});
  }),
  syncScroll: function(event, scrolledView) {
    // temporary behaviour until proper sync scroll that does incremental loading of table is implemented:
    // fetch table length of entire version, scroll to match
    var versionViewBody = Ext.ComponentQuery.query('versionview')[0].body;
    var tableView = Ext.ComponentQuery.query('#tableView')[0];
    var tableViewBody = tableView.body;
    var textContent = versionViewBody.dom.textContent || versionViewBody.dom.innerText;
    var numContentCharacters = textContent.length + 20; // a few extra for good measure

    var tableOptions = this.getTableViewConfig();
    if (numContentCharacters > tableOptions.LENGTH) {
      this.getConfigWindow().down('form').getForm().findField('LENGTH').setValue(numContentCharacters);
      this.applyOptions();
    }

    var maxScroll = 0;
    var otherMaxScroll = 0;
    var currentScroll = 0;
    var percent = 0;
    var otherScroll = 0;
    if (scrolledView == Ext.ComponentQuery.query('versionview')[0]) {
      // get current versionView scroll amount and calculate percentage of scroll position
      maxScroll = versionViewBody.dom.scrollHeight - versionViewBody.dom.clientHeight;
      currentScroll = versionViewBody.getScroll().top;
      if (currentScroll != 0) {
        percent = currentScroll / maxScroll;
      }
      var xy = versionViewBody.getXY();
      var firstVisible, prevVisible;
      // adjust scroll amount so that scroll amount matches with how offsetsTo is calculated
      var actualHeight = Ext.fly(versionViewBody, '_internal').getHeight();
      var currentScrollAdjusted = percent * actualHeight + actualHeight / 2;

      //var contentCharOffset = 0;
      // find the first element visible in the version view, which we will use to align content
      Ext.Array.each(versionViewBody.query("span[id]"), function(e) {
        var current = Ext.get(e);
        var offsets = current.getOffsetsTo(versionViewBody);
        if (offsets[1] > currentScrollAdjusted) {
          // if current's offset is at bottom of or greater than what would be shown at bottom of screen, use prev
          if (offsets[1] >= (currentScrollAdjusted + actualHeight / 2)) {
            firstVisible = prevVisible;
          } else {
            firstVisible = current;
          }
          return false;
        }
        //contentCharOffset += (e.textContent || e.innerText).length;
        prevVisible = e;
      });
      if (firstVisible) {
        //this.highlightFirst.delay(200, null, null, [{elem: firstVisible}]);
        var theid = firstVisible.getAttribute('id');
        if (theid) {
          if (!theid.match("ext")) {
            var theNumber = theid.substring(1, theid.length).replace(/[a-z]/, '');
            var tableFirstVisible = Ext.get('t' + theNumber);
            //console.log(theNumber, firstVisible, tableFirstVisible);
          }
        }
      }


      if (tableFirstVisible) {

        if (tableFirstVisible) {
          tableFirstVisible.scrollIntoView(tableViewBody);
          //console.log(currentScrollAdjusted + " offset of first visible",firstVisible.getOffsetsTo(versionViewBody), firstVisible.dom.textContent || firstVisible.dom.innerText);
          //tableFirstVisible.highlight("ffff9c", { attr: 'backgroundColor', duration: 1000 });
          //this.highlightTableFirst.delay(200, null, null,[{elem: tableFirstVisible}]);
          //firstVisible.frame("#ff0000", 1, { duration: 1000 });
        }
      }

    } else {
      // get current tableView scroll and move versionView to match
    }
  },
  moveSiglum: function(panel, e) {
    jQuery('td.siglumleft').css('left', panel.body.dom.scrollLeft);
  },
  resizeUI: function(w, h) {
    // force resize and repositioning of app when window resizes
    var uiPanel = Ext.ComponentQuery.query("apparatusviewer")[0];
    var placeholder = Ext.get('uiplaceholder');
    var placeWidth = placeholder.getX() * 2;
    var newHeight = h - (placeholder.getY()) - 70;
    var newWidth = w - placeWidth;
    placeholder.setHeight(newHeight);
    uiPanel.setHeight(newHeight);
    placeholder.setWidth(newWidth);
    uiPanel.setWidth(newWidth);
    uiPanel.showAt(placeholder.getX(), placeholder.getY());
  },
  init: function(application) {
    this.baseurl = jQuery('#metadata').data('baseurl');
    Ext.EventManager.onWindowResize(this.resizeUI, this);
    this.control({
      "#configureButton": {
        click: this.showConfigureOptions
      },
      "#viewRecordBtn": {
        click: this.viewRecord
      },
      "#toggleFullscreenButton": {
        click: this.toggleFullscreen
      },
      "#cancelButton": {
        click: this.cancelConfigureOptions
      },
      "#applyButton": {
        click: this.applyOptions
      },
      "#versionSelector": {
        select: this.onVersionSelectionChange
      },
      "#documentSelector": {
        render: this.initSelectDocument,
        change: this.onDocumentIdChange
      },
      "versionview": {
        scroll: this.syncScroll
      },
      "tableview": {
        scroll: this.moveSiglum
      },
      "apparatusviewer": {
        restore: function() {
          this.resizeUI(Ext.Element.getViewportWidth(), Ext.Element.getViewportHeight());
        },
        afterrender: function() {
          this.resizeUI(Ext.Element.getViewportWidth(), Ext.Element.getViewportHeight());
        }
      }
      /*,"#tableView": {
       scroll: this.syncScroll
       }*/
    });

    Ext.getStore('VersionListStore').on('load', this.onVersionListLoad);
  }

});
