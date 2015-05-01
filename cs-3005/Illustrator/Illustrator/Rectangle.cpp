//
//  Rectangle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2)
:   mP1(p1),
    mP2(p2)
{
    
}

void Rectangle::setP1(Point p)
{
    mP1 = p;
}

void Rectangle::setP2(Point p)
{
    mP2 = p;
}

void Rectangle::draw()
{
    
}

Point Rectangle::getP1()
{
    return mP1;
}

Point Rectangle::getP2()
{
    return mP2;
}


