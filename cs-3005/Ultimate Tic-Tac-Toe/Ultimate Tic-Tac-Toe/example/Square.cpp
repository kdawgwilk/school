//
//  Square.cpp
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Square.h"

Square::Square(double xIn, double yIn, double sizeIn)
:   mLeft(xIn),
    mBottom(yIn),
    mSize(sizeIn)
{
    
}


void Square::draw() const
{
//    GL_QUADS
    glBegin(GL_LINE_LOOP);
    glVertex2d(mLeft, mBottom);
    glVertex2d(mLeft + mSize, mBottom);
    glVertex2d(mLeft + mSize, mBottom + mSize);
    glVertex2d(mLeft, mBottom + mSize);
    glEnd();
}

bool Square::contains(double x, double y) const
{
    return (x >= mLeft && x <= mLeft + mSize) && (y >= mBottom && y <= mBottom + mSize);
}

void Square::adjust(double dx, double dy, double dsize)
{
    mLeft += dx;
    mBottom += dy;
    mSize += dsize;
}

void Square::destroy(std::vector<Square *> squares) const
{
    for (auto itr : squares) {
        delete itr;
    }
}
double Square::getLeft() const
{
    return mLeft;
}

double Square::getBottom() const
{
    return mBottom;
}

double Square::getSize() const
{
    return mSize;
}

