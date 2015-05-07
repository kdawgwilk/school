'use strict';

/**
 * @ngdoc function
 * @name angularCalendarApp.controller:CalendarCtrl
 * @description
 * # CalendarCtrl
 * Controller of the angularCalendarApp
 */
angular.module('angularCalendarApp')
  .controller('CalendarCtrl', [ '$scope',
    function ($scope) {
      //var eventId = $routeParams.id;
      //EventService.get({id: eventId},
      //  function success(response) {
      //    //console.log("Success:" + JSON.stringify(response));
      //    $scope.eventEntry = response;
      //  },
      //  function error(errorResponse) {
      //    //console.log("Error:" + JSON.stringify(errorResponse));
      //  }
      //);

      $scope.curr;
      $scope.currYear;
      $scope.currMonth;
      $scope.currDate;
      $scope.firstDay;
      $scope.lastDay;
      $scope.numDays;
      $scope.data = {
          monthNames: ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'],
          daysFull: ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'],
          daysPart: ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'],
          events: {
            "2015-4": {
              "25": ['Test']
            },
            "2015-5": {
              "5": ['Heres an event', 'Another event'],
              "12": ['Work']
            },
            "2015-6": {
              "20": ['Test']
            }
          }
        };
      $scope.setToday = function() {
        $scope.curr = new Date();
        $scope.currYear = $scope.curr.getFullYear();
        $scope.currMonth = $scope.curr.getMonth();
        $scope.currDate = $scope.curr.getDate();
        $scope.firstDay = new Date($scope.currYear, $scope.currMonth, 1).getDay();
        $scope.lastDay = new Date($scope.currYear, $scope.currMonth + 1, 0).getDay();
        $scope.numDays = new Date($scope.currYear, $scope.currMonth + 1, 0).getDate();
        $('.month').html('<strong>' + $scope.data.monthNames[$scope.currMonth] + '</strong> ' + $scope.currYear);
      };
      $scope.setDate = function() {
        $scope.firstDay = new Date($scope.currYear, $scope.currMonth, 1).getDay();
        $scope.lastDay = new Date($scope.currYear, $scope.currMonth + 1, 0).getDay();
        $scope.numDays = new Date($scope.currYear, $scope.currMonth + 1, 0).getDate();
        $('.month').html('<strong>' + $scope.data.monthNames[$scope.currMonth] + '</strong> ' + $scope.currYear);
      };

      $scope.nextMonth = function() {
        if($scope.currMonth >= 11) {
          $scope.currMonth = 0;
          $scope.currYear += 1;
        } else {
          $scope.currMonth += 1;
        }
        $scope.setDate();
        $scope.updateCalendar();
      };
      $scope.backMonth = function() {
        if($scope.currMonth <= 0) {
          $scope.currMonth = 11;
          $scope.currYear -= 1;
        } else {
          $scope.currMonth -= 1;
        }
        $scope.setDate();
        $scope.updateCalendar();
      };
      $scope.nextYear = function() {
        $scope.currYear += 1;
        $scope.setDate();
        $scope.updateCalendar();
      };
      $scope.backYear = function() {
        $scope.currYear -= 1;
        $scope.setDate();
        $scope.updateCalendar();
      };
      $scope.today = function() {
        $scope.setToday();
        $scope.updateCalendar();
      };

      $scope.buildCalendar = function() {
        var row,
          col,
          date = 1,
          td = 0,
          start = $scope.firstDay,
          eventDay,
          $tr = $('<tr>');
        for (col = 0; col < $scope.data.daysPart.length; col++) {
          $('<th>' + $scope.data.daysPart[col] + '</th>').appendTo($tr);
        }
        $tr.appendTo('#calendar thead');

        for (row = 0; row < Math.ceil($scope.numDays / 7); row++) {
          $tr = $('<tr>');
          for (col = 0; col < $scope.data.daysPart.length; col++) {
            if (start === td && date <= $scope.numDays) {
              var i,
                $td = $('<td data-date="' + date + '">' + date + '</td>'),
                events,
                $new = $('<a class="add btn btn-default btn-xs"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span></a>');
              $new.appendTo($td);
              if($scope.data.events[$scope.currYear + '-' + ($scope.currMonth + 1)] !== undefined) {
                eventDay = $scope.data.events[$scope.currYear + '-' + ($scope.currMonth + 1)];
                if(eventDay[date] !== undefined) {
                  events = eventDay[date];
                  if (events !== undefined) {
                    for (i = 0; i < events.length; i++) {
                      $('<div><a class="event" data-name="' + events[i] + '">' + events[i] + '</a></div>').appendTo($td);
                    }
                  }
                }
              }

              $td.appendTo($tr);
              start++;
              date++;
            } else {
              $('<td>').appendTo($tr);
            }
            td++;
          }
          $tr.appendTo('#calendar tbody');
        }
        return true;
      };

      $scope.addDayHandlers = function() {
        $('.event').editable({
          type: 'text',
          title: 'Edit Event',
          success: function(response, newValue) {
            var yearMonth = $scope.currYear + '-' + ($scope.currMonth + 1);
            var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
            if($scope.data.events[yearMonth] === undefined) {
              $scope.data.events[yearMonth] = {};
              $scope.data.events[yearMonth][dataDate] = [];
            } else {
              if($scope.data.events[yearMonth][dataDate] === undefined) {
                $scope.data.events[yearMonth][dataDate] = [];
              }
            }
            var index = $scope.data.events[yearMonth][dataDate].indexOf(this.getAttribute('data-name'));
            this.setAttribute('data-name', '');
            $scope.data.events[yearMonth][dataDate].splice(index, 1);
            if(newValue !== '') {
              $scope.data.events[yearMonth][dataDate].push(newValue);
              this.setAttribute('data-name', newValue);
            }
          }
        });

        $('.add').on('click', function(e) {
          var $event = $('<div><a class="event" data-name=""></a></div>');
          $event.appendTo(e.currentTarget.parentNode);
          $('.event').editable({
            type: 'text',
            title: 'Edit Event',
            success: function(response, newValue) {
              var yearMonth = $scope.currYear + '-' + ($scope.currMonth + 1);
              var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
              if($scope.data.events[yearMonth] === undefined) {
                $scope.data.events[yearMonth] = {};
                $scope.data.events[yearMonth][dataDate] = [];
              } else {
                if($scope.data.events[yearMonth][dataDate] === undefined) {
                  $scope.data.events[yearMonth][dataDate] = [];
                }
              }
              var index = data.events[yearMonth][dataDate].indexOf(this.getAttribute('data-name'));
              this.setAttribute('data-name', '');
              $scope.data.events[yearMonth][dataDate].splice(index, 1);
              if(newValue !== '') {
                $scope.data.events[yearMonth][dataDate].push(newValue);
                this.setAttribute('data-name', newValue);
              }
            }
          });
        });
      };
      $scope.updateCalendar = function() {
        $('#calendar thead, tbody').html('');
        $scope.buildCalendar();
        $scope.populateModal();
        $scope.addDayHandlers();
      };
      $scope.populateModal = function() {
        var $modalList = $('.modal-body .list-group');
        var i;
        for (var key in $scope.data.events) {
          if ($scope.data.events.hasOwnProperty(key)) {
            var obj = $scope.data.events[key];
            for (var prop in obj) {
              // important check that this is objects own property
              // not from prototype prop inherited
              if(obj.hasOwnProperty(prop)){
                console.log(obj[prop][0]);
                for(i = 0; i < obj[prop].length; i++) {
                  $('<li class="list-group-item"><a class="event" data-name="' + obj[prop][i] + '">' + obj[prop][i] + '</a></li>').appendTo($modalList);
                }
              }
            }
          }
        }
      };

      $scope.setToday();
      $scope.updateCalendar();
    }]);
