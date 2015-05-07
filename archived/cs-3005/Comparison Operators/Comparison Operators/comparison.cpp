bool is_smaller (int a, int b)
{
    if (a < b)
    {
        return true;
    }
    return false;
}

bool is_larger (double a, double b)
{
    if (a > b)
    {
        return true;
    }
    return false;
}

bool is_not_larger (int a, int b)
{
    if (a <= b)
    {
        return true;
    }
    return false;
}

bool is_not_smaller (double a, double b)
{
    if (a >= b)
    {
        return true;
    }
    return false;
}

bool is_same (int a, int b)
{
    if (a == b)
    {
        return true;
    }
    return false;
}

bool is_different (double a, double b)
{
    if (a != b)
    {
        return true;
    }
    return false;
}
