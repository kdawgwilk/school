#include "file_funcs.h"
#include "file_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

//
TEST(file_funcs, read_words_1) {
  std::srand(std::time(0));
  std::vector<std::string> original_words;
  original_words.push_back("great");
  original_words.push_back("green");
  original_words.push_back("gobs");
  original_words.push_back("of");
  original_words.push_back("greasy");
  original_words.push_back("grimey");
  original_words.push_back("gopher");
  original_words.push_back("guts");
  std::string filename = "ggg.txt";
  std::ofstream test_file(filename.c_str());
  size_t i;
  for(i = 0; i < original_words.size(); i++)
    {
      test_file << original_words[i] << std::endl;
    }
  test_file.close();

  std::vector<std::string> words = read_words(filename.c_str());

  EXPECT_EQ(words.size(), original_words.size());
  for(i = 0; i < std::min(original_words.size(), words.size()); i++)
    {
      EXPECT_EQ(words[i], original_words[i]);
    }

  // remove the file
  remove(filename.c_str());
}

//
TEST(file_funcs, read_words_2) {
  std::vector<std::string> original_words;
  original_words.push_back("great");
  original_words.push_back("green");
  original_words.push_back("gobs");
  original_words.push_back("of");
  original_words.push_back("greasy");
  original_words.push_back("grimey");
  original_words.push_back("gopher");
  original_words.push_back("guts");
  size_t i;
  size_t maxv = 1000;
  size_t next;
  for(i = 0; i < maxv; i++)
    {
      next = rand() % original_words.size();
      original_words.push_back(original_words[next]);
    }
  std::string filename = "hhh.txt";
  std::ofstream test_file(filename.c_str());
  for(i = 0; i < original_words.size(); i++)
    {
      test_file << original_words[i] << std::endl;
    }
  test_file.close();

  std::vector<std::string> words = read_words(filename.c_str());

  EXPECT_EQ(words.size(), original_words.size());
  for(i = 0; i < std::min(original_words.size(), words.size()); i++)
    {
      EXPECT_EQ(words[i], original_words[i]);
    }

  // remove the file
  remove(filename.c_str());
}
