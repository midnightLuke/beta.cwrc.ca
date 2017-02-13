Ext.define('TableApparatusApp.store.DocumentListStore', {
    extend: 'Ext.data.Store',

    requires: [
        'TableApparatusApp.model.DocumentListModel',
    ],

    constructor: function(cfg) {
        var hashsplit = document.location.href.split('#');
        var slashsplit = hashsplit[1].split('/');
        var mvd = slashsplit[0];
        var crit_ed = slashsplit[1];
        var me = this;
        cfg = cfg || {};
        var project = jQuery('#metadata').data('project');
        me.callParent([Ext.apply({
            storeId: 'DocumentListStore',
            autoLoad: true,
            model: 'TableApparatusApp.model.DocumentListModel',
            proxy: {
                type: 'ajax',
                url: '/islandora/emic/collation/' + crit_ed + '/' + mvd + '/list',
                reader: {
                    type: 'json',
                    root: 'results'
                }
            }
        }, cfg)]);
    }
});