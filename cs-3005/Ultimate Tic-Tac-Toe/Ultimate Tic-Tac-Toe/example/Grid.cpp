//
//  Grid.cpp
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Grid.h"


Grid::Grid(double x, double y, double size)
: Square(x, y, size)
{
    int i, j;
    int count = 0;
    for (i = 0; i < mBoardSize * 2; i++) {
        for (j = 0; j < mBoardSize; j++) {
            if (i >= mBoardSize) {
                // Colums
                mWinningCombos[i][j] = (i - mBoardSize) + (j * mBoardSize);
            } else {
                // Rows
                mWinningCombos[i][j] = count;
            }
            count++;
        }
    }
    // Only check diagonals if size in an odd number
    if (mBoardSize % 2) {
        // Top Left to Bottom Right
        for (j = 0; j < mBoardSize; j++) {
            mWinningCombos[(mBoardSize * 2)][j] = j * (mBoardSize + 1);
        }
        // Top Right to Bottom Left
        for (j = 0; j < mBoardSize; j++) {
            mWinningCombos[1 + (mBoardSize * 2)][j] = (mBoardSize - 1) + (j * (mBoardSize - 1));
        }
    }
//    // Diagonals
//    mWinningCombos[6][0] = 0;
//    mWinningCombos[6][1] = 4;
//    mWinningCombos[6][2] = 8;
////    mWinningCombos[6][3] =
//    
//    mWinningCombos[7][0] = 2;
//    mWinningCombos[7][1] = 4;
//    mWinningCombos[7][2] = 6;
    
//    // Rows
//    mWinningCombos[0][0] = 0;
//    mWinningCombos[0][1] = 1;
//    mWinningCombos[0][2] = 2;
//    
//    mWinningCombos[1][0] = 3;
//    mWinningCombos[1][1] = 4;
//    mWinningCombos[1][2] = 5;
//                    
//    mWinningCombos[2][0] = 6;
//    mWinningCombos[2][1] = 7;
//    mWinningCombos[2][2] = 8;
//    
//    // Colums
//    mWinningCombos[3][0] = 0;
//    mWinningCombos[3][1] = 3;
//    mWinningCombos[3][2] = 6;
//                    
//    mWinningCombos[4][0] = 1;
//    mWinningCombos[4][1] = 4;
//    mWinningCombos[4][2] = 7;
//                    
//    mWinningCombos[5][0] = 2;
//    mWinningCombos[5][1] = 5;
//    mWinningCombos[5][2] = 8;
    
    }


std::vector<Square *> Grid::getLocations() const
{
    std::vector<Square *> squares;
    double size = mSize / mBoardSize;
    
    Square * sq;
    int i, xOffset, yOffset;
    double x, y;
    for(i = 0; i < (mBoardSize * mBoardSize); i++) {
        xOffset = i % mBoardSize;
        yOffset = i / mBoardSize;
        
        x = mLeft + xOffset * size;
        y = mBottom + yOffset * size;
        
        sq = new Square(x, y, size);
        squares.push_back(sq);
    }
    return squares;
}

void Grid::draw() const
{
    std::vector<Square *> squares = this->getLocations();
    for (auto itr : squares) {
        itr->draw();
    }
}


