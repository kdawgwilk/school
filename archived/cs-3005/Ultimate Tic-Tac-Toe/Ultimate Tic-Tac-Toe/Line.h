//
//  Line.h
//  Ultimate Tic-Tac-Toe
//
//  Created by Kaden Wilkinson on 5/6/15.
//
//

#ifndef __Ultimate_Tic_Tac_Toe__Line__
#define __Ultimate_Tic_Tac_Toe__Line__

#include "Point.h"


class Line {
public:
    
    Line(Point p1, Point p2);
    
    void draw();
    
    void setLP1(Point p);
    void setLP2(Point p);
    void setP1(Point p);
    void setP2(Point p);
    void setP3(Point p);
    void setP4(Point p);
    Point getLP1();
    Point getLP2();
    Point getP1();
    Point getP2();
    Point getP3();
    Point getP4();
    
    
    
protected:
    
    double mWidth;
    bool mVertical;
    Point mLP1;
    Point mLP2;
    
    Point mP1;
    Point mP2;
    Point mP3;
    Point mP4;
    
private:
    
    
};


#endif /* defined(__Ultimate_Tic_Tac_Toe__Line__) */
