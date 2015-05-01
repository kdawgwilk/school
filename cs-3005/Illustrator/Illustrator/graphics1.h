//
//  graphics1.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 3/5/15.
//
//

#ifndef Illustrator_graphics1_h
#define Illustrator_graphics1_h


void DrawCircle(double x1, double y1, double radius);
void DrawRectangle(double x1, double y1, double x2, double y2);
void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
void DrawText(double x, double y, const char *string);
void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void InitializeMyStuff();


#endif
