#include "vector_funcs.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<int> negativity (int num)
{
    vector<int> v;
    int i;
    if (num < 1)
    {
        return v;
    }
    else
    {
        for (i = 1; i <= num; i++)
        {
            v.push_back(-i);
        }
        return v;
    }
}

int median (vector<int> v)
{
    int median;
    int size = v.size();
    if (size < 1)
    {
        return 0;
    }
    sort(v.begin(), v.end());
    if (size  % 2 == 0)
    {
        median = (v[size / 2 - 1] + v[size / 2]) / 2;
    }
    else
    {
        median = v[size / 2];
    }
    return median;
}
