'use strict';

angular.module('c4mApp')
  .service('EntityResource', function(DrupalSettings, Request, $http) {

    /**
     * Create a new entity.
     *
     * @param data
     *   The data object to POST.

     * @param resource
     *   The bundle of the entity.
     *
     * @param resourceFields
     *   The fields information.
     *
     * @returns {*}
     *   JSON of the newly created entity.
     */
    this.createEntity = function(data, resource, resourceFields) {
      Request.resourceFields = resourceFields;
      Request.resource = resource;
      return $http({
        method: 'POST',
        url: DrupalSettings.getBasePath() + 'api/' + resource,
        data: data,
        transformRequest: Request.prepare,
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          "X-CSRF-Token": DrupalSettings.getCsrfToken()
        },
        withCredentials: true
      });
    }
  });
