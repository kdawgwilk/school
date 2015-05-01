#include "pointer_funcs.h"
#include <iostream>
#include <cmath>

int global = 0;

void add_from_pointer(int *x, int *y, int *z)
{
    *z = *x + *y;
}

void mul_from_pointer(int *x, int *y, int *z)
{
    *z = *x * *y;
}

bool is_global(int *num)
{
    int local = 0;
    int *heap = new int[0];
    int global_diff = abs(&global - num);
    int local_diff = abs(&local - num);
    int heap_diff = abs(heap - num);
    if (global_diff < local_diff && global_diff < heap_diff)
    {
        delete [] heap;
        return true;
    }
    delete [] heap;
    return false;
}

bool is_local(int *num)
{
    int local = 0;
    int *heap = new int[0];
    int global_diff = abs(&global - num);
    int local_diff = abs(&local - num);
    int heap_diff = abs(heap - num);
    if (local_diff < global_diff && local_diff < heap_diff)
    {
        delete [] heap;
        return true;
    }
    delete [] heap;
    return false;
}

bool is_heap(int *num)
{
    int local = 0;
    int *heap = new int[0];
    int global_diff = abs(&global - num);
    int local_diff = abs(&local - num);
    int heap_diff = abs(heap - num);
    if (heap_diff < global_diff && heap_diff < local_diff)
    {
        delete [] heap;
        return true;
    }
    delete [] heap;
    return false;
}
