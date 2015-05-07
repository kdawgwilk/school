extern bool is_not_smaller(double a, double b);

#include "gtest/gtest.h"

TEST(Comparision, GE1) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_TRUE(is_not_smaller(v, r));
}

TEST(Comparision, GE2) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_FALSE(is_not_smaller(r, v));
}

TEST(Comparision, GE3) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_TRUE(is_not_smaller(v, r));
}

TEST(Comparision, GE4) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_TRUE(is_not_smaller(r, v));
}
