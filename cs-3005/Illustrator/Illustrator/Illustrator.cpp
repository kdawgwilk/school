//
//  Illustrator.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 5/5/15.
//
//

#include "Illustrator.h"


//std::vector<Button> Illustrator::buttons (8);
//int Illustrator::mode;
//std::vector<double> Illustrator::colors (3);

Illustrator::Illustrator()
{
    mode = -1;
    colors.push_back(1);
    colors.push_back(0);
    colors.push_back(0);
}

void Illustrator::setMode(int id_in)
{
    mode = id_in;
    for(unsigned int i=0; i<buttons.size(); i++)
    {
        if(buttons[i].mID == id_in)
            buttons[i].mActive = true;
        else
            buttons[i].mActive = false;
    }
}

bool Illustrator::setColors(double index, double color)
{
    colors[index] = color;
    return true;
}