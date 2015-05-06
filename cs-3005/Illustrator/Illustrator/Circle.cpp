//
//  Circle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Circle.h"


Circle::Circle(Point center, double radius, std::vector<double> colors)
:   Shape(colors),
    mCenter(center),
    mRadius(radius)
{
    
}

Circle::Circle(Point center, Point p, std::vector<double> colors)
:   Shape(colors),
    mCenter(center)
{
    double distance = sqrt(
        pow((p.getX() - center.getX()), 2.0) +
        pow((p.getY() - center.getY()), 2.0)
    );
    std::cout << distance << std::endl;
    mRadius = distance;
}


void Circle::setCenter(Point p)
{
    mCenter = p;
}

void Circle::setRadius(double r)
{
    mRadius = r;
}

void Circle::draw()
{
    glColor3d(mColor[0], mColor[1], mColor[2]);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 32; i++) {
        double theta = (double)i/32.0 * 2.0 * 3.1415926;
        double x = mCenter.getX() + mRadius * cos(theta);
        double y = mCenter.getY() + mRadius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}

void Circle::save(std::ostream &os) const
{
    os << "";
}

Point Circle::getCenter()
{
    return mCenter;
}

double Circle::getRadius()
{
    return mRadius;
}



