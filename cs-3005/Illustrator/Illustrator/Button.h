//
//  Button.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Button__
#define __Illustrator__Button__


#include "Rectangle.h"


class Button: public Rectangle {
public:
    
    Button(Point p1, const char *label, int id, std::vector<double> color);
    
    virtual void draw();
    virtual void setColor(std::vector<double> color);

    bool contains(Point p);
    void setActive(bool state);
    int getID();

protected:
    const char *mLabel;
    bool mActive;
    int mID;
    
private:
    
};

#endif /* defined(__Illustrator__Button__) */
