#include "string_funcs.h"
#include <iostream>


int strlength (const char s[])
{
    int c = 0;
    while (s[c] != '\0') { c++; }
    std::cout << "Length:" << c << std::endl;
    return c;
}

void strcopy (char dest[], const char src[])
{
    const int length = strlength(src);
    int i;
    for (i = 0; i <= length; i++)
    {
        dest[i] = src[i];
    }
}

void strrcpy (char dest[], const char src[])
{
    const int length = strlength(src);
    int i;
    for (i = 0; i <= length; i++)
    {
        dest[i] = src[length - i - 1];
    }
    std::cout << "Copy: " << dest << std::endl;
}

void strrev (char s[])
{
    const int length = strlength(s);
    //How do I set the length of dest to variable length above
    char dest[16];
    int i;
    std::cout << "Original: " << s << std::endl;
    for (i = 0; i <= length; i++)
    {
        dest[i] = s[length - i - 1];
    }
    for (i = 0; i <= length; i++)
    {
        s[i] = dest[i];
    }
    std::cout << "Reversed: " << s << std::endl;
}
