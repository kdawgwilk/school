#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(pointer, FIND_NEXT_1) {
  double x[5], *y;
  y = find_next(&x[3]);
  EXPECT_EQ(&x[4], y);
}

//
TEST(pointer, FIND_NEXT_2) {
  double x[5], *y;
  y = find_next(&x[0]);
  EXPECT_EQ(&x[1], y);
}

//
TEST(pointer, FIND_NEXT_3) {
  double x[5], *y;
  y = find_next(x);
  EXPECT_EQ(&x[1], y);
}

//
TEST(pointer, FIND_NEXT_4) {
  double x[5], *y;
  y = find_next(&x[1]);
  EXPECT_EQ(&x[2], y);
}
