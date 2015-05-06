//
//  Illustrator.h
//  Illustrator
//
//  Created by Kaden Wilkinson on 5/5/15.
//
//

#ifndef __Illustrator__Illustrator__
#define __Illustrator__Illustrator__

#include "Button.h"


class Illustrator
{
    
public:
    Illustrator();
    static void setMode(int id_in);
    static bool setColors(double index, double color);
    
    static int mMode;
    static std::vector<double> mColor;
};

#endif /* defined(__Illustrator__Illustrator__) */
