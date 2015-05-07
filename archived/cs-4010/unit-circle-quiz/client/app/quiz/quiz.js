'use strict';

angular.module('unitCircleQuizApp')
  .config(function ($routeProvider) {
    $routeProvider
      .when('/quiz', {
        templateUrl: 'app/quiz/quiz.html',
        controller: 'QuizCtrl'
      });
  });

