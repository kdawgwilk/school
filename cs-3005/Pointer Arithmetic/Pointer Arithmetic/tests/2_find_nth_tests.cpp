#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(pointer, FIND_NTH_1) {
  double x[5], *y;
  y = find_nth(&x[3], 1);
  EXPECT_EQ(&x[4], y);
}

//
TEST(pointer, FIND_NTH_2) {
  double x[5], *y;
  y = find_nth(&x[0], 1);
  EXPECT_EQ(&x[1], y);
}

//
TEST(pointer, FIND_NTH_3) {
  double x[5], *y;
  y = find_nth(x, 1);
  EXPECT_EQ(&x[1], y);
}

//
TEST(pointer, FIND_NTH_4) {
  double x[5], *y;
  y = find_nth(&x[1], 1);
  EXPECT_EQ(&x[2], y);
}

//
TEST(pointer, FIND_NTH_5) {
  double x[5], *y;
  y = find_nth(&x[0], 2);
  EXPECT_EQ(&x[2], y);
}
//
TEST(pointer, FIND_NTH_6) {
  double x[5], *y;
  y = find_nth(&x[0], 4);
  EXPECT_EQ(&x[4], y);
}
//
TEST(pointer, FIND_NTH_7) {
  double x[5], *y;
  y = find_nth(&x[1], 3);
  EXPECT_EQ(&x[4], y);
}
