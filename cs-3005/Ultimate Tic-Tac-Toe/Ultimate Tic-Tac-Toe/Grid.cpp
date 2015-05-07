//
//  Grid.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#include "Grid.h"


Grid::Grid(int size, Square square)
:   mSize(size),
    mSquare(square)
{
    addSquares(mSquares);
}

void Grid::addSquares(std::vector<Square *> squares)
{
    squares.clear();
    int row, col;
    double left = mSquare.getLeft();
    double bottom = mSquare.getBottom();
    double width = mSquare.getWidth();
    double height = mSquare.getHeight();
    double colWidth = width / mSize;
    double rowHeight = height / mSize;
    
    for (row = 1; row <= mSize; row++) {
        for (col = 1; col <= mSize; col++) {
            double x1 = (col * colWidth) + left;
            double x2 = x1 + colWidth;
            double y1 = (row * rowHeight) + bottom;
            double y2 = ((row - 1) * rowHeight) + bottom;
            Point p1 = Point(x1, y1);
            Point p2 = Point(x2, y2);
            
            squares.push_back(new Square(p1, p2));
        }
    }
}

void Grid::draw()
{
    for (auto itr : mSquares) {
        itr->draw();
    }
}

void Grid::resize(int width, int height)
{
    
}


