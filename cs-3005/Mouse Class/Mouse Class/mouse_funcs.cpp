#include "Mouse.h"
#include "mouse_funcs.h"


Mouse click_center(int width, int height)
{
    Mouse m = Mouse();
    m.pushButton(1);
    m.setPosition(width / 2, height / 2);
    return m;
}
Mouse click_max(int width, int height)
{
    Mouse m = Mouse();
    m.pushButton(1);
    m.setPosition(width - 1, height - 1);
    return m;
}
Mouse unclick_center(int width, int height)
{
    Mouse m = Mouse();
    m.releaseButton();
    m.setPosition(width / 2, height / 2);
    return m;
}
Mouse unclick_max(int width, int height)
{
    Mouse m = Mouse();
    m.releaseButton();
    m.setPosition(width - 1, height - 1);
    return m;
}
