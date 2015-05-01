(function () {

    var container = document.getElementById('container');
    var size = 3;
    var row, col;
    var turn = 0;
    var player1;
    var player2;
    var currentPlayer;
    var winner = false;
    var box;

    var setPlayers = function () {
        player1 = document.getElementById('player1').value;
        player2 = document.getElementById('player2').value;
    };

    var checkTurn = function () {
        if (turn) {
            currentPlayer = player2;
            turn = 0;
        } else {
            currentPlayer = player1;
            turn = 1;
        }
    };

    var handler = function () {
        if (this.innerHTML != '') {

        } else {
            checkTurn();
            this.innerHTML = currentPlayer;
            checkWinner();
        }
    };

    var playerTurn = function () {
        boxId = '';
        box = document.getElementById('');
        box.innerHTML = currentPlayer;
    };

    var setHandlers = function () {
        var boxId;
        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                boxId = 'box' + col + '-' + row;
                document.getElementById(boxId).addEventListener('click', handler);
            }
        }
    };
    var removeHandlers = function () {
        var boxId;
        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                boxId = 'box' + col + '-' + row;
                document.getElementById(boxId).removeEventListener('click', handler);
            }
        }
    };

    var createBoard = function () {
        var table = '<table>';
        var boxId;
        for (row = 0; row < size; row++) {
            table += '<tr>';
            for (col = 0; col < size; col++) {
                boxId = 'box' + col + '-' + row;
                table += '<td id="' + boxId + '"></td>';
            }
            table += '</tr>';
        }
        table += '</table>';
        container.innerHTML = table;
        setHandlers();
    };

    var isWinner = function (a, b, c) {
        if ((a.innerHTML != '') && (a.innerHTML === b.innerHTML) && (a.innerHTML === c.innerHTML)) {
            console.log(a.innerHTML);
            a.classList.add('winner');
            b.classList.add('winner');
            c.classList.add('winner');
            winner = true;
            alert('Player ' + currentPlayer + ' Wins!');
            removeHandlers();
            return true;
        }
        return false;
    };

    var checkWinner = function () {
        var boxes = {};
        var box0_0 = document.getElementById('box0-0');
        var box0_1 = document.getElementById('box0-1');
        var box0_2 = document.getElementById('box0-2');
        var box1_0 = document.getElementById('box1-0');
        var box1_1 = document.getElementById('box1-1');
        var box1_2 = document.getElementById('box1-2');
        var box2_0 = document.getElementById('box2-0');
        var box2_1 = document.getElementById('box2-1');
        var box2_2 = document.getElementById('box2-2');

        isWinner(box0_0, box0_1, box0_2);
        isWinner(box1_0, box1_1, box1_2);
        isWinner(box2_0, box2_1, box2_2);

        isWinner(box0_0, box1_0, box2_0);
        isWinner(box0_1, box1_1, box2_1);
        isWinner(box0_2, box1_2, box2_2);

        isWinner(box0_0, box1_1, box2_2);
        isWinner(box2_0, box1_1, box0_2);

    };

    var gameLoop = function () {
        while (!winner) {
            checkWinner();
        }
    };

    var newGame = function () {
        setPlayers();
        createBoard();
        //gameLoop();
    };
    document.getElementById('newGame').onclick = function () {newGame();};
    newGame();

}());
