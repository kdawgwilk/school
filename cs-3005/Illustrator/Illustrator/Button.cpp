//
//  Button.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#include "OpenGL.h"
#include "Button.h"


Button::Button(Point p1, const char *label, int id, std::vector<double> color)
:   Rectangle(p1, Point(p1.getX() + 100, p1.getY() + 20), color),
    mLabel(label),
    mActive(false),
    mID(id)
{
    
}

void Button::draw()
{
    glColor3d(mColor[0], mColor[1], mColor[2]);
    glBegin(GL_QUADS);
    glVertex2d(mP1.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP1.getY());
    glVertex2d(mP2.getX(), mP2.getY());
    glVertex2d(mP1.getX(), mP2.getY());
    glEnd();
    
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

void Button::setColor(std::vector<double> color)
{
    mColor = color;
}

bool Button::contains(Point p)
{
    if(p.getX() > mP1.getX() && p.getX() < mP2.getX() && p.getY() > mP1.getY() && p.getY() < mP2.getY()) {
        return true;
    }
    return false;
}

void Button::setActive(bool state)
{
    mActive = state;
}

int Button::getID()
{
    return mID;
}

