#include "Rational.h"
#include "Rational.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(operator_overload, simplify_1) {
  Rational r;
  EXPECT_EQ(0, r.getNumerator());
  EXPECT_EQ(0, r.getDenominator());
}

//
TEST(operator_overload, simplify_2) {
  Rational r(6, 12);
  EXPECT_EQ(1, r.getNumerator());
  EXPECT_EQ(2, r.getDenominator());
}

//
TEST(operator_overload, simplify_3) {
  Rational r(15, 25);
  EXPECT_EQ(3, r.getNumerator());
  EXPECT_EQ(5, r.getDenominator());
}

//
TEST(operator_overload, simplify_4) {
  Rational r(100, 30);
  EXPECT_EQ(10, r.getNumerator());
  EXPECT_EQ(3, r.getDenominator());
}
