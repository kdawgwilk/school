#include "NumberList.h"
#include "NumberList.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(number_list, get_numbers_1) {
  NumberList nl;
  // should be the NULL pointer at this time
  EXPECT_EQ(0, nl.getNumbers());
}

//
TEST(number_list, get_number_count_1) {
  NumberList nl;
  // should be no items at this time
  EXPECT_EQ(0, nl.getNumberCount());
}
