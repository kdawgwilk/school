#include "risk.h"
#include "gtest/gtest.h"

TEST(Risk, ROLL_PLAYER_1) {
  const int bad1 = -131313;
  const int bad2 =  131313;
  int array[5] = { bad1, bad1, bad1, bad2, bad2 };
  roll_player(&array[1], 3);
  EXPECT_EQ(bad1, array[0]);
  EXPECT_NE(bad1, array[1]);
  EXPECT_NE(bad2, array[1]);
  EXPECT_NE(bad1, array[2]);
  EXPECT_NE(bad2, array[2]);
  EXPECT_NE(bad1, array[3]);
  EXPECT_NE(bad2, array[3]);
  EXPECT_EQ(bad2, array[4]);

  EXPECT_LE(1, array[1]);
  EXPECT_GE(6, array[1]);
  EXPECT_LE(1, array[2]);
  EXPECT_GE(6, array[2]);
  EXPECT_LE(1, array[3]);
  EXPECT_GE(6, array[3]);

  EXPECT_GE(array[1], array[2]);
  EXPECT_GE(array[2], array[3]);
}
