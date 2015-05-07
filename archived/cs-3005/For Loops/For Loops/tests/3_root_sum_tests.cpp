extern double root_sum(int, int);

#include "gtest/gtest.h"

//
TEST(root_sum, SIMPLE_1) {
  const int a = 1;
  const int b = 2;
  double v = root_sum(a, b);
  EXPECT_GT(2.4143, v);
  EXPECT_LT(2.4142, v);
}

TEST(root_sum, SIMPLE_2) {
  const int a = 1;
  const int b = 10;
  double v = root_sum(a, b);
  EXPECT_GT(22.469, v);
  EXPECT_LT(22.468, v);
}

TEST(root_sum, SIMPLE_3) {
  const int a = 10;
  const int b = 20;
  double v = root_sum(a, b);
  EXPECT_GT(42.37, v);
  EXPECT_LT(42.35, v);
}

TEST(root_sum, SIMPLE_4) {
  const int a = 100;
  const int b = 200;
  double v = root_sum(a, b);
  EXPECT_GT(1231.03, v);
  EXPECT_LT(1231.01, v);
}
