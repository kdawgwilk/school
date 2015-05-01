#include "array_utils.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Arrays, SORTINT1) {
  const int answer[5] = { 1, 2, 3, 4, 5 };
  int array[5] = { 1, 2, 3, 4, 5 };
  int i;
  sort_int_asc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTINT2) {
  const int answer[5] = { 1, 2, 3, 4, 5 };
  int array[5] = { 5, 4, 3, 2, 1 };
  int i;
  sort_int_asc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTINT3) {
  const int answer[5] = { 1, 2, 3, 4, 5 };
  int array[5] = { 4, 3, 1, 2, 5 };
  int i;
  sort_int_asc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTINT4) {
  const int answer[5] = { -1000, -200, -100, 234, 400 };
  int array[5] = { -100, -200, 400, 234, -1000 };
  int i;
  sort_int_asc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTINT5) {
  const int count = 100;
  int answer[count];
  int array[count];
  int i, j;
  for(i = 0; i < count; i++)
    {
      answer[i] = i-count/2;
      array[i] = answer[i];
    }
  for(i = 0; i < count; i++)
    {
      j = std::rand() % count;
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  sort_int_asc(array, count);
  for(i = 0; i < count; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}
