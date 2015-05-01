extern bool is_larger(double a, double b);

#include "gtest/gtest.h"

TEST(Comparision, GT1) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_TRUE(is_larger(v, r));
}

TEST(Comparision, GT2) {
  const double v = 4.5;
  const double r = 3.14;
  EXPECT_FALSE(is_larger(r, v));
}

TEST(Comparision, GT3) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_FALSE(is_larger(v, r));
}

TEST(Comparision, GT4) {
  const double v = 4.5;
  const double r = 4.5;
  EXPECT_FALSE(is_larger(r, v));
}
