//
//  graphics1.h
//  MacGraphicsStarter
//
//  Created by Kaden Wilkinson on 3/5/15.
//
//

#ifndef MacGraphicsStarter_graphics1_h
#define MacGraphicsStarter_graphics1_h

#include "Headers.h"
#include "Grid.h"
#include "Square.h"


void undo();
void redo();
void save();
void load();
void clear();

void createBoard();

void playerTurn(int x, int y);
void checkWin();
void drawBoard();
void drawText(double x, double y, const char *string);

void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void initMyStuff();


#endif
