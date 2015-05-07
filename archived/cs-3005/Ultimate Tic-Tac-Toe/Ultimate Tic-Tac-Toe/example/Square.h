//
//  Square.h
//  UltimateTicTacToe
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __UltimateTicTacToe__Square__
#define __UltimateTicTacToe__Square__

#include <vector>
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

class Square {
public:
    Square(double x, double y, double size);
    void draw() const;
    bool contains(double x, double y) const;
    
    void adjust(double dx, double dy, double dsize);
    
    double getLeft() const;
    double getBottom() const;
    double getSize() const;
    
protected:
    double mLeft;
    double mBottom;
    double mSize;
    int mBoardSize;
};

#endif /* defined(__UltimateTicTacToe__Square__) */
