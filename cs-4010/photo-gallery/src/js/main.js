(function ($) {
    "use strict";

    var intervalID;
    var num_of_categories = piclist.length;
    var addImages = function () {
        var i,
            j;
        for (i = 0; i < num_of_categories; i++) {
            var num_of_images = piclist[i].length;
            for (j = 0; j < num_of_images; j++) {
                $('<li data-pile="category' + i + '">' +
                    '<a href="#" category="' + i + '" image="' + j + '">' +
                    '<img src="' + baseurl + piclist[i][j][1] + '" />' +
                    '</a>' +
                    '</li>'
                ).appendTo('#tp-grid');
            }
        }
        return true;
    };
    var back = function () {
        window.clearInterval(intervalID);
        console.log("back click handler");
        var $preview = $('#preview');
        var category = $preview.attr('category');
        var cat_length = piclist[category].length;
        var image = parseInt($preview.attr('image'));
        if (image == 0) {
            image = cat_length;
        }
        $preview.attr('src', baseurl + piclist[category][image - 1][0]);
        $preview.attr('category', category);
        $preview.attr('image', image - 1);
    };
    var next = function () {
        console.log("next click handler");
        var $preview = $('#preview');
        var category = $preview.attr('category');
        var cat_length = piclist[category].length;
        var image = parseInt($preview.attr('image'));
        if (image == cat_length - 1) {
            image = -1;
        }
        $preview.attr('src', baseurl + piclist[category][image + 1][0]);
        $preview.attr('category', category);
        $preview.attr('image', image + 1);
    };
    var play = function () {
        intervalID = window.setInterval(next, 4000);
    };
    var ThumbnailClickHandler = function () {
        window.clearInterval(intervalID);
        console.log("thumbnail click handler");
        var $preview = $('#preview');
        var category = $(this).attr('category');
        var image = $(this).attr('image');
        $preview.attr('src', baseurl + piclist[category][image][0]);
        $preview.attr('category', category);
        $preview.attr('image', image);
    };
    var addListeners = function () {
        var $back = $('#back');
        var $next = $('#next');
        var $play = $('.play');
        $back.on("click", back);
        $next.on("click", next);
        $play.on("click", play);
    };
    $(document).ready(function () {
        var $grid = $('#tp-grid'),
            $name = $('#name'),
            $close = $('#close'),
            $loader = $('<div class="loader">' +
                '<i></i><i></i><i></i><i></i><i></i><i></i><span>Loading...</span>' +
                '</div>'
            ).insertBefore($grid);
        addImages();

        var stapel = $grid.stapel({
            onLoad: function () {
                $loader.remove();
            },
            onBeforeOpen: function (pileName) {
                $name.html(pileName);
            },
            onAfterOpen: function (pileName) {
                window.clearInterval(intervalID);
                $close.show();
                var $images = $('li[data-pile] a');
                $images.on("click", ThumbnailClickHandler);
            }
        });
        addListeners();
        $close.on('click', function () {
            window.clearInterval(intervalID);
            $close.hide();
            $name.empty();
            stapel.closePile();
        });
    });
})(jQuery);