//
//  Square.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#ifndef __Ultimate_Tic_Tac_Toe__Square__
#define __Ultimate_Tic_Tac_Toe__Square__

#include "Headers.h"
#include "Point.h"


class Square {
public:
    
    Square();
    Square(Point p1, Point p2);
    
    void setP1(Point p);
    void setP2(Point p);
    Point getP1();
    Point getP2();
    
    double getLeft();
    double getBottom();
    double getWidth();
    double getHeight();
    
    virtual void draw();
//    virtual void setColor(std::vector<double> color);
    
protected:
    
    Point mP1;
    Point mP2;
    
private:
    
    
};


#endif /* defined(__Ultimate_Tic_Tac_Toe__Square__) */
