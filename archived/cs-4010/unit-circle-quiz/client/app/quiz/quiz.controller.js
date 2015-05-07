'use strict';

angular.module('unitCircleQuizApp')
  .controller('QuizCtrl', [ '$scope', 'SweetAlert',
    function ($scope, SweetAlert) {
      var questions = {
        "dAngles": "Click the section that belongs to the following angle in degrees: ",
        "rAngles": "Click the section that belongs to the following angle in radians: ",
        "quadrants": "Click the quadrant that has the following values: ",
        "points": "Click something: "
      };
      var questionsList = ["dAngles", "rAngles", "quadrants"];//, "points"];
      var data = {
        dAngles: ["30", "45", "60", "90", "120", "135", "150", "180", "210", "225", "240", "270", "300", "315", "330", "360"],
        rAngles: ["π/6", "π/4", "π/3", "π/2", "2π/3", "3π/4", "5π/6", "π", "7π/6", "5π/4", "4π/3", "3π/2", "5π/3", "7π/4", "11π/6", "2π"],
        quadrants: ["(+, +)", "(-, +)", "(-, -)", "(+, -)"],
        points: ["(2π/3, )", "(, )", "(, )"]
      };
      $scope.correct = false;
      $scope.correctAttempts = 0;
      $scope.totalAttempts = 0;
      $scope.highscore = 0;

      $scope.timerRunning = false;

      $scope.startTimer = function (){
        $scope.$broadcast('timer-start');
        $scope.timerRunning = true;
      };

      $scope.stopTimer = function (){
        $scope.$broadcast('timer-stop');
        $scope.timerRunning = false;
      };

      $scope.outOfTime = function () {
        SweetAlert.swal({
          title: $scope.correctAttempts + " out of " + $scope.totalAttempts,
          text: "Not too bad!",
          type: "success",
          closeOnCancel: false
        }, function (isConfirm) {
          if (isConfirm) {
            $scope.correctAttempts = 0;
            $scope.totalAttempts = 0;
            $scope.wrong = "";
            $scope.alert = "";
            //$scope.countdown = 5;
            $scope.stopTimer();
            $scope.newQuestion();
          }
        });
        //alert();
      };

      $scope.sectionClicked = function(e) {
        var angle;
        if ($scope.type == "points") {
          angle = e.currentTarget.attributes['data-angle'].value;
        } else {
          angle = e.currentTarget.attributes['data-angle'].value;
        }
        $scope.userAnswer = angle;
        $scope.submitAnswer();
      };
      $scope.newQuestion = function () {
        $scope.type = questionsList[Math.floor(Math.random() * questionsList.length)];
        //$scope.type = questionsList[2];
        $scope.correctAnswer = data[$scope.type][Math.floor(Math.random() * data[$scope.type].length)];
        $scope.question = questions[$scope.type] + $scope.correctAnswer;
      };

      $scope.submitAnswer = function () {
        if (!$scope.timerRunning) {
          $scope.startTimer();
        }
        $scope.checkAnswer();
      };
      $scope.checkAnswer = function () {
        $scope.totalAttempts++;
        var index = data.dAngles.indexOf($scope.userAnswer);
        if ($scope.type == "quadrants") {
          if ($scope.correctAnswer == (data[$scope.type][Math.floor(index / 4)])) {
            $scope.correct = true;
            $scope.correctAttempts++;
            if ($scope.highscore < $scope.correctAttempts) {
              $scope.highscore = $scope.correctAttempts;
            }
          }
        } else {
          if ($scope.correctAnswer == data[$scope.type][index]) {
            $scope.correct = true;
            $scope.correctAttempts++;
            if ($scope.highscore < $scope.correctAttempts) {
              $scope.highscore = $scope.correctAttempts;
            }
          }
        }
        if ($scope.correct) {
          $scope.newQuestion();
          $scope.wrong = "Correct!";
          $scope.alert = "success";
          $scope.correct = false;
        } else {
          $scope.wrong = "Try Again...";
          $scope.alert = "danger";
        }
      };
      $scope.newQuestion();
  }]);


