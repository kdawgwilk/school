extern bool is_same(int a, int b);

#include "gtest/gtest.h"

TEST(Comparision, EQ1) {
  const int v = 6;
  const int r = 6;
  EXPECT_TRUE(is_same(v, r));
}

TEST(Comparision, EQ2) {
  const int v = 6;
  const int r = 6;
  EXPECT_TRUE(is_same(r, v));
}

TEST(Comparision, EQ3) {
  const int v = 6;
  const int r = 7;
  EXPECT_FALSE(is_same(r, v));
}

TEST(Comparision, EQ4) {
  const int v = 6;
  const int r = 7;
  EXPECT_FALSE(is_same(v, r));
}
