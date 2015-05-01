'use strict';

/**
 * @ngdoc function
 * @name angularCalendarApp.controller:EventCtrl
 * @description
 * # EventCtrl
 * Controller of the angularCalendarApp
 */
angular.module('angularCalendarApp')
  .controller('EventCtrl', ['$scope', '$location', '$http',
  function ($scope, $location, $http) {
    $scope.awesomeThings = [
      'HTML5 Boilerplate',
      'AngularJS',
      'Karma'
    ];


  }]);
