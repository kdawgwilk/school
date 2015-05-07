//
//  Grid.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#ifndef __Ultimate_Tic_Tac_Toe__Grid__
#define __Ultimate_Tic_Tac_Toe__Grid__

#include "Headers.h"
#include "Square.h"


class Grid {
public:
    
    Grid(int size, Square square);
    
    void addSquares(std::vector<Square *> squares);
    
    void draw();
    void resize(int width, int height);
    
protected:
    
    int mSize;
    std::vector<Square *> mSquares;
    Square mSquare;
    
private:
    
    
};


#endif /* defined(__Ultimate_Tic_Tac_Toe__Grid__) */
