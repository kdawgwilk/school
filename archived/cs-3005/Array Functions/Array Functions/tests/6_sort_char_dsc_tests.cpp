#include "array_utils.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Arrays, SORTCHAR1) {
  const char answer[5] = { 'x', 'a', 'A', '0', ' ' };
  char array[5] = { ' ', '0', 'A', 'a', 'x' };
  int i;
  sort_char_dsc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTCHAR2) {
  const char answer[5] = { 'x', 'a', 'A', '0', ' ' };
  char array[5] = { 'x', 'a', 'A', '0', ' ' };
  int i;
  sort_char_dsc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTCHAR3) {
  const char answer[5] = { 'x', 'a', 'A', '0', ' ' };
  char array[5] = { 'a', '0', 'A', ' ', 'x' };
  int i;
  sort_char_dsc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTCHAR4) {
  const char answer[5] = { 'X', 'A', '@', '1', '%' };
  char array[5] = { 'X', '1', '%', '@', 'A' };
  int i;
  sort_char_dsc(array, 5);
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}

TEST(Arrays, SORTCHAR5) {
  const int count = 100;
  char answer[count];
  char array[count];
  int i, j;
  for(i = 0; i < count; i++)
    {
      answer[i] = count-i-1;
      array[i] = answer[i];
    }
  for(i = 0; i < count; i++)
    {
      j = std::rand() % count;
      char t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  sort_char_dsc(array, count);
  for(i = 0; i < count; i++)
    {
      EXPECT_EQ(answer[i], array[i]);
    }
}
