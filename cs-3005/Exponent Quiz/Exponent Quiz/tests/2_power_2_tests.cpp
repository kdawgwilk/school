#include "exponent_quiz.h"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(Quiz, POWER_2_1) {
  const int exponents[5] = { 0, 5, 9, 31, 49 };
  const long long answers[5] = { 1, 32, 512, 2147483648, 562949953421312 };

  int i;
  for(i = 0; i < 5; i++)
    {
      long long answer = power_2(exponents[i]);
      EXPECT_EQ(answer, answers[i]);
    }
}
