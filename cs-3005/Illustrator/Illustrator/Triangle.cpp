//
//  Triangle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Triangle.h"


Triangle::Triangle()
{
    
}

Triangle::Triangle(Point p1, Point p2, Point p3, std::vector<double> color)
:   Shape(color),
    mP1(p1),
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
    glColor3d(mColor[0], mColor[1], mColor[2]);
    glBegin(GL_TRIANGLES);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP3.getX(), mP3.getY());
    glEnd();
}

void Triangle::setColor(std::vector<double> color)
{
    mColor = color;
}

void Triangle::save(std::ostream &os)
{
    os << "Triangle " << mP1 << mP2 << mP3 << mColor[0] << " " << mColor[1] << " " << mColor[3] << std::endl;
}

void Triangle::load(std::istream &is)
{
    Point p1;
    Point p2;
    Point p3;
    std::vector<double> color;
    double r, g, b;
    is >> p1 >> p2 >> p3 >> r >> g >> b;
    color.push_back(r);
    color.push_back(g);
    color.push_back(b);
    setP1(p1);
    setP2(p2);
    setP3(p3);
    setColor(color);
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


