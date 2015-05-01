#ifndef _STUDENTAUX_H_
#define _STUDENTAUX_H_

#include "StudentLinkedList.h"
#include <vector>
#include <iostream>
#include <fstream>

int ReadStudentFile(const std::string &filename, StudentLinkedList &students);
int RemoveStudents(const std::string &filename, StudentLinkedList &students);
double AverageAgeStudents(const std::string &filename, StudentLinkedList &students);

#endif