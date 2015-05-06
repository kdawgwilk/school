//
//  Triangle.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Triangle__
#define __Illustrator__Triangle__

#include <cmath>
#include "Shape.h"
#include "Point.h"


class Triangle: public Shape {
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3, std::vector<double> color);
    
    void setP1(Point p);
    void setP2(Point p);
    void setP3(Point p);
    
    virtual void draw();
    virtual void setColor(std::vector<double> color);
    virtual void save(std::ostream &os);
    virtual void load(std::istream &is);
    
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
