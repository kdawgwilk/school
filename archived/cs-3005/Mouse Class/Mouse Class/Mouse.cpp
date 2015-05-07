#include "Mouse.h"

Mouse::Mouse()
{
  this->button = 0;
  this->x = 0;
  this->y = 0;
}

void Mouse::setPosition(int new_x, int new_y)
{
  this->x = new_x;
  this->y = new_y;
}

void Mouse::pushButton(int which_button)
{
  this->button = which_button;
}

void Mouse::releaseButton()
{
  this->button = 0;
}

int Mouse::getX()
{
  return this->x;
}

int Mouse::getY()
{
  return this->y;
}

int Mouse::getButton()
{
  return this->button;
}
