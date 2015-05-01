'use strict';

/**
 * @ngdoc function
 * @name angularCalendarApp.controller:MainCtrl
 * @description
 * # MainCtrl
 * Controller of the angularCalendarApp
 */
angular.module('angularCalendarApp')
  .controller('MainCtrl', [ '$scope', '$location', '$http', '$routeParams', 'EventService',
  function ($scope, $location, $http, $routeParams, EventService) {
    $scope.awesomeThings = [
      'HTML5 Boilerplate',
      'AngularJS',
      'Karma'
    ];
    var eventId = $routeParams.id;
    EventService.get({id: eventId},
      function success(response) {
        console.log("Success:" + JSON.stringify(response));
        $scope.eventEntry = response;
      },
      function error(errorResponse) {
        console.log("Error:" + JSON.stringify(errorResponse));
      }
    );



    var curr,
      currYear,
      currMonth,
      currDate,
      firstDay,
      lastDay,
      numDays,
      data = {
        monthNames: ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'],
        daysFull: ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'],
        daysPart: ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'],
        events: {
          "2015-2": {
            "25": ['Test']
          },
          "2015-3": {
            "5": ['Heres an event', 'Another event'],
            "12": ['Work']
          },
          "2015-4": {
            "20": ['Test']
          }
        }
      };
    var setToday = function() {
      curr = new Date();
      currYear = curr.getFullYear();
      currMonth = curr.getMonth();
      currDate = curr.getDate();
      firstDay = new Date(currYear, currMonth, 1).getDay();
      lastDay = new Date(currYear, currMonth + 1, 0).getDay();
      numDays = new Date(currYear, currMonth + 1, 0).getDate();
      $('.month').html('<strong>' + data.monthNames[currMonth] + '</strong> ' + currYear);
    };
    var setDate = function() {
      firstDay = new Date(currYear, currMonth, 1).getDay();
      lastDay = new Date(currYear, currMonth + 1, 0).getDay();
      numDays = new Date(currYear, currMonth + 1, 0).getDate();
      $('.month').html('<strong>' + data.monthNames[currMonth] + '</strong> ' + currYear);
    };

    var nextMonth = function() {
      if(currMonth >= 11) {
        currMonth = 0;
        currYear += 1;
      } else {
        currMonth += 1;
      }
      setDate();
      updateCalendar();
    };
    var backMonth = function() {
      if(currMonth <= 0) {
        currMonth = 11;
        currYear -= 1;
      } else {
        currMonth -= 1;
      }
      setDate();
      updateCalendar();
    };
    var nextYear = function() {
      currYear += 1;
      setDate();
      updateCalendar();
    };
    var backYear = function() {
      currYear -= 1;
      setDate();
      updateCalendar();
    };
    var today = function() {
      setToday();
      updateCalendar();
    };

    var buildCalendar = function() {
      var row,
        col,
        date = 1,
        td = 0,
        start = firstDay,
        eventDay,
        $tr = $('<tr>');
      for (col = 0; col < data.daysPart.length; col++) {
        $('<th>' + data.daysPart[col] + '</th>').appendTo($tr);
      }
      $tr.appendTo('#calendar thead');

      for (row = 0; row < Math.ceil(numDays / 7); row++) {
        $tr = $('<tr>');
        for (col = 0; col < data.daysPart.length; col++) {
          if (start === td && date <= numDays) {
            var i,
              $td = $('<td data-date="' + date + '">' + date + '</td>'),
              events,
              $new = $('<a class="add btn btn-default btn-xs"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span></a>');
            $new.appendTo($td);
            if(data.events[currYear + '-' + (currMonth + 1)] !== undefined) {
              eventDay = data.events[currYear + '-' + (currMonth + 1)];
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

    var addDayHandlers = function() {
      //$.fn.editable.defaults.mode = 'inline';
      $('.event').editable({
        type: 'text',
        title: 'Edit Event',
        success: function(response, newValue) {
          var yearMonth = currYear + '-' + (currMonth + 1);
          var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
          if(data.events[yearMonth] === undefined) {
            data.events[yearMonth] = {};
            data.events[yearMonth][dataDate] = [];
          } else {
            if(data.events[yearMonth][dataDate] === undefined) {
              data.events[yearMonth][dataDate] = [];
            }
          }
          var index = data.events[yearMonth][dataDate].indexOf(this.getAttribute('data-name'));
          this.setAttribute('data-name', '');
          data.events[yearMonth][dataDate].splice(index, 1);
          if(newValue !== '') {
            data.events[yearMonth][dataDate].push(newValue);
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
            var yearMonth = currYear + '-' + (currMonth + 1);
            var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
            if(data.events[yearMonth] === undefined) {
              data.events[yearMonth] = {};
              data.events[yearMonth][dataDate] = [];
            } else {
              if(data.events[yearMonth][dataDate] === undefined) {
                data.events[yearMonth][dataDate] = [];
              }
            }
            var index = data.events[yearMonth][dataDate].indexOf(this.getAttribute('data-name'));
            this.setAttribute('data-name', '');
            data.events[yearMonth][dataDate].splice(index, 1);
            if(newValue !== '') {
              data.events[yearMonth][dataDate].push(newValue);
              this.setAttribute('data-name', newValue);
            }
          }
        });
      });
    };
    var addNavHandlers = function() {
      $('.next-month').on('click', nextMonth);
      $('.back-month').on('click', backMonth);
      $('.next-year').on('click', nextYear);
      $('.back-year').on('click', backYear);
      $('.today').on('click', today);
    };
    var updateCalendar = function() {
      $('#calendar thead, tbody').html('');
      buildCalendar();
      populateModal();
      addDayHandlers();
    };
    var populateModal = function() {
      var $modalList = $('.modal-body .list-group');
      var i;
      for (var key in data.events) {
        if (data.events.hasOwnProperty(key)) {
          var obj = data.events[key];
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

    setToday();
    updateCalendar();
    addNavHandlers();



  }]);
