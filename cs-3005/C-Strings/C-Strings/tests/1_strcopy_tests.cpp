#include "string_funcs.h"
#include "string_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"
#include <cstring>

//
TEST(strcopy, STRCOPY_1) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = "a";
  char b2[16] = "abcdefghijklmno";
  char dst[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
  char b3[16] = "abcdefghijklmno";
  char expected[16] = "a";

  /* do copy */
  strcopy(dst, src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], dst[i]);
    }
  EXPECT_EQ(expected[i], dst[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
      EXPECT_EQ(b0[i], b3[i]);
    }
}

//
TEST(strcopy, STRCOPY_2) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = "hello world";
  char b2[16] = "abcdefghijklmno";
  char dst[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
  char b3[16] = "abcdefghijklmno";
  char expected[16] = "hello world";

  /* do copy */
  strcopy(dst, src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], dst[i]);
    }
  EXPECT_EQ(expected[i], dst[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
      EXPECT_EQ(b0[i], b3[i]);
    }
}

//
TEST(strcopy, STRCOPY_3) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = "Call me, maybe";
  char b2[16] = "abcdefghijklmno";
  char dst[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
  char b3[16] = "abcdefghijklmno";
  char expected[16] = "Call me, maybe";

  /* do copy */
  strcopy(dst, src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], dst[i]);
    }
  EXPECT_EQ(expected[i], dst[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
      EXPECT_EQ(b0[i], b3[i]);
    }
}

//
TEST(strcopy, STRCOPY_10) {
  char b0[16] = "abcdefghijklmno";
  char b1[16] = "abcdefghijklmno";
  char src[16] = "";
  char b2[16] = "abcdefghijklmno";
  char dst[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
  char b3[16] = "abcdefghijklmno";
  char expected[16] = "";

  /* do copy */
  strcopy(dst, src);

  /* check expected value */
  unsigned int i;
  for(i = 0; i < strlen(expected); i++)
    {
      EXPECT_EQ(expected[i], dst[i]);
    }
  EXPECT_EQ(expected[i], dst[i]); // check null-character

  /* check boundaries */
  for(i = 0; i < strlen(b0); i++)
    {
      EXPECT_EQ(b0[i], b1[i]);
      EXPECT_EQ(b0[i], b2[i]);
      EXPECT_EQ(b0[i], b3[i]);
    }
}
