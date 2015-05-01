
#include <cmath>


int factorial (int num)
{
    int t = 1;
    int i;
    if (num > 12)
    {
        return -1;
    }
    else
    {
        for (i = 1; i <= num; i++)
        {
            t *= i;
        }
    }
    return t;
}

int add_em (int a, int b)
{
    int t = 0;
    int i;
    if (a == b)
    {
        return a;
    }
    else if (a < b)
    {
        for (i = 0; i <= b - a; i++)
        {
            t += a + i;
        }
        return t;
    }
    else if (a > b)
    {
        for (i = 0; i <= a - b; i++)
        {
            t += b + i;
        }
        return t;
    }
    else
    {
        return t;
    }
}

double root_sum (int a, int b)
{
    double t;
    int i;
    for (i = 0; i <= b - a; i++)
    {
        t += std::sqrt(a + i);
    }
    return t;
}
