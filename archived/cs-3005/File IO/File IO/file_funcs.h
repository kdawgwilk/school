#ifndef _FILE_FUNCS_H_
#define _FILE_FUNCS_H_

#include <vector>
#include <iostream>
#include <fstream>


std::vector<std::string> read_words(const char *);
bool write_words(const char *filename, std::vector<std::string> words);
bool copy_file(const char *ifilename, const char *ofilename);


#endif //_FILE_FUNCS_H_
