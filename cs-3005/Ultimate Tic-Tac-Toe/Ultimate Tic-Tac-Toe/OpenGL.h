//
//  graphics1.h
//  MacGraphicsStarter
//
//  Created by Kaden Wilkinson on 3/5/15.
//
//

#ifndef MacGraphicsStarter_graphics1_h
#define MacGraphicsStarter_graphics1_h

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif


void undo();
void redo();
void save();
void load();
void clear();

void createBoard();

void drawBoard();
void drawText(double x, double y, const char *string);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();


#endif
