#include "exponent_quiz.h"
#include "gtest/gtest.h"

TEST(Quiz, STRING_TO_NUMBER_1) {
  const char * strings[5] = { "1", "2", "4", "2147483648", "562949953421312" };
  const long long answers[5] = { 1, 2, 4, 2147483648, 562949953421312 };
  int i;
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(string_to_number(strings[i]), answers[i]);
    }
}

TEST(Quiz, STRING_TO_NUMBER_2) {
  const char * strings[5] = { "1k", "2m", "4b", "8t", "16t" };
  const long long answers[5] = { 1024, 2097152, 4294967296,
                                 8796093022208, 17592186044416 };
  int i;
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(string_to_number(strings[i]), answers[i]);
    }
}

TEST(Quiz, STRING_TO_NUMBER_3) {
  const char * strings[5] = { "1x", "2a", "4r", "8n", "16p" };
  const long long answers[5] = { 1, 2, 4, 8, 16 };
  int i;
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(string_to_number(strings[i]), answers[i]);
    }
}

TEST(Quiz, STRING_TO_NUMBER_4) {
  const char * strings[5] = { "1kk", "2m2", "4b9", "8t6", "16tt" };
  const long long answers[5] = { 1024, 2097152, 4294967296,
                                 8796093022208, 17592186044416 };
  int i;
  for(i = 0; i < 5; i++)
    {
      EXPECT_EQ(string_to_number(strings[i]), answers[i]);
    }
}
