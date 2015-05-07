//
//  Square.cpp
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#include "Square.h"


Square::Square()
{
    
}

Square::Square(Point p1, Point p2)
:   mP1(p1),
    mP2(p2)
{
    
}

void Square::setP1(Point p)
{
    mP1 = p;
}

void Square::setP2(Point p)
{
    mP2 = p;
}

Point Square::getP1()
{
    return mP1;
}

Point Square::getP2()
{
    return mP2;
}

double Square::getLeft()
{
    return mP1.getX();
}

double Square::getBottom()
{
    return mP2.getY();
}

double Square::getWidth()
{
    return mP2.getX() - mP1.getX();
}

double Square::getHeight()
{
    return mP1.getY() - mP2.getY();
}

void Square::draw()
{
    glColor3d(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP1.getX(), mP2.getY());
    glEnd();
}

//void Square::setColor(std::vector<double> color)
//{
//    
//}

