extern int add_em(int, int);

#include "gtest/gtest.h"

//
TEST(add_em, SIMPLE_1) {
  const int a = 1;
  const int b = 2;
  int v = add_em(a, b);
  EXPECT_EQ(3, v);
}


//
TEST(add_em, SIMPLE_2) {
  const int a = 2;
  const int b = 5;
  int v = add_em(a, b);
  EXPECT_EQ(14, v);
}

//
TEST(add_em, SIMPLE_3) {
  const int a = 33;
  const int b = 104;
  int v = add_em(a, b);
  EXPECT_EQ(4932, v);
}

//
TEST(add_em, SIMPLE_4) {
  const int a = -104;
  const int b = -33;
  int v = add_em(a, b);
  EXPECT_EQ(-4932, v);
}


//
TEST(add_em, REVERSE_1) {
  const int a = 2;
  const int b = 1;
  int v = add_em(a, b);
  EXPECT_EQ(3, v);
}

//
TEST(add_em, REVERSE_2) {
  const int a = 5;
  const int b = 2;
  int v = add_em(a, b);
  EXPECT_EQ(14, v);
}

//
TEST(add_em, REVERSE_3) {
  const int a = 104;
  const int b = 33;
  int v = add_em(a, b);
  EXPECT_EQ(4932, v);
}

//
TEST(add_em, REVERSE_4) {
  const int a = -33;
  const int b = -104;
  int v = add_em(a, b);
  EXPECT_EQ(-4932, v);
}


//
TEST(add_em, SAME_1) {
  const int a = 1;
  const int b = 1;
  int v = add_em(a, b);
  EXPECT_EQ(1, v);
}

//
TEST(add_em, SAME_2) {
  const int a = 5;
  const int b = 5;
  int v = add_em(a, b);
  EXPECT_EQ(5, v);
}

//
TEST(add_em, SAME_3) {
  const int a = 113;
  const int b = 113;
  int v = add_em(a, b);
  EXPECT_EQ(113, v);
}

//
TEST(add_em, SAME_4) {
  const int a = -153;
  const int b = -153;
  int v = add_em(a, b);
  EXPECT_EQ(-153, v);
}
