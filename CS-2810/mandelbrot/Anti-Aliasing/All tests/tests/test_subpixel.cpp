#include "gtest/gtest.h"
#include <inttypes.h>

extern "C" void setupSubpixel(int antialias);
extern "C" double subpixelOffsets[];

TEST(subpixel, all) {
    setupSubpixel(1);
    EXPECT_EQ(0, subpixelOffsets[0]);

    setupSubpixel(2);
    EXPECT_EQ(0.5/2.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/2.0 - 0.5, subpixelOffsets[1]);

    setupSubpixel(3);
    EXPECT_EQ(0.5/3.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/3.0 - 0.5, subpixelOffsets[1]);
    EXPECT_EQ(2.5/3.0 - 0.5, subpixelOffsets[2]);

    setupSubpixel(4);
    EXPECT_EQ(0.5/4.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/4.0 - 0.5, subpixelOffsets[1]);
    EXPECT_EQ(2.5/4.0 - 0.5, subpixelOffsets[2]);
    EXPECT_EQ(3.5/4.0 - 0.5, subpixelOffsets[3]);

    setupSubpixel(5);
    EXPECT_EQ(0.5/5.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/5.0 - 0.5, subpixelOffsets[1]);
    EXPECT_EQ(2.5/5.0 - 0.5, subpixelOffsets[2]);
    EXPECT_EQ(3.5/5.0 - 0.5, subpixelOffsets[3]);
    EXPECT_EQ(4.5/5.0 - 0.5, subpixelOffsets[4]);

    setupSubpixel(6);
    EXPECT_EQ(0.5/6.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/6.0 - 0.5, subpixelOffsets[1]);
    EXPECT_EQ(2.5/6.0 - 0.5, subpixelOffsets[2]);
    EXPECT_EQ(3.5/6.0 - 0.5, subpixelOffsets[3]);
    EXPECT_EQ(4.5/6.0 - 0.5, subpixelOffsets[4]);
    EXPECT_EQ(5.5/6.0 - 0.5, subpixelOffsets[5]);

    setupSubpixel(7);
    EXPECT_EQ(0.5/7.0 - 0.5, subpixelOffsets[0]);
    EXPECT_EQ(1.5/7.0 - 0.5, subpixelOffsets[1]);
    EXPECT_EQ(2.5/7.0 - 0.5, subpixelOffsets[2]);
    EXPECT_EQ(3.5/7.0 - 0.5, subpixelOffsets[3]);
    EXPECT_EQ(4.5/7.0 - 0.5, subpixelOffsets[4]);
    EXPECT_EQ(5.5/7.0 - 0.5, subpixelOffsets[5]);
    EXPECT_EQ(6.5/7.0 - 0.5, subpixelOffsets[6]);
}
