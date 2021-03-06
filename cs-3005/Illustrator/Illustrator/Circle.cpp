//
//  Circle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Circle.h"


Circle::Circle()
{
    
}

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
    if (mOutline) {
        glBegin(GL_LINE_LOOP);
    } else {
        glBegin(GL_POLYGON);
    }
    for(int i = 0; i < 32; i++) {
        double theta = (double)i/32.0 * 2.0 * 3.1415926;
        double x = mCenter.getX() + mRadius * cos(theta);
        double y = mCenter.getY() + mRadius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}

void Circle::save(std::ostream &os)
{
    double r, g, b;
    double scale = 0.01;  // i.e. round to nearest one-hundreth
    r = (int)(mColor[0] / scale) * scale;
    g = (int)(mColor[1] / scale) * scale;
    b = (int)(mColor[2] / scale) * scale;
    os << "Circle " << mCenter << int(mRadius) << " " << mOutline << " " << r << " " << g << " " << b << std::endl;
}

void Circle::load(std::istream &is)
{
    Point center;
    double radius;
    bool outline;
    std::vector<double> color;
    double r, g, b;
    is >> center >> radius >> outline >> r >> g >> b;
    color.push_back(r);
    color.push_back(g);
    color.push_back(b);
    setCenter(center);
    setRadius(radius);
    setColor(color);
    setOutline(outline);
}

Point Circle::getCenter()
{
    return mCenter;
}

double Circle::getRadius()
{
    return mRadius;
}



