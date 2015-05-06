//
//  Slider.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "Slider.h"


Slider::Slider(Point p1, const char *label, int id, double value, std::vector<double> color)
:   Button(p1,label, id, color),
    mValue(value)
{
    
}

void Slider::setColor(std::vector<double> color)
{
    mColor = color;
}

void Slider::setValue(double value)
{
    mValue = value;
}

std::vector<double> Slider::getOppositeColor()
{
//    [255-x for x in self.color];
    return {};
}

int Slider::getID()
{
    return mID;
}

double Slider::getValue()
{
    return mValue;
}

//void Slider::draw()
//{
//    glColor3d(mColor[0], mColor[1], mColor[2]);
//    glBegin(GL_QUADS);
//    glVertex2d(mP1.getX(), mP1.getY());
//    glVertex2d(mP2.getX(), mP1.getY());
//    glVertex2d(mP2.getX(), mP2.getY());
//    glVertex2d(mP1.getX(), mP2.getY());
//    glEnd();
//}
//
//bool Slider::contains(Point p)
//{
//    if(p.getX() > mP1.getX() && p.getX() < mP2.getX() && p.getY() > mP1.getY() && p.getY() < mP2.getY()) {
//        return true;
//    }
//    return false;
//}




