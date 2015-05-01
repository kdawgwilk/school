//
//  Triangle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Triangle__
#define __Illustrator__Triangle__

#include "Point.h"


class Triangle {
public:
    
    Triangle(Point p1, Point p2, Point p3);
    
    void setP1(Point p);
    void setP2(Point p);
    void setP3(Point p);
    
    virtual void draw();
    
    Point getP1();
    Point getP2();
    Point getP3();
    
protected:
    
private:
    
    Point mP1;
    Point mP2;
    Point mP3;
    
};

#endif /* defined(__Illustrator__Triangle__) */
