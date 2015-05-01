#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(pointer, ADD_FROM_POINTER_1) {
  int x, y, z;
  x = 1;
  y = 2;
  add_from_pointer(&x, &y, &z);
  EXPECT_EQ(1, x);
  EXPECT_EQ(2, y);
  EXPECT_EQ(3, z);
}

//
TEST(pointer, ADD_FROM_POINTER_2) {
  int x, y, z;
  x = -100;
  y = 50;
  add_from_pointer(&x, &y, &z);
  EXPECT_EQ(-100, x);
  EXPECT_EQ(50, y);
  EXPECT_EQ(-50, z);
}
