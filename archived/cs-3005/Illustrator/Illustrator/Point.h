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
    
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    
    virtual void draw();
    virtual void save(std::ostream &os);
    virtual void load(std::istream &is);
    
    double getX() const;
    double getY() const;
    
protected:
    
private:
    
    double mX;
    double mY;
    double mRadius;
    
};

std::ostream &operator<<(std::ostream &os, const Point &rhs);
std::istream &operator>>(std::istream &is, Point &rhs);


#endif /* defined(__Illustrator__Point__) */
