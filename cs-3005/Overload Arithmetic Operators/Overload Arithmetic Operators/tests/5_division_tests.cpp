#include "Rational.h"
#include "Rational.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(operator_overload, division_1) {
  Rational r1(1, 2);
  Rational r2(1, 2);
  Rational r3 = r1 / r2;
  EXPECT_EQ(1, r1.getNumerator());
  EXPECT_EQ(2, r1.getDenominator());
  EXPECT_EQ(1, r2.getNumerator());
  EXPECT_EQ(2, r2.getDenominator());
  EXPECT_EQ(1, r3.getNumerator());
  EXPECT_EQ(1, r3.getDenominator());
}


//
TEST(operator_overload, division_2) {
  Rational r1(5, 3);
  Rational r2(1, 3);
  Rational r3 = r1 / r2;
  EXPECT_EQ(5, r1.getNumerator());
  EXPECT_EQ(3, r1.getDenominator());
  EXPECT_EQ(1, r2.getNumerator());
  EXPECT_EQ(3, r2.getDenominator());
  EXPECT_EQ(5, r3.getNumerator());
  EXPECT_EQ(1, r3.getDenominator());
}


//
TEST(operator_overload, division_3) {
  Rational r1(3, 8);
  Rational r2(1, 6);
  Rational r3 = r1 / r2;
  EXPECT_EQ(3, r1.getNumerator());
  EXPECT_EQ(8, r1.getDenominator());
  EXPECT_EQ(1, r2.getNumerator());
  EXPECT_EQ(6, r2.getDenominator());
  EXPECT_EQ(9, r3.getNumerator());
  EXPECT_EQ(4, r3.getDenominator());
}

//
TEST(operator_overload, division_4) {
  Rational r1(8, 3);
  Rational r2(9, 4);
  Rational r3 = r1 / r2;
  EXPECT_EQ(8, r1.getNumerator());
  EXPECT_EQ(3, r1.getDenominator());
  EXPECT_EQ(9, r2.getNumerator());
  EXPECT_EQ(4, r2.getDenominator());
  EXPECT_EQ(32, r3.getNumerator());
  EXPECT_EQ(27, r3.getDenominator());
}
