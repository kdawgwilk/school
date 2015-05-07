//
//  Game.h
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __UltimateTicTacToe__Game__
#define __UltimateTicTacToe__Game__

#include <vector>
#include "Grid.h"
#include "Board.h"

class Game : public Grid {
public:
    Game(double x, double y, double size);
    Game(Square square);
    ~Game();
    void setSize();
    void draw()const;
    bool click(double x, double y);
    void setPlayableBoard(int index);
    void checkWin();
    
protected:
    std::vector<Board *> mBoards;
    bool mActive;
    int mCurrentPlayer;
    
};

#endif /* defined(__UltimateTicTacToe__Game__) */
