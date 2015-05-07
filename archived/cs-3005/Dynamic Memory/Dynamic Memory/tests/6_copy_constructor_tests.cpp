#include "NumberList.h"
#include "NumberList.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(number_list, copy_constructor_1) {
  NumberList nl;

  // should be the NULL pointer at this time
  EXPECT_EQ((void*)0, nl.getNumbers());
  // should be no items at this time
  EXPECT_EQ(0, nl.getNumberCount());

  // add a number
  EXPECT_EQ(true, nl.addNumber(6));
  // should not be the NULL pointer at this time
  EXPECT_NE((void*)0, nl.getNumbers());
  // should be one item at this time
  EXPECT_EQ(1, nl.getNumberCount());

  NumberList nl2(nl);

  // should not be the NULL pointer at this time
  EXPECT_NE((void*)0, nl2.getNumbers());
  // should be one item at this time
  EXPECT_EQ(1, nl2.getNumberCount());

  // should not be the same pointer
  EXPECT_NE(nl.getNumbers(), nl2.getNumbers());
}

//
TEST(number_list, copy_constructor_2) {
  NumberList nl;

  // should be the NULL pointer at this time
  EXPECT_EQ((void*)0, nl.getNumbers());
  // should be no items at this time
  EXPECT_EQ(0, nl.getNumberCount());

  // add a bunch of numbers
  int i, count = 100;
  for(i = 0; i < count; i++)
    {
      EXPECT_EQ(true, nl.addNumber(6));
    }
  // should not be the NULL pointer at this time
  EXPECT_NE((void*)0, nl.getNumbers());
  // should be count items at this time
  EXPECT_EQ(count, nl.getNumberCount());

  NumberList nl2(nl);

  // should not be the NULL pointer at this time
  EXPECT_NE((void*)0, nl2.getNumbers());
  // should be count items at this time
  EXPECT_EQ(count, nl2.getNumberCount());

  // should not be the same pointer
  EXPECT_NE(nl.getNumbers(), nl2.getNumbers());
}
