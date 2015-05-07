//
//  Board.h
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __UltimateTicTacToe__Board__
#define __UltimateTicTacToe__Board__

#include <vector>
#include "Grid.h"
#include "Tile.h"

class Board : public Grid {
public:
    Board(double x, double y, double size);
    Board(Square square);
    ~Board();
    void draw(bool mActive) const;
    bool click(double x, double y, int currentPlayer);
    int getLatestTile();
    void setPlayable(bool value);
    bool isFull();
    int getOccupied();
    
protected:
    std::vector<Tile *> mTiles;
    int mOccupied;
    bool mPlayable;
    int mLatestTile;
    int mClaimedBy;
    void checkWin();
    
};

#endif /* defined(__UltimateTicTacToe__Board__) */
