#include "NumberList.h"
#include <iostream>

NumberList::NumberList()
    : mListLength(0),
    mNumArray(0)
{
    //Empty
}

NumberList::~NumberList()
{
    clear();
}

NumberList &NumberList::operator=(const NumberList &rhs)
{
    int i;
    int rhs_count = rhs.getNumberCount();
    const int * tmp = rhs.getNumbers();
    clear();
    for(i = 0; i < rhs_count; i++) {
        addNumber(tmp[i]);
    }
    return *this;
}

NumberList::NumberList(const NumberList &src)
    : mListLength(0),
    mNumArray(0)
{
    *this = src;
}

const int *NumberList::getNumbers() const
{
    return mNumArray;
}

int NumberList::getNumberCount() const
{
    return mListLength;
}

bool NumberList::addNumber(int new_num)
{
    int i;
    int count = getNumberCount();
    std::cout << "Count: " << count << "\n";
    int * tmp = new int[count + 1];

    // if memory was allocated, copy the data
    if(tmp)
    {
        for(i = 0; i < count; i++) {
            tmp[i] = mNumArray[i];
        }
        tmp[count] = new_num;

        if(mNumArray)
        {
            delete [] mNumArray;
            mNumArray = 0;
        }
        mNumArray = tmp;
        count++;
        mListLength = count;
        return true;
    }
    else
    {
        return false;
    }
    delete [] tmp;
    tmp = 0;
}

bool NumberList::clear()
{
    delete [] mNumArray;
    mNumArray = 0;
    mListLength = 0;
    return true;
}
