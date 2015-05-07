'use strict';

angular.module('unitCircleQuizApp')
  .config(function ($routeProvider) {
    $routeProvider
      .when('/calculator', {
        templateUrl: 'app/calculator/calculator.html',
        controller: 'CalculatorCtrl'
      });
  });
