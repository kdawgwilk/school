#include "risk.h"
#include "gtest/gtest.h"
#include <cstdlib>
#include <ctime>

TEST(Risk, ROLL_DIE_1) {
  std::srand(std::time(0));
  int i, result;
  int counts[6] = { 0, 0, 0, 0, 0, 0 };
  for(i = 0; i < 100; i++)
    {
      result = roll_die(6);
      EXPECT_GE(result, 1);
      EXPECT_LE(result, 6);
      if(result >= 1 && result <= 6)
        {
          counts[result-1]++;
        }
    }
  for(i = 0; i < 6; i++)
    {
      EXPECT_NE(0, counts[i]);
    }
}
