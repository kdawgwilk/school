#include "risk.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Risk, SORTINT1) {
  const int answer[5] = { 5, 4, 3, 2, 1 };
  int array[7] = { 0, 1, 2, 3, 4, 5, 6 };
  int i;
  sort_int_dsc(&array[1], 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i+1]);
    }
  EXPECT_EQ(0, array[0]);
  EXPECT_EQ(6, array[6]);
}

TEST(Risk, SORTINT2) {
  const int answer[5] = { 5, 4, 3, 2, 1 };
  int array[7] = { 0, 5, 4, 3, 2, 1, 6 };
  int i;
  sort_int_dsc(&array[1], 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i+1]);
    }
  EXPECT_EQ(0, array[0]);
  EXPECT_EQ(6, array[6]);
}

TEST(Risk, SORTINT3) {
  const int answer[5] = { 5, 4, 3, 2, 1 };
  int array[7] = { 0, 4, 3, 1, 2, 5, 6 };
  int i;
  sort_int_dsc(&array[1], 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i+1]);
    }
  EXPECT_EQ(0, array[0]);
  EXPECT_EQ(6, array[6]);
}

TEST(Risk, SORTINT4) {
  const int answer[5] = { 400, 234, -100, -200, -1000 };
  int array[7] = { 0, -100, -200, 400, 234, -1000, 6 };
  int i;
  sort_int_dsc(&array[1], 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i+1]);
    }
  EXPECT_EQ(0, array[0]);
  EXPECT_EQ(6, array[6]);
}

TEST(Risk, SORTINT5) {
  const int count = 100;
  int answer[count];
  int array[count];
  int i, j;
  for(i = 0; i < count; i++)
    {
      answer[i] = count/2 - i;
      array[i] = answer[i];
    }
  for(i = 0; i < count; i++)
    {
      j = std::rand() % count;
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  sort_int_dsc(array, count);
  for(i = 0; i < count; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}
