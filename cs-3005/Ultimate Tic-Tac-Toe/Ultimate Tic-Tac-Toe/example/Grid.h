//
//  Grid.h
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __UltimateTicTacToe__Grid__
#define __UltimateTicTacToe__Grid__

#include <vector>
#include "Square.h"


class Grid : public Square {
public:
    Grid(double x, double y, double size);
    std::vector<Square *> getLocations() const;
    void draw() const;
    
protected:
    int mWinningCombos[8][3];
};

#endif /* defined(__UltimateTicTacToe__Grid__) */
