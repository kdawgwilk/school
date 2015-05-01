extern int factorial(int);

#include "gtest/gtest.h"

//
TEST(factorial, SIMPLE_1) {
  const int n = 1;
  int f = factorial(n);
  EXPECT_EQ(1, f);
}

//
TEST(factorial, SIMPLE_2) {
  const int n = 2;
  int f = factorial(n);
  EXPECT_EQ(2, f);
}

//
TEST(factorial, SIMPLE_3) {
  const int n = 3;
  int f = factorial(n);
  EXPECT_EQ(6, f);
}

//
TEST(factorial, SIMPLE_4) {
  const int n = 12;
  int f = factorial(n);
  EXPECT_EQ(479001600, f);
}

//
TEST(factorial, BOUNDS_LOWER_1) {
  const int n = 0;
  int f = factorial(n);
  EXPECT_EQ(1, f);
}

//
TEST(factorial, BOUNDS_LOWER_2) {
  const int n = -1;
  int f = factorial(n);
  EXPECT_EQ(1, f);
}


//
TEST(factorial, BOUNDS_LOWER_3) {
  const int n = -102;
  int f = factorial(n);
  EXPECT_EQ(1, f);
}

//
TEST(factorial, BOUNDS_UPPER_1) {
  const int n = 13;
  int f = factorial(n);
  EXPECT_EQ(-1, f);
}

//
TEST(factorial, BOUNDS_UPPER_2) {
  const int n = 14;
  int f = factorial(n);
  EXPECT_EQ(-1, f);
}

//
TEST(factorial, BOUNDS_UPPER_3) {
  const int n = 1230;
  int f = factorial(n);
  EXPECT_EQ(-1, f);
}
