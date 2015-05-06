#ifndef _STUDENTAUX_H_
#define _STUDENTAUX_H_

#include "LinkedList.h"
#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>

int ReadStudentFile(const std::string &filename, LinkedList<Student> &students);
int RemoveStudents(const std::string &filename, LinkedList<Student> &students);
double AverageAgeStudents(const std::string &filename, LinkedList<Student> &students);

#endif