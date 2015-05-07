'use strict';

angular.module('angularCalendarApp')
.factory('EventService', ['$http', '$resource',
  function($http, $resource) {
    return $resource('/api/events', {}, {
      get: {method: 'GET', cache: false, isArray: true},
      save: {method: 'POST', cache: false, isArray: false},
      update: {method: 'PUT', cache: false, isArray: false},
      delete: {method: 'DELETE', cache: false, isArray: false}
    });
}]);
//.factory('ClientService', ['$scope', '$http', '$resource',
//  function($scope, $http, $resource) {
//    return $resource('/api/clients', {}, {
//      get: {method: 'GET', cache: false, isArray: true},
//      save: {method: 'POST', cache: false, isArray: false},
//      update: {method: 'PUT', cache: false, isArray: false},
//      delete: {method: 'DELETE', cache: false, isArray: false}
//    })
//}]);
