#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"


//
int g_x_4;
TEST(pointer, IS_LOCAL_1) {
  bool r = is_local(&g_x_4);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_LOCAL_2) {
  static int x;
  bool r = is_local(&x);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_LOCAL_3) {
  int x;
  bool r = is_local(&x);
  EXPECT_EQ(true, r);
}

//
TEST(pointer, IS_LOCAL_4) {
  int *x = new int[3];
  bool r = is_local(x);
  EXPECT_EQ(false, r);
  delete [] x;
  x = 0;
}
