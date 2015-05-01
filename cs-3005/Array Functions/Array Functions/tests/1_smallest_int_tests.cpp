#include "array_utils.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Arrays, SMALLINT1) {
  const int array[5] = { 1, 2, 3, 4, 5 };
  int result = smallest_int(array, 5);
  EXPECT_EQ(1, result);
}

TEST(Arrays, SMALLINT2) {
  const int array[5] = { 5, 4, 3, 2, 1 };
  int result = smallest_int(array, 5);
  EXPECT_EQ(1, result);
}

TEST(Arrays, SMALLINT3) {
  const int array[5] = { -1, -2, -3, -4, -5 };
  int result = smallest_int(array, 5);
  EXPECT_EQ(-5, result);
}

TEST(Arrays, SMALLINT4) {
  const int array[5] = { 999 };
  int result = smallest_int(array, 1);
  EXPECT_EQ(999, result);
}

TEST(Arrays, SMALLINT5) {
  const int array[5] = { 7234, 324543, 2332, 111122, 45464343 };
  int result = smallest_int(array, 5);
  EXPECT_EQ(2332, result);
}


TEST(Arrays, SMALLINT6) {
  const int count = 100;
  const int answer = -count/2;
  int array[count];
  int i, j;
  for(i = 0; i < count; i++)
    {
      array[i] = i-count/2;
    }
  for(i = 0; i < count; i++)
    {
      j = std::rand() % count;
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  int result = smallest_int(array, count);
  EXPECT_EQ(answer, result);
}
