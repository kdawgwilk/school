document.addEventListener("DOMContentLoaded", function () {
    "use strict";
    var size = 9;
    var paddle;
    var ball;
    var container;
    var body;
    var intervalID;
    var paddlePosition;
    var ballX = 385;
    var ballY = 300;
    var brokenBricks = {};
    var brokenCount = 0;
    // ball velocity
    var msPerFrame = 20;
    var secondsPerFrame = msPerFrame / 1000;
    // This sets horizontal rate to 200--600 pixels/second
    //var vx = secondsPerFrame * (Math.floor(Math.random() * 400) + 200);
    var vx = secondsPerFrame * 200;
    if (Math.random() < 0.5) vx = -vx;
    // This sets vertical rate to 500 pixels/second
    var vy = secondsPerFrame * 400;

    function createBoard() {
        var row;
        var col;
        var brick;
        var board = '';
        var key;
        var classes;
        body = document.getElementsByTagName('body')[0];
        container = document.getElementById('main');
        for (row = 0; row <= size; row++) {
            for (col = 0; col <= size; col++) {
                key = 'brick' + String(col) + '-' + String(row);
                classes = 'row' + String(row) + ' col' + String(col);
                brick = '<div id="' + key + '" class="brick ' + classes + '"></div>';
                brokenBricks[key] = false;
                board += brick;
            }
        }
        board += '<div id="paddle"></div>';
        board += '<div id="ball" class="broken"></div>';
        container.innerHTML = board;
        paddle = document.getElementById("paddle");
        ball = document.getElementById('ball');
        paddle.style.left = (800 - 140) / 2;
    }
    function checkBroken(key, side) {
        var brick = document.getElementById(key);
        if (brokenBricks[key] == true) {
            // brick is already broken, pretend it's not there
            return false;
        } else {
            // brick has not been broken yet
            brokenBricks[key] = true; // now it has
            brokenCount += 1;
            // make brick invisible
            brick.classList.add('broken');
            // reverse y direction of ball
            if (side == 'top' || side == 'bottom') {
                if (vy > 0) {
                    vy = -Math.abs(vy);
                } else {
                    vy = Math.abs(vy);
                }
            } else if (side == 'left' || side == 'right') {
                if (vx > 0) {
                    vx = -Math.abs(vx);
                } else {
                    vx = Math.abs(vx);
                }
            } else {
                console.log('Side collision not found');
            }
        }
    }
    function checkPaddle(x, y, side) {
        var leftPaddle;
        var rightPaddle;
        if (paddlePosition < 2) {
            leftPaddle = 2;
            rightPaddle = 2 + 140
        } else if (paddlePosition > 658) {
            leftPaddle = 658;
            rightPaddle = 658 + 140;
        } else {
            leftPaddle = paddlePosition;
            rightPaddle = paddlePosition + 140;
        }
        if (x > leftPaddle && x < rightPaddle) {
            vy = -Math.abs(vy);
        }
    }
    function checkCollision(x, y, side) {
        var brickWidth = 80;  // dimensions of a brick
        var brickHeight = 20;
        var row = Math.floor((y - 100) / brickHeight);
        var col = Math.floor(x / brickWidth);
        var key = 'brick' + String(col) + '-' + String(row);
        if (y >= 550 && y <= 555) {
            checkPaddle(x, y, side);
            return false;
        }
        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            // not in the right area
            return false;
        }
        if ((x+2) % brickWidth < 4)  {
            // not quite in the brick--it's in the white border left and right
            checkBroken(key, side);
            return true;
        } else if ((y+2) % brickHeight < 4) {
            // not quite in the brick--it's in the white border top and bottom
            return false;
        }
        checkBroken(key, side);
        return true;
    }
    function moveBall() {
        if (brokenCount >= 100) {
            alert("You won!");
            window.clearInterval(intervalID);
            document.location.reload();
        }
        //else if (brokenCount > 80) {
        //    if (vx > 0){
        //        vx += 10;
        //    } else {
        //        vx -= 10;
        //    }
        //    //vy *= 100;
        //} else if (brokenCount > 60) {
        //    vx += 100;
        //    //vy = secondsPerFrame * 400;
        //} else if (brokenCount > 40) {
        //    vx += 100;
        //} else if (brokenCount > 5) {
        //    if (vx > 0){
        //        vx *= 2;
        //    } else {
        //        vx *= 2;
        //    }
        //}
        ballX += vx;
        ballY += vy;
        if (ballX < 0) {
            ballX = 0;
            vx = Math.abs(vx);
        } else if (ballX > 770) {
            ballX = 770;
            vx = -Math.abs(vx);
        } else if (ballY < 0) {
            ballY = 0;
            vy = Math.abs(vy);
        } else if (ballY > 565) {
            window.clearInterval(intervalID);
            alert('You Lose!');
            document.location.reload();
        }
        if (checkCollision(ballX + 15, ballY, 'top')) {
            //return false;
        } else if (checkCollision(ballX + 15, ballY + 30, 'bottom')) {
            //return false;
        } else if (checkCollision(ballX + 30, ballY + 15, 'right')) {
            //return false
        } else if (checkCollision(ballX, ballY + 15, 'left')) {
            //return false;
        }
        ball.style.left = ballX;
        ball.style.top = ballY;
        return true;
    }
    function ballHandler(e) {
        ball.classList.remove('broken');
        ball.style.left = ballX;
        ball.style.top = ballY;
        intervalID = window.setInterval(moveBall, 20);
        body.removeEventListener('click', ballHandler);
    }
    function mouseHandler(e) {
        var mouseX = e.clientX;
        var offsetLeft = document.getElementById('main').offsetLeft;
        paddlePosition = mouseX - offsetLeft - 70;
        if (paddlePosition < 2) {
            paddle.style.left = 2;
        } else if (paddlePosition > 658) {
            paddle.style.left = 658;
        } else {
            paddle.style.left = paddlePosition;
        }
    }
    function addHandlers() {
        body.addEventListener('mousemove', mouseHandler);
        body.addEventListener('click', ballHandler);
    }
    function newGame() {
        createBoard();
        addHandlers();
    }
    newGame();
})();