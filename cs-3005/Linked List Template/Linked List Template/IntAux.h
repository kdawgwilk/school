

#ifndef _INTAUX_H_
#define _INTAUX_H_

#include "LinkedList.h"
#include <vector>
#include <iostream>
#include <fstream>

int ReadIntFile(const std::string &filename, LinkedList<int> &nums);
int RemoveInts(const std::string &filename, LinkedList<int> &nums);
double AverageValue(const std::string &filename, LinkedList<int> &nums);

#endif
