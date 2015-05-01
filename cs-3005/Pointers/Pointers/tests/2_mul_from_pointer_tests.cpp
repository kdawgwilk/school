#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(pointer, MUL_FROM_POINTER_1) {
  int x, y, z;
  x = 1;
  y = 2;
  mul_from_pointer(&x, &y, &z);
  EXPECT_EQ(1, x);
  EXPECT_EQ(2, y);
  EXPECT_EQ(2, z);
}

//
TEST(pointer, MUL_FROM_POINTER_2) {
  int x, y, z;
  x = -100;
  y = 50;
  mul_from_pointer(&x, &y, &z);
  EXPECT_EQ(-100, x);
  EXPECT_EQ(50, y);
  EXPECT_EQ(-5000, z);
}

//
TEST(pointer, MUL_FROM_POINTER_3) {
  int x, y, z;
  x = 2;
  y = 3;
  mul_from_pointer(&x, &y, &z);
  EXPECT_EQ(2, x);
  EXPECT_EQ(3, y);
  EXPECT_EQ(6, z);
}
