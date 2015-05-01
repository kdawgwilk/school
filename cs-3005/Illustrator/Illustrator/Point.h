//
//  Point.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Point__
#define __Illustrator__Point__


class Point {
public:
    
    Point(int x, int y);
    void setX(int x);
    void setY(int y);
    
    void draw();
    
    int getX();
    int getY();
    
protected:
    
private:
    
    int mX;
    int mY;
    
};

#endif /* defined(__Illustrator__Point__) */
