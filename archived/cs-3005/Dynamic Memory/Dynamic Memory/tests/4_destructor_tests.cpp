#include "NumberList.h"
#include "NumberList.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(number_list, destructor_1) {
  NumberList *nlptr = 0;
  {
    NumberList nl;
    nlptr = &nl; // NEVER DO THIS IN YOUR CODE

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

    // We didn't clear the number.  Your destructor should do the clear.
    // Check the ValGrind output.
  }

  // should be the NULL pointer at this time
  EXPECT_EQ((void*)0, nlptr->getNumbers());
  // should be no items at this time
  EXPECT_EQ(0, nlptr->getNumberCount());
}

//
TEST(number_list, destructor_2) {
  NumberList *nlptr = 0;
  {
    NumberList nl;
    nlptr = &nl;

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

    // We didn't clear the numbers.  Your destructor should do the clear.
    // Check the ValGrind output.
  }

  // should be the NULL pointer at this time
  EXPECT_EQ((void*)0, nlptr->getNumbers());
  // should be no items at this time
  EXPECT_EQ(0, nlptr->getNumberCount());
}
