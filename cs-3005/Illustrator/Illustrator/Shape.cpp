//
//  Shape.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Shape.h"


Shape::Shape()
{
    
}

Shape::Shape(std::vector<double> color)
:   mColor(color),
    mOutline(false)
{
    
}

void Shape::setColor(std::vector<double> color)
{
    mColor = color;
}

void Shape::setOutline(bool outline)
{
    mOutline = outline;
}