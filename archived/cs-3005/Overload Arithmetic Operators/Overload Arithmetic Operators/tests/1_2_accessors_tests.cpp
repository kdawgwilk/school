#include "Rational.h"
#include "Rational.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(operator_overload, accessors_1) {
  Rational r;
  EXPECT_EQ(0, r.getNumerator());
  EXPECT_EQ(0, r.getDenominator());
}

//
TEST(operator_overload, accessors_2) {
  Rational r(1, 2);
  EXPECT_EQ(1, r.getNumerator());
  EXPECT_EQ(2, r.getDenominator());
}

//
TEST(operator_overload, accessors_3) {
  Rational r(3, 5);
  EXPECT_EQ(3, r.getNumerator());
  EXPECT_EQ(5, r.getDenominator());
}
