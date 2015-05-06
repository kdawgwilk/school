//
//  graphics1.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 3/5/15.
//
//

#ifndef Illustrator_OpenGL_h
#define Illustrator_OpenGL_h

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Button.h"
#include "Slider.h"


void save();
void load();
void undo();
void redo();
void clear();

void drawPoints();
void drawShapes();
void drawButtons();
void drawSliders();
void drawText(double x, double y, const char *string);

void createButtons();
void createSliders();

void handleButtonClick(int x, int y, Button *btn);
void handleSliderClick(int x, int y, Slider *slider);
void handleOtherClick(int x, int y);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();


#endif
