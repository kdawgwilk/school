(function () {

    var size = 3;
    var row, col;
    var turn = 0;
    var turns = 0;
    var player1 = 'X';
    var player2 = 'O';
    var currentPlayer;
    var winner = false;
    var square;

    //changes turn after each player
    var checkTurn = function () {
        if (turn) {
            currentPlayer = player2;
            turn = 0;
        } else {
            currentPlayer = player1;
            turn = 1;
        }
    };

    //handler checks player turn and then sets the players square accordingly and then triggers to check for winner
    var handler = function () {
        if (this.innerHTML != '&nbsp;') {

        } else {
            checkTurn();
            this.innerHTML = currentPlayer;
            checkWinner();
            turns++;
            console.log(turns);
        }
    };

    //add handler to all squares
    var setHandlers = function () {
        var squareId;
        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                squareId = 'square' + col + row;
                document.getElementById(squareId).addEventListener('click', handler);
            }
        }
    };

    //check 3 squares and see if equal and if true set class to winner
    var isWinner = function (a, b, c) {
        if ((a.innerHTML != '&nbsp;') && (a.innerHTML === b.innerHTML) && (a.innerHTML === c.innerHTML)) {
            console.log(a.innerHTML);
            a.classList.add('winner');
            b.classList.add('winner');
            c.classList.add('winner');
            return 1;
        }
        return 0;
    };

    var checkWinner = function () {
        var wins = 0;
        var square00 = document.getElementById('square00');
        var square01 = document.getElementById('square01');
        var square02 = document.getElementById('square02');
        var square10 = document.getElementById('square10');
        var square11 = document.getElementById('square11');
        var square12 = document.getElementById('square12');
        var square20 = document.getElementById('square20');
        var square21 = document.getElementById('square21');
        var square22 = document.getElementById('square22');

        //check for wins and return 1 if there is a win
        wins += isWinner(square00, square01, square02);
        wins += isWinner(square10, square11, square12);
        wins += isWinner(square20, square21, square22);

        wins += isWinner(square00, square10, square20);
        wins += isWinner(square01, square11, square21);
        wins += isWinner(square02, square12, square22);

        wins += isWinner(square00, square11, square22);
        wins += isWinner(square20, square11, square02);

        //fix safari bug by waiting for handler to complete
        setTimeout(function () {
            //check for wins and tie and alert players accordingly
            if (wins == 0 && turns >= 9) {
                alert('Its a Tie!');
                document.location.reload();
            } else if (wins > 0) {
                alert('Player ' + currentPlayer + ' Wins!');
                document.location.reload();
            }
        });

    };

    //initializes game
    var newGame = function () {
        setHandlers();
    };

    newGame();

}());