extern int divide_half(int);

#include "gtest/gtest.h"

TEST(Arithmetic, DivisionEven) {
  const int v = 16;
  const int r = v / 2;
  EXPECT_EQ(r, divide_half(v));
}

TEST(Arithmetic, DivisionOdd) {
  const int v = 9;
  const int r = v / 2;
  EXPECT_EQ(r, divide_half(v));
}
