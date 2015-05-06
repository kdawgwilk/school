//
//  Slider.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/7/15.
//
//

#ifndef __Illustrator__Slider__
#define __Illustrator__Slider__

#include <cmath>
#include "Point.h"
#include "Button.h"


class Slider: public Button {
public:
    Slider(Point p1, const char *label, int id, double value, std::vector<double> color);
    
    void setColor(std::vector<double> color);
    void setValue(double value);
    std::vector<double> getOppositeColor();
//    virtual void draw();
//    bool contains(Point p);
    
    int getID();
    double getValue();
    
protected:
    
    double mValue;
    
private:
    
};

#endif /* defined(__Illustrator__Slider__) */
