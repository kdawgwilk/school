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
TEST(file_funcs, write_words_1) {
  std::vector<std::string> original_words;
  original_words.push_back("great");
  original_words.push_back("green");
  original_words.push_back("gobs");
  original_words.push_back("of");
  original_words.push_back("greasy");
  original_words.push_back("grimey");
  original_words.push_back("gopher");
  original_words.push_back("guts");
  std::vector<std::string> copy_original_words = original_words;
  std::string filename = "g3.txt";
  EXPECT_EQ(write_words(filename.c_str(), copy_original_words), true);

  size_t i;
  EXPECT_EQ(copy_original_words.size(), original_words.size());
  for(i = 0; i < std::min(original_words.size(), copy_original_words.size()); i++)
    {
      EXPECT_EQ(copy_original_words[i], original_words[i]);
    }

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
TEST(file_funcs, write_words_2) {
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
  std::vector<std::string> copy_original_words = original_words;
  std::string filename = "h3.txt";
  EXPECT_EQ(write_words(filename.c_str(), copy_original_words), true);

  EXPECT_EQ(copy_original_words.size(), original_words.size());
  for(i = 0; i < std::min(original_words.size(), copy_original_words.size()); i++)
    {
      EXPECT_EQ(copy_original_words[i], original_words[i]);
    }

  std::vector<std::string> words = read_words(filename.c_str());
  EXPECT_EQ(words.size(), original_words.size());
  for(i = 0; i < std::min(original_words.size(), words.size()); i++)
    {
      EXPECT_EQ(words[i], original_words[i]);
    }

  // remove the file
  remove(filename.c_str());
}
