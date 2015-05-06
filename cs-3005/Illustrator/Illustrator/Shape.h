//
//  Shape.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Shape__
#define __Illustrator__Shape__

#include <iostream>
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

#endif /* defined(__Illustrator__Shape__) */
