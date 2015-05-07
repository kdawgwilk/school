#include "risk.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(Risk, HANDLE_BATTLE_1) {
  int result = handle_battle(4, 1);
  EXPECT_LT(result, 0);
}

TEST(Risk, HANDLE_BATTLE_2) {
  int result = handle_battle(1, 3);
  EXPECT_LT(result, 0);
}

TEST(Risk, HANDLE_BATTLE_3) {
  int result = handle_battle(4, 3);
  EXPECT_LT(result, 0);
}

TEST(Risk, HANDLE_BATTLE_4) {
  const int nattack = 2;
  const int ndefend = 2;
  const int nperbattle = std::min(nattack, ndefend);
  const int nbattle = 10000;
  int i, losses = 0;
  for(i = 0; i < nbattle; i++)
    {
      losses += handle_battle(nattack, ndefend);
    }
  EXPECT_LT(losses, nperbattle*nbattle*42/100);
  EXPECT_GT(losses, nperbattle*nbattle*36/100);
}

TEST(Risk, HANDLE_BATTLE_5) {
  const int nattack = 1;
  const int ndefend = 2;
  const int nperbattle = std::min(nattack, ndefend);
  const int nbattle = 10000;
  int i, losses = 0;
  for(i = 0; i < nbattle; i++)
    {
      losses += handle_battle(nattack, ndefend);
    }
  EXPECT_LT(losses, nperbattle*nbattle*28/100);
  EXPECT_GT(losses, nperbattle*nbattle*22/100);
}
