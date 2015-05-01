extern int third_remains(int);

#include "gtest/gtest.h"

TEST(Arithmetic, ModulusEven) {
  const int v = 18;
  const int r = v % 3;
  EXPECT_EQ(r, third_remains(v));
}

TEST(Arithmetic, ModulusOne) {
  const int v = 25;
  const int r = v % 3;
  EXPECT_EQ(r, third_remains(v));
}

TEST(Arithmetic, ModulusTwo) {
  const int v = 14;
  const int r = v % 3;
  EXPECT_EQ(r, third_remains(v));
}
