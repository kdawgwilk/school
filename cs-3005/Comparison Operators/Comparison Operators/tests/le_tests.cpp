extern bool is_not_larger(int a, int b);

#include "gtest/gtest.h"

TEST(Comparision, LE1) {
  const int v = 6;
  const int r = 6;
  EXPECT_TRUE(is_not_larger(v, r));
}

TEST(Comparision, LE2) {
  const int v = 6;
  const int r = 6;
  EXPECT_TRUE(is_not_larger(r, v));
}

TEST(Comparision, LE3) {
  const int v = 6;
  const int r = 7;
  EXPECT_FALSE(is_not_larger(r, v));
}

TEST(Comparision, LE4) {
  const int v = 6;
  const int r = 7;
  EXPECT_TRUE(is_not_larger(v, r));
}
