#include "array_utils.h"
#include "gtest/gtest.h"

TEST(Arrays, FINDINTBIN1) {
  const int array[5] = { 1, 2, 3, 4, 5 };
  int result = find_int_binary(array, 5, 1);
  EXPECT_EQ(0, result);
}

TEST(Arrays, FINDINTBIN2) {
  const int array[5] = { 1, 2, 3, 4, 5 };
  int result = find_int_binary(array, 5, 3);
  EXPECT_EQ(2, result);
}

TEST(Arrays, FINDINTBIN3) {
  const int array[5] = { 1, 2, 3, 4, 5 };
  int result = find_int_binary(array, 5, 5);
  EXPECT_EQ(4, result);
}

TEST(Arrays, FINDINTBIN4) {
  const int array[5] = { 1, 2, 3, 4, 5 };
  int result = find_int_binary(array, 5, 17);
  EXPECT_EQ(-1, result);
}

TEST(Arrays, FINDINTBIN5) {
  const int count = 1000;
  const int answer = count-2;
  int *array = new int[count];
  int i;
  for(i = 0; i < count; i++)
    {
      array[i] = i-count/2;
    }
  int result = find_int_binary(array, count, (count/2)-2);
  EXPECT_EQ(answer, result);
  delete [] array;
}
