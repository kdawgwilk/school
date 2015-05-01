#include "exponent_quiz.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

void generate_exponents(const int min, const int max, int *exponents)
{
    int i;
    int c = 0;
    int pos;
    int tmp;
    for(i = min; i <= max; i++)
    {
        exponents[c++] = i;
    }
    for(i = 0; i < c; i++)
    {
        tmp = exponents[i];
        pos = std::rand() % c;
        exponents[i] = exponents[pos];
        exponents[pos] = tmp;

    }
}

long long power_2(const int exponent)
{
    long long result = 2;
    int i;
    if(exponent < 1)
    {
        return 1;
    }
    for(i = 1; i < exponent; i++)
    {
        result *= 2;
    }
    return result;
}

long long string_to_number(const char *str)
{
    long long result = 0;
    int c = 0;
    while(str[c] != '\0')
    {
        if(str[c] < 58 && str[c] > 47)
        {
            result = result * 10 + str[c] - '0';
            c++;
        } else
        {
            break;
        }
    }
    if(str[c] == 107 || str[c] == 75)//k = 107, K = 75
    {
        result *= 1024;
    } else if(str[c] == 109 || str[c] == 77)//m = 109, M = 77
    {
        result *= 1048576;
    } else if(str[c] == 98 || str[c] == 66)//b = 98, B = 66
    {
        result *= 1073741824;
    } else if(str[c] == 116 || str[c] == 84)//t = 116, T = 84
    {
        result *= 1099511627776;
    }
    return result;
}
