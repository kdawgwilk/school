#include "array_utils.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Arrays, LARGECHAR1) {
  const char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  char result = largest_char(array, 5);
  EXPECT_EQ('e', result);
}

TEST(Arrays, LARGECHAR2) {
  const char array[5] = { 'a', 'Z', 'A', 'X', 'E' };
  char result = largest_char(array, 5);
  EXPECT_EQ('a', result);
}

TEST(Arrays, LARGECHAR3) {
  const char array[5] = { ' ', '0', 'z', '\r', '\n' };
  char result = largest_char(array, 5);
  EXPECT_EQ('z', result);
}

TEST(Arrays, LARGECHAR4) {
  const char array[5] = { 5, 87, 22, 42, 65 };
  char result = largest_char(array, 5);
  EXPECT_EQ(87, result);
}

TEST(Arrays, LARGECHAR5) {
  const char array[5] = { 'a' };
  char result = largest_char(array, 1);
  EXPECT_EQ('a', result);
}

TEST(Arrays, LARGECHAR6) {
  const int count = 100;
  const char answer = count-1;
  char array[count];
  int i, j;
  for(i = 0; i < count; i++)
    {
      array[i] = i;
    }
  for(i = 0; i < count; i++)
    {
      j = std::rand() % count;
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  char result = largest_char(array, count);
  EXPECT_EQ(answer, result);
}
