extern double plus_pi(double);

#include "gtest/gtest.h"

TEST(Arithmetic, Addition) {
  const double v = 4.5;
  const double r = v + 3.14;
  EXPECT_EQ(r, plus_pi(v));
}
