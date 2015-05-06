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

//void Slider::setColor(std::vector<double> color)
//{
//    mColor = color;
//}

void Slider::setValue(double value)
{
    mValue = value;
}

int Slider::getID()
{
    return mID;
}

double Slider::getValue()
{
    return mValue;
}

void Slider::draw(std::vector<double> color)
{
    // Slider
    glColor3d(color[0], color[1], color[2]);
    glBegin(GL_QUADS);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP1.getX(), mP2.getY());
    glEnd();
    
    // Slider Position
    glColor3d(1 - color[0], 1 - color[1], 1 - color[2]);
    glBegin(GL_QUADS);
    double value = mP1.getX() + (100 * mValue) - 5;
    glVertex2d(value, mP1.getY() - 3);
    glVertex2d(value + 10, mP1.getY() - 3);
    glVertex2d(value + 10, mP2.getY() + 3);
    glVertex2d(value, mP2.getY() + 3);
    glEnd();
    
    // Slider Label
    void *font = GLUT_BITMAP_9_BY_15;
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    if (mActive) {
        glColor3d(0, 0, 0);
    } else {
        glColor3d(1, 1, 1);
    }
    int len, i;
    glRasterPos2d(mP1.getX() + 10, mP1.getY() + 5);
    len = (int) strlen(mLabel);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, mLabel[i]);
    }
    
    glDisable(GL_BLEND);
}

bool Slider::contains(Point p)
{
    if(p.getX() > mP1.getX() && p.getX() < mP2.getX() && p.getY() > mP1.getY() && p.getY() < mP2.getY()) {
        // Distance from left edge of slider
        double d = p.getX() - mP1.getX();
//        std::cout << "Distance: " << d <<std::endl;
        mValue = d / 100;
        return true;
    }
    return false;
}




