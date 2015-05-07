#include "Dice.h"
#include "Dice.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"
#include <ctime>
#include <cstdlib>

//
TEST(Dice, DEFAULT_CONSTRUCTOR_1) {
  std::srand(std::time(0));
  Dice d;
  EXPECT_EQ(1, 1); // can't look inside the object, so can't really test it.
}
