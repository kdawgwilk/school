extern int minus_13(int);

#include "gtest/gtest.h"

TEST(Arithmetic, Subtraction) {
  const int v = 39;
  const int r = v - 13;
  EXPECT_EQ(r, minus_13(v));
}
