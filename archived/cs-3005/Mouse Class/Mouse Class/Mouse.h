#ifndef _MOUSE_H_
#define _MOUSE_H_

class Mouse
{
public:
  Mouse();
  void setPosition(int new_x, int new_y);
  void pushButton(int which_button);
  void releaseButton();
  int getX();
  int getY();
  int getButton();

private:
  int x, y;
  int button;
};

#endif /* _MOUSE_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
