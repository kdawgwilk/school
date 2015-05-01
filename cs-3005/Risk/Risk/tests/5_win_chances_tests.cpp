#include "risk.h"
#include "gtest/gtest.h"

TEST(Risk, WIN_CHANCES_1) {
  const int nattack = 4;
  const int ndefend = 1;
  const int nbattle = 10000;
  double result = win_chances(nattack, ndefend, nbattle);
  EXPECT_LT(result, 0);
}

TEST(Risk, WIN_CHANCES_2) {
  const int nattack = 1;
  const int ndefend = 3;
  const int nbattle = 10000;
  double result = win_chances(nattack, ndefend, nbattle);
  EXPECT_LT(result, 0);
}

TEST(Risk, WIN_CHANCES_3) {
  const int nattack = 4;
  const int ndefend = 3;
  const int nbattle = 10000;
  double result = win_chances(nattack, ndefend, nbattle);
  EXPECT_LT(result, 0);
}

TEST(Risk, WIN_CHANCES_4) {
  const int nattack = 2;
  const int ndefend = 2;
  const int nbattle = 10000;
  double result = win_chances(nattack, ndefend, nbattle);
  EXPECT_LT(result, 0.42);
  EXPECT_GT(result, 0.36);
}

TEST(Risk, WIN_CHANCES_5) {
  const int nattack = 1;
  const int ndefend = 2;
  const int nbattle = 10000;
  double result = win_chances(nattack, ndefend, nbattle);
  EXPECT_LT(result, 0.28);
  EXPECT_GT(result, 0.22);
}
