#include "array_utils.h"
#include "gtest/gtest.h"

TEST(Arrays, FINDCHAR1) {
  const char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  int result = find_char_linear(array, 5, 'a');
  EXPECT_EQ(0, result);
}

TEST(Arrays, FINDCHAR2) {
  const char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  int result = find_char_linear(array, 5, 'c');
  EXPECT_EQ(2, result);
}

TEST(Arrays, FINDCHAR3) {
  const char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  int result = find_char_linear(array, 5, 'e');
  EXPECT_EQ(4, result);
}

TEST(Arrays, FINDCHAR4) {
  const char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  int result = find_char_linear(array, 5, 'z');
  EXPECT_EQ(-1, result);
}

TEST(Arrays, FINDCHAR5) {
  const int count = 127;
  const int answer = count-2;
  char *array = new char[count];
  int i;
  for(i = 0; i < count; i++)
    {
      array[i] = count-i;
    }
  int result = find_char_linear(array, count, 2);
  EXPECT_EQ(answer, result);
  delete array;
}
