extern bool is_smaller(int a, int b);

#include "gtest/gtest.h"

TEST(Comparision, LT1) {
  const int v = 6;
  const int r = 6;
  EXPECT_FALSE(is_smaller(v, r));
}

TEST(Comparision, LT2) {
  const int v = 6;
  const int r = 6;
  EXPECT_FALSE(is_smaller(r, v));
}

TEST(Comparision, LT3) {
  const int v = 6;
  const int r = 7;
  EXPECT_FALSE(is_smaller(r, v));
}

TEST(Comparision, LT4) {
  const int v = 6;
  const int r = 7;
  EXPECT_TRUE(is_smaller(v, r));
}
