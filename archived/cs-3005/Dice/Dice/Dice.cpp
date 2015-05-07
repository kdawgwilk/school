#include "Dice.h"
#include <cstdlib>

Dice::Dice()
    : num(1)
{

}

int Dice::getValue() const
{
    return num;
}

void Dice::roll()
{
    num = std::rand() % 6 + 1;
}
