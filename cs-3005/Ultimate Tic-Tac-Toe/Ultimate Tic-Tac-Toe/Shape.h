//
//  Shape.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#ifndef __Ultimate_Tic_Tac_Toe__Shape__
#define __Ultimate_Tic_Tac_Toe__Shape__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#ifdef _WIN32
#include "glut.h"
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif


class Shape {
public:
    
    Shape();
    Shape(std::vector<double> color);
    virtual void draw() = 0;
    virtual void setColor(std::vector<double> color) = 0;
    virtual void save(std::ostream &os) = 0;
    virtual void load(std::istream &is) = 0;
    
protected:
    
    std::vector<double> mColor;
    
private:
    
};

#endif /* defined(__Ultimate_Tic_Tac_Toe__Shape__) */
