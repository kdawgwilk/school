#include "array_utils.h"
#include "gtest/gtest.h"

TEST(Arrays, FINDCHARBIN1) {
  const char array[5] = { 5, 4, 3, 2, 1 };
  int result = find_char_binary(array, 5, 1);
  EXPECT_EQ(4, result);
}

TEST(Arrays, FINDCHARBIN2) {
  const char array[5] = { 5, 4, 3, 2, 1 };
  int result = find_char_binary(array, 5, 3);
  EXPECT_EQ(2, result);
}

TEST(Arrays, FINDCHARBIN3) {
  const char array[5] = { 5, 4, 3, 2, 1 };
  int result = find_char_binary(array, 5, 5);
  EXPECT_EQ(0, result);
}

TEST(Arrays, FINDCHARBIN4) {
  const char array[5] = { 5, 4, 3, 2, 1 };
  int result = find_char_binary(array, 5, 17);
  EXPECT_EQ(-1, result);
}

TEST(Arrays, FINDCHARBIN5) {
  const int count = 128;
  const int answer = count-2;
  char *array = new char[count];
  int i;
  for(i = 0; i < count; i++)
    {
      array[i] = count-i-1;
    }
  int result = find_char_binary(array, count, 1);
  EXPECT_EQ(answer, result);
  delete [] array;
}
