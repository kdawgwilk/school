#include "pointer_funcs.h"
#include "pointer_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(pointer, GET_NTH_VALUE_1) {
  long long int x[5] = { 987654321L, -987654321L, 123456789L, -123456789L, 0L };
  long long int y;
  int i;
  for(i = 0; i < 5; i++)
    {
      y = get_nth_value(&x[0], i);
      EXPECT_EQ(x[i], y);
    }
}
