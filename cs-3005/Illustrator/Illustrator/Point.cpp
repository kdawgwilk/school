//
//  Point.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Point.h"

Point::Point(int x, int y)
:   mX(x),
    mY(y)
{
    
}

void Point::setX(int x)
{
    mX = x;
}

void Point::setY(int y)
{
    mY = y;
}

void Point::draw()
{
//    pygame.draw.circle(surface, (255, 255, 255), (self.x, self.y), 3, 0)
    
}

int Point::getX()
{
    return mX;
}

int Point::getY()
{
    return mY;
}