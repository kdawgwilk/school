#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"


//
int g_x_5;
TEST(pointer, IS_HEAP_1) {
  bool r = is_heap(&g_x_5);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_HEAP_2) {
  static int x;
  bool r = is_heap(&x);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_HEAP_3) {
  int x;
  bool r = is_heap(&x);
  EXPECT_EQ(false, r);
}

//
TEST(pointer, IS_HEAP_4) {
  int *x = new int[3];
  bool r = is_heap(x);
  EXPECT_EQ(true, r);
  delete [] x;
  x = 0;
}
