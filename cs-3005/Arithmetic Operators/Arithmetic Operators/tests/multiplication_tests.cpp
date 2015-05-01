extern unsigned int times_luck(unsigned int);

#include "gtest/gtest.h"

TEST(Arithmetic, Multiplication) {
  const unsigned int v = 9;
  const unsigned int r = v * 7;
  EXPECT_EQ(r, times_luck(v));
}

TEST(Arithmetic, MultiplicationUnsigned) {
  const unsigned int v = -9;
  const unsigned int r = v * 7;
  EXPECT_EQ(r, times_luck(v));
}
