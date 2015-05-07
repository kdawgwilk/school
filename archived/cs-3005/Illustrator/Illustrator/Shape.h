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
    virtual void setColor(std::vector<double> color);
    virtual void setOutline(bool outline);

    virtual void save(std::ostream &os) = 0;
    virtual void load(std::istream &is) = 0;
    
protected:
    
    std::vector<double> mColor;
    bool mOutline;
    
private:
    
};

#endif /* defined(__Illustrator__Shape__) */
