extern bool is_different(double a, double b);

#include "gtest/gtest.h"

TEST(Comparision, NE1) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_TRUE(is_different(v, r));
}

TEST(Comparision, NE2) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_TRUE(is_different(r, v));
}

TEST(Comparision, NE3) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_FALSE(is_different(v, r));
}

TEST(Comparision, NE4) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_FALSE(is_different(r, v));
}
