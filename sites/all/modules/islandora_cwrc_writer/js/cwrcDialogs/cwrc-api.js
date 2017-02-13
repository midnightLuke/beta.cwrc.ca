/*jshint browser: true, devel: true*/
/*global jQuery, Drupal*/
/**
 * @file
 * Defines a function to override the CWRC-Writer API.
 *
 * We do this because the requests and responses for searching / creating
 * entities differ.
 */
Drupal.CWRCWriter = Drupal.CWRCWriter || {};
Drupal.CWRCWriter.api = {
  /**
   * Used to search / create / update entities of the given type.
   *
   * @param type
   *   The type of entity to handle, person, organization, title, place.
   * @param url
   *   The url for the CWRC API.
   * @param $
   *   A reference to the jQuery object.
   * @constructor
   */
  CwrcEntity: function (type, url, $) {
    'use strict';
    this.searchEntity = function(searchObject){
      var limit, page, restrictions;
      limit = searchObject.limit !== undefined ? searchObject.limit : 100;
      page = searchObject.page !== undefined ? searchObject.page : 0;
      restrictions = searchObject.restrictions !== undefined ? searchObject.restrictions : [];
      return $.ajax({
        url: url + '/' + type + '/search',
        type: 'GET',
        async: true,
        data: {
          query: searchObject.query,
          limit: limit,
          page: page,
          restrictions: restrictions
        },
        success: function(data) {
          searchObject.success(data);
        },
        error: function(error) {
          searchObject.error(error);
        }
      });
    };
    /**
     *
     * @param pid
     * @returns {*}
     */
    this.getEntity = function(pid) {
      var result = result;
      $.ajax({
        url: url + '/' + type + '/' + pid,
        type: 'GET',
        async: false,
        success: function(data) {
          result = data;
        },
        error: function(error) {
          result = error;
        }
      });
      return result;
    };
    this.newEntity = function(data) {
      var result = result;
      $.ajax({
        url: url + '/' + type,
        type: 'POST',
        data: {
          method: 'post',
          data: data
        },
        async: false,
        success: function(data) {
          result = data;
        },
        error: function(error) {
          result = error;
        }
      });
      return result;
    };
    this.modifyEntity = function(pid, data) {
      var result = result;
      $.ajax({
        url: url + '/' + type + '/' + pid,
        type: 'POST',
        data: {
          method: 'put',
          data: data
        },
        async: false,
        success: function(data) {
          result = data;
        },
        error: function(error) {
          result = error;
        }
      });
      return result;
    };
    /**
     * Deletes the given entity from the system.
     *
     * @param {string} pid
     *   The PID of the islandora object to delete.
     * @returns {*}
     */
    this.deleteEntity = function(pid) {
      // Not Implemented. There is no mechanism in the interface to perform this
      // action.
    };
  },
  /**
   * Instantiate the CWRC API.
   *
   * @param url
   *   The url in which to issues requests to create / update / search entities.
   * @param $
   *   jQuery object.
   * @constructor
   */
  CwrcApi: function (url, $) {
    'use strict';
    var that = this;
    // Public variables
    this.person = new Drupal.CWRCWriter.api.CwrcEntity('person', url, $);
    this.organization = new Drupal.CWRCWriter.api.CwrcEntity('organization', url, $);
    this.title = new Drupal.CWRCWriter.api.CwrcEntity('title', url, $);
    this.place = new Drupal.CWRCWriter.api.CwrcEntity('place', url, $);
    this.updateIsInitialized = function () {
      // Not implemented.
    };
    this.initializeWithCookieData = function (data) {
      // Not implemented.
    };
    this.initializeWithLogin = function (username, password) {
      // Not implemented.
    };
    this.logout = function () {
      // Not implemented.
    };
  }
};
