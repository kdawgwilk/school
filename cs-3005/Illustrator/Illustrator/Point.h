//
//  Point.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Point__
#define __Illustrator__Point__

#include <cmath>
#include "Shape.h"


class Point: public Shape {
public:
    
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    
    virtual void draw();
    virtual void save(std::ostream &os) const;
    
    double getX();
    double getY();
    
protected:
    
private:
    
    double mX;
    double mY;
    double mRadius;
    
};

#endif /* defined(__Illustrator__Point__) */
