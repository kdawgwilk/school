#include "array_utils.h"


int smallest_int(const int a[], const int size)
{
    int s = a[0];
    int i;
    for (i = 0; i <= size; i++)
    {
        if (a[i] <= s && a[i] != 0)
        {
            s = a[i];
        }
    }
    return s;
}

char largest_char(const char a[], const int size)
{
    char s = a[0];
    int i;
    for (i = 0; i < size; i++)
    {
        if (a[i] >= s && a[i] != 0)
        {
            s = a[i];
        }
    }
    return s;
}

int find_int_linear(const int a[], const int size, const int item)
{
    int s = 0;
    int i;
    for (i = 0; i <= size; i++)
    {
        if (a[i] == item)
        {
            s = i;
            break;
        }
        else {
            s = -1;
        }
    }
    return s;
}

int find_char_linear(const char a[], const int size, const char item)
{
    int s = 0;
    int i;
    for (i = 0; i <= size; i++)
    {
        if (a[i] == item)
        {
            s = i;
            break;
        }
        else {
            s = -1;
        }
    }
    return s;
}

void sort_int_asc(int a[], const int size)
{
    bool swapped = true;
    int j = 0;
    int tmp, i;
    while (swapped) {
        swapped = false;
        j++;
        for (i = 0; i < size - j; i++) {
              if (a[i] > a[i + 1]) {
                    tmp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tmp;
                    swapped = true;
              }
        }
    }
}

void sort_char_dsc(char a[], const int size)
{
    bool swapped = true;
    int j = 0;
    char tmp;
    int i;
    while (swapped) {
        swapped = false;
        j++;
        for (i = 0; i < size - j; i++) {
              if (a[i] < a[i + 1]) {
                    tmp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tmp;
                    swapped = true;
              }
        }
    }
}

int find_int_binary(const int a[], const int size, const int item)
{
    int left = 0;
    int right = size - 1;
    int mid;
    int s = -1;

    while (left <= right)
    {
    	mid = ((left + right) / 2);
    	if (item == a[mid])
    	{
    		s = mid;
    		return s;
    	}
        else if (item > a[mid])
        {
        	left = mid + 1;
        }
        else
        {
        	right = mid - 1;
        }
    }
    return s;
}

int find_char_binary(const char a[], const int size, const char item)
{
    int left = 0;
    int right = size - 1;
    int mid;
    int s = -1;

    while (left <= right)
    {
    	mid = ((left + right) / 2);
    	if (item == a[mid])
    	{
    		s = mid;
    		return s;
    	}
        else if (item > a[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return s;
}
