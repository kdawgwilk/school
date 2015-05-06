//
//  Rectangle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Rectangle__
#define __Illustrator__Rectangle__

#include <cmath>
#include "Shape.h"
#include "Point.h"


class Rectangle: public Shape {
public:
    Rectangle(Point p1, Point p2, std::vector<double> color);
    
    void setP1(Point p);
    void setP2(Point p);
    
    virtual void draw();
    virtual void save(std::ostream &os) const;
    
    Point getP1();
    Point getP2();
    
protected:
    
    Point mP1;
    Point mP2;
    
private:
    
    
};

#endif /* defined(__Illustrator__Rectangle__) */
