#include "string_funcs.h"
#include "string_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"
#include <cstring>

//
TEST(strrev, STRREV_1) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = { 'a', 0, 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'};
  char b2[16] = "abcdefghijklmno";
  char expected[16] = "a";

  /* do reverse */
  strrev(src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], src[i]);
    }
  EXPECT_EQ(expected[i], src[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
    }
}

//
TEST(strrev, STRREV_2) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', 0, 'Z', 'Z', 'Z', 'Z'};
  char b2[16] = "abcdefghijklmno";
  char expected[16] = "dlrow olleh";

  /* do reverse */
  strrev(src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], src[i]);
    }
  EXPECT_EQ(expected[i], src[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
    }
}

//
TEST(strrev, STRREV_3) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = { 'C', 'a', 'l', 'l', ' ', 'm', 'e', ',', ' ', 'm', 'a', 'y', 'b', 'e', 0, 'Z'};
  char b2[16] = "abcdefghijklmno";
  char expected[16] = "ebyam ,em llaC";

  /* do reverse */
  strrev(src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], src[i]);
    }
  EXPECT_EQ(expected[i], src[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
    }
}

//
TEST(strrev, STRREV_10) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = { 0, 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'};
  char b2[16] = "abcdefghijklmno";
  char expected[16] = "";

  /* do reverse */
  strrev(src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], src[i]);
    }
  EXPECT_EQ(expected[i], src[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
    }
}
