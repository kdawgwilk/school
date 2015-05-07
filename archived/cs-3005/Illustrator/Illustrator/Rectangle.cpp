//
//  Rectangle.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Rectangle.h"


Rectangle::Rectangle()
{
    
}

Rectangle::Rectangle(Point p1, Point p2, std::vector<double> color)
:   Shape(color),
    mP1(p1),
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
    glColor3d(mColor[0], mColor[1], mColor[2]);
    if (mOutline) {
        glBegin(GL_LINE_LOOP);
    } else {
        glBegin(GL_QUADS);
    }
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP1.getX(), mP2.getY());
    glEnd();
}

void Rectangle::save(std::ostream &os)
{
    double r, g, b;
    double scale = 0.01;  // i.e. round to nearest one-hundreth
    r = (int)(mColor[0] / scale) * scale;
    g = (int)(mColor[1] / scale) * scale;
    b = (int)(mColor[2] / scale) * scale;
    os << "Rectangle " << mP1 << mP2 << mOutline << " " << r << " " << g << " " << b << std::endl;
}

void Rectangle::load(std::istream &is)
{
    Point p1;
    Point p2;
    bool outline;
    std::vector<double> color;
    double r, g, b;
    is >> p1 >> p2 >> outline >> r >> g >> b;
    color.push_back(r);
    color.push_back(g);
    color.push_back(b);
    setP1(p1);
    setP2(p2);
    setColor(color);
    setOutline(outline);
}

Point Rectangle::getP1()
{
    return mP1;
}

Point Rectangle::getP2()
{
    return mP2;
}


