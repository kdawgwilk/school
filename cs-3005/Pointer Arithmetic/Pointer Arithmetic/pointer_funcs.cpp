#include "pointer_funcs.h"
#include <iostream>


double *find_next(double *p)
{
    return p + 1;
}

double *find_nth(double *adr, int num)
{
    return adr + num;
}

long long int get_value(long long int *adr)
{
    return *adr;
}

int get_nth_value(long long int *adr, int num)
{
    return adr[num];
}
