(function($) {
    "use strict";

    var curr,
        curr_year,
        curr_month,
        curr_date,
        first_day,
        last_day,
        numDays,
        data = {
            monthNames: ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'],
            daysFull: ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'],
            daysPart: ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'],
            events: {
                "2015-2": {
                    "25": ["Test"]
                },
                "2015-3": {
                    "5": ["Heres an event", "Another event"],
                    "12": ["Work"]
                },
                "2015-4": {
                    "20": ["Test"]
                }
            }
        };
    var setToday = function() {
        curr = new Date();
        curr_year = curr.getFullYear();
        curr_month = curr.getMonth();
        curr_date = curr.getDate();
        first_day = new Date(curr_year, curr_month, 1).getDay();
        last_day = new Date(curr_year, curr_month + 1, 0).getDay();
        numDays = new Date(curr_year, curr_month + 1, 0).getDate();
        $('.month').html('<strong>' + data.monthNames[curr_month] + '</strong> ' + curr_year);
    };
    var setDate = function() {
        first_day = new Date(curr_year, curr_month, 1).getDay();
        last_day = new Date(curr_year, curr_month + 1, 0).getDay();
        numDays = new Date(curr_year, curr_month + 1, 0).getDate();
        $('.month').html('<strong>' + data.monthNames[curr_month] + '</strong> ' + curr_year);
    };

    var nextMonth = function() {
        if(curr_month >= 11) {
            curr_month = 0;
            curr_year += 1;
        } else {
            curr_month += 1;
        }
        setDate();
        updateCalendar();
    };
    var backMonth = function() {
        if(curr_month <= 0) {
            curr_month = 11;
            curr_year -= 1;
        } else {
            curr_month -= 1;
        }
        setDate();
        updateCalendar();
    };
    var nextYear = function() {
        curr_year += 1;
        setDate();
        updateCalendar();
    };
    var backYear = function() {
        curr_year -= 1;
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
            start = first_day,
            eventDay,
            $tr = $('<tr>');
        for (col = 0; col < data.daysPart.length; col++) {
            $('<th>' + data.daysPart[col] + '</th>').appendTo($tr);
        }
        $tr.appendTo('#calendar thead');

        for (row = 0; row < Math.ceil(numDays / 7); row++) {
            $tr = $('<tr>');
            for (col = 0; col < data.daysPart.length; col++) {
                if (start == td && date <= numDays) {
                    var i,
                        $td = $('<td data-date="' + date + '">' + date + '</td>'),
                        events,
                        $new = $('<a class="add btn btn-default btn-xs"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span></a>');
                        $new.appendTo($td);
                    if(data.events[curr_year + '-' + (curr_month + 1)] != undefined) {
                        eventDay = data.events[curr_year + '-' + (curr_month + 1)];
                        if(eventDay[date] != undefined) {
                            events = eventDay[date];
                            if (events != undefined) {
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
                var yearMonth = curr_year + '-' + (curr_month + 1);
                var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
                if(data.events[yearMonth] == undefined) {
                    data.events[yearMonth] = {};
                    data.events[yearMonth][dataDate] = [];
                } else {
                    if(data.events[yearMonth][dataDate] == undefined) {
                        data.events[yearMonth][dataDate] = [];
                    }
                }
                var index = data.events[yearMonth][dataDate].indexOf(this.getAttribute("data-name"));
                this.setAttribute('data-name', '');
                data.events[yearMonth][dataDate].splice(index, 1);
                if(newValue != "") {
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
                    var yearMonth = curr_year + '-' + (curr_month + 1);
                    var dataDate = this.parentNode.parentNode.getAttribute('data-date').toString();
                    if(data.events[yearMonth] == undefined) {
                        data.events[yearMonth] = {};
                        data.events[yearMonth][dataDate] = [];
                    } else {
                        if(data.events[yearMonth][dataDate] == undefined) {
                            data.events[yearMonth][dataDate] = [];
                        }
                    }
                    var index = data.events[yearMonth][dataDate].indexOf(this.getAttribute("data-name"));
                    this.setAttribute('data-name', '');
                    data.events[yearMonth][dataDate].splice(index, 1);
                    if(newValue != "") {
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
        $('#calendar thead, tbody').html("");
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

    $(document).ready(function() {
        setToday();
        updateCalendar();
        addNavHandlers();
    });
})(jQuery);