//
//  OpenGL.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/7/15.
//
//

#ifndef Ultimate_Tic_Tac_Toe_OpenGL_h
#define Ultimate_Tic_Tac_Toe_OpenGL_h

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

#include "Game.h"

void save();
void load();
void undo();
void redo();
void clear();

void drawText(double x, double y, const char *string);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();




#endif
