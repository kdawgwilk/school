#include "vector_funcs.h"
#include "vector_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"
#include <cstdlib>
#include <ctime>

//
TEST(vector, MEDIAN_1) {
  std::srand(std::time(0));
  std::vector<int> v;
  v.push_back(8);
  v.push_back(4);
  v.push_back(3);
  v.push_back(7);
  v.push_back(5);
  int m = median(v);
  EXPECT_EQ(5, m);
}

//
TEST(vector, MEDIAN_2) {
  std::vector<int> v;
  v.push_back(8);
  v.push_back(4);
  v.push_back(3);
  v.push_back(7);
  v.push_back(5);
  v.push_back(6);
  int m = median(v);
  EXPECT_EQ(5, m);
}

//
TEST(vector, MEDIAN_3) {
  std::vector<int> v;
  v.push_back(8);
  v.push_back(4);
  v.push_back(3);
  v.push_back(7);
  v.push_back(5);
  v.push_back(7);
  int m = median(v);
  EXPECT_EQ(6, m);
}

//
TEST(vector, MEDIAN_4) {
  std::vector<int> v;
  int m = median(v);
  EXPECT_EQ(0, m);
}
