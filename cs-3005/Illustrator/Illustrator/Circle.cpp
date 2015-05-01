//
//  Circle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Circle.h"


Circle::Circle(Point center, int radius)
:   mCenter(center),
    mRadius(radius)
{
    
}

void Circle::setCenter(Point p)
{
    mCenter = p;
}

void Circle::setRadius(int r)
{
    mRadius = r;
}

void Circle::draw()
{
    
}

Point Circle::getCenter()
{
    return mCenter;
}

int Circle::getRadius()
{
    return mRadius;
}



