#include "gtest/gtest.h"

extern "C" int getColor(int iters);

TEST(getColor, all) {
    // 0 -> black
    int n = getColor(0);
    EXPECT_EQ(0, n);

    // reds
    n = getColor(1);
    EXPECT_EQ(0x0f0000, n);

    n = getColor(2);
    EXPECT_EQ(0x1f0000, n);

    n = getColor(16);
    EXPECT_EQ(0xff0000, n);

    n = getColor(31);
    EXPECT_EQ(0x0f0000, n);

    // blues
    n = getColor(32);
    EXPECT_EQ(0x00000f, n);

    n = getColor(33);
    EXPECT_EQ(0x00001f, n);

    n = getColor(47);
    EXPECT_EQ(0x0000ff, n);

    n = getColor(61);
    EXPECT_EQ(0x00001f, n);

    // overflow back into reds
    n = getColor(63);
    EXPECT_EQ(0x0f0000, n);

    n = getColor(64);
    EXPECT_EQ(0x1f0000, n);

    n = getColor(78);
    EXPECT_EQ(0xff0000, n);

    n = getColor(93);
    EXPECT_EQ(0x0f0000, n);

    // and into blues again
    n = getColor(94);
    EXPECT_EQ(0x00000f, n);

    n = getColor(95);
    EXPECT_EQ(0x00001f, n);

    n = getColor(109);
    EXPECT_EQ(0x0000ff, n);

    n = getColor(123);
    EXPECT_EQ(0x00001f, n);

    // and again
    n = getColor(125);
    EXPECT_EQ(0x0f0000, n);

    n = getColor(126);
    EXPECT_EQ(0x1f0000, n);

    n = getColor(140);
    EXPECT_EQ(0xff0000, n);

    n = getColor(155);
    EXPECT_EQ(0x0f0000, n);

    n = getColor(156);
    EXPECT_EQ(0x00000f, n);

    n = getColor(157);
    EXPECT_EQ(0x00001f, n);

    n = getColor(171);
    EXPECT_EQ(0x0000ff, n);

    n = getColor(185);
    EXPECT_EQ(0x00001f, n);
}
