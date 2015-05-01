#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"


//
int g_x_3;
TEST(pointer, IS_GLOBAL_1) {
  bool r = is_global(&g_x_3);
  EXPECT_EQ(true, r);
}

//
TEST(pointer, IS_GLOBAL_2) {
  static int x;
  bool r = is_global(&x);
  EXPECT_EQ(true, r);
}

//
TEST(pointer, IS_GLOBAL_3) {
  int x;
  bool r = is_global(&x);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_GLOBAL_4) {
  int *x = new int[3];
  bool r = is_global(x);
  EXPECT_EQ(false, r);
  delete [] x;
  x = 0;
}
