#include "vector_funcs.h"
#include "vector_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(vector, NEGATIVITY_1) {
  int size = 6;
  std::vector<int> v = negativity(size);
  int i;
  EXPECT_EQ(size, v.size());
  for(i = 0; i < size; i++)
    {
      EXPECT_EQ(-(i+1), v[i]);
    }
}

//
TEST(vector, NEGATIVITY_2) {
  int size = 100;
  std::vector<int> v = negativity(size);
  int i;
  EXPECT_EQ(size, v.size());
  for(i = 0; i < size; i++)
    {
      EXPECT_EQ(-(i+1), v[i]);
    }
}

//
TEST(vector, NEGATIVITY_3) {
  int size = 0;
  std::vector<int> v = negativity(size);
  EXPECT_EQ(size, v.size());
}

//
TEST(vector, NEGATIVITY_4) {
  int size = -100;
  std::vector<int> v = negativity(size);
  EXPECT_EQ(0, v.size());
}
