//
//  Triangle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3)
:   mP1(p1),
    mP2(p2),
    mP3(p3)
{
    
}

void Triangle::setP1(Point p)
{
    mP1 = p;
}

void Triangle::setP2(Point p)
{
    mP2 = p;
}

void Triangle::setP3(Point p)
{
    mP3 = p;
}

void Triangle::draw()
{
    
}

Point Triangle::getP1()
{
    return mP1;
}

Point Triangle::getP2()
{
    return mP2;
}

Point Triangle::getP3()
{
    return mP3;
}


