'use strict';

angular.module('unitCircleQuizApp')
  .directive('unitCircle', function () {
    return {
      templateUrl: 'app/unit-circle/custom-unit-circle.svg',
      restrict: 'EA',
      link: function (scope, element, attrs) {
        var sections = [];
        var unitCircle = Snap("#custom-unit-circle");
        var circle = unitCircle.circle(255, 255, 250);
        var y = unitCircle.line(254, 5, 254, 505);
        var x = unitCircle.line(5, 255, 505, 255);
        var sectionsGroup = Snap.selectAll(
          "#section-1," +
          "#section-2," +
          "#section-3," +
          "#section-4," +
          "#section-5," +
          "#section-6," +
          "#section-7," +
          "#section-8," +
          "#section-9," +
          "#section-10," +
          "#section-11," +
          "#section-12," +
          "#section-13," +
          "#section-14," +
          "#section-15," +
          "#section-16 "
        );
        var quadrant1 = Snap.selectAll(
          "#section-1," +
          "#section-2," +
          "#section-3," +
          "#section-4"
        );
        var quadrant2 = Snap.selectAll(
          "#section-5," +
          "#section-6," +
          "#section-7," +
          "#section-8"
        );
        var quadrant3 = Snap.selectAll(
          "#section-9," +
          "#section-10," +
          "#section-11," +
          "#section-12"
        );
        var quadrant4 = Snap.selectAll(
          "#section-13," +
          "#section-14," +
          "#section-15," +
          "#section-16"
        );

        circle.attr({
          fill: "none"
        });
        sectionsGroup.attr({
          strokeWidth: 1
        });
        //quadrant1.hover(
        //  function () {
        //
        //  },
        //  function () {
        //
        //  }
        //);

        unitCircle.attr({
          fill: "#fff",
          stroke: "#000",
          strokeWidth: 3
        });

        sectionsGroup.forEach( function (element, index) {
          sections.push(element);
          element.hover(function () {
            for (var sectionIndex = index; sectionIndex >= 0; sectionIndex--) {
              sections[sectionIndex].animate({
                fill: "#1D93BC"
              }, 75)
            }
          }, function () {
            for (var sectionIndex = index; sectionIndex >= 0; sectionIndex--) {
              sections[sectionIndex].animate({
                fill: "#fff"
              }, 75)
            }
          });
        });
      }
    };
  });
