//
//  Tile.h
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __UltimateTicTacToe__Tile__
#define __UltimateTicTacToe__Tile__

#include "Square.h"

class Tile : public Square {
public:
    Tile(double x, double y, double size);
    Tile(Square square);
    void draw(int claimPlayer);
    bool click(double x, double y, int currentPlayer);
    int getOccupiedBy() const;
    
protected:
    int mOccupiedBy;
};

#endif /* defined(__UltimateTicTacToe__Tile__) */
