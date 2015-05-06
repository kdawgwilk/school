'use strict';

/**
 * @ngdoc overview
 * @name angularCalendarApp
 * @description
 * # angularCalendarApp
 *
 * Main module of the application.
 */
angular
  .module('angularCalendarApp', [
    'ngAnimate',
    'ngAria',
    'ngCookies',
    'ngMessages',
    'ngResource',
    'ngRoute',
    'ngSanitize',
    'ngTouch'
  ])
  .config(function ($routeProvider) {
    $routeProvider
      .when('/', {
        templateUrl: 'views/main.html',
        controller: 'MainCtrl'
      })
      .when('/calendar', {
        templateUrl: 'views/calendar.html',
        controller: 'CalendarCtrl'
      })
      .when('/event', {
        templateUrl: 'views/event.html',
        controller: 'EventCtrl'
      })
      .otherwise({
        redirectTo: '/'
      });
  });
