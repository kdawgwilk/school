//
//  Rectangle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Rectangle__
#define __Illustrator__Rectangle__

#include "Point.h"


class Rectangle {
public:
    Rectangle(Point p1, Point p2);
    
    void setP1(Point p);
    void setP2(Point p);
    
    virtual void draw();
    
    Point getP1();
    Point getP2();
    
protected:
    
private:
    
    Point mP1;
    Point mP2;
    
};

#endif /* defined(__Illustrator__Rectangle__) */
