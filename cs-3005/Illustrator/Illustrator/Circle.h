//
//  Circle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Circle__
#define __Illustrator__Circle__

#include <cmath>
#include "Shape.h"
#include "Point.h"


class Circle: public Shape {
public:
    
    Circle();
    Circle(Point center, double radius, std::vector<double> colors);
    Circle(Point center, Point p, std::vector<double> colors);
    
    void setCenter(Point p);
    void setRadius(double r);
    
    virtual void draw();
    virtual void setColor(std::vector<double> color);
    virtual void save(std::ostream &os);
    virtual void load(std::istream &is);
    
    Point getCenter();
    double getRadius();
    
protected:
    
private:
    
    Point mCenter;
    double mRadius;
};

#endif /* defined(__Illustrator__Circle__) */
