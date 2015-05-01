#include "Dice.h"
#include "Dice.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(Dice, GET_VALUE_1) {
  Dice d;
  EXPECT_EQ(d.getValue(), 1); // make sure value is set in constructor
}
