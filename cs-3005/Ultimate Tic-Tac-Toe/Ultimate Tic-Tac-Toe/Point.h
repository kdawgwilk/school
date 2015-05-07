//
//  Point.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#ifndef __Ultimate_Tic_Tac_Toe__Point__
#define __Ultimate_Tic_Tac_Toe__Point__

#include "Headers.h"

class Point {
public:
    
    Point();
    Point(double x, double y);
    
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    
//    virtual void draw();
//    virtual void setColor(std::vector<double> color);
//    virtual void save(std::ostream &os);
//    virtual void load(std::istream &is);
    
    
protected:
    
private:
    
    double mX;
    double mY;    
};

std::ostream &operator<<(std::ostream &os, const Point &rhs);
std::istream &operator>>(std::istream &is, Point &rhs);


#endif /* defined(__Ultimate_Tic_Tac_Toe__Point__) */
