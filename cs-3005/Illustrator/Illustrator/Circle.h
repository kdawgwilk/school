//
//  Circle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Circle__
#define __Illustrator__Circle__

#include "Point.h"


class Circle {
public:
    
    Circle(Point center, int radius);
    
    void setCenter(Point p);
    void setRadius(int r);
    
    virtual void draw();
    
    Point getCenter();
    int getRadius();
    
protected:
    
private:
    
    Point mCenter;
    int mRadius;
};

#endif /* defined(__Illustrator__Circle__) */
