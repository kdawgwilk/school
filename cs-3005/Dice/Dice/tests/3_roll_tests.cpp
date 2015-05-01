#include "Dice.h"
#include "Dice.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(Dice, ROLL_1) {
  int counts[6] = { 0, 0, 0, 0, 0, 0 };
  int i, x;
  Dice d;
  for(i = 0; i < 100; i++)
    {
      d.roll();
      x = d.getValue();
      /* check that each roll is in range */
      EXPECT_GE(x, 1);
      EXPECT_LE(x, 6);
      /* count the in-range rolls */
      if(x >= 1 && x <= 6)
        {
          counts[x-1] ++;
        }
    }
  /* make sure each number was rolled */
  for(i = 0; i < 6; i++)
    {
      EXPECT_GT(counts[i], 0);
    }
}
