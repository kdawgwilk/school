#include "gtest/gtest.h"
#include <inttypes.h>

extern "C" int blendColors(int64_t *buffer, int count);

TEST(blendColors, single) {
    // single values
    int64_t buffer[10];

    buffer[0] = 0;
    int n = blendColors(buffer, 1);
    EXPECT_EQ(0, n);

    buffer[0] = 0xff;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0xff, n);

    buffer[0] = 0xff00;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0xff00, n);

    buffer[0] = 0xff0000;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0xff0000, n);

    buffer[0] = 0x010203;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0x010203, n);

    buffer[0] = 0x102030;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0x102030, n);

    // junk bits
    buffer[0] = 0x1ffffff;
    n = blendColors(buffer, 1);
    EXPECT_EQ(0xffffff, n);
}

TEST(blendColors, multiple) {
    // multiple values
    int64_t buffer[10];

    buffer[0] = 0x00;
    buffer[1] = 0x10;
    buffer[2] = 0x20;
    int n = blendColors(buffer, 3);
    EXPECT_EQ(0x10, n);

    buffer[0] = 0x0000;
    buffer[1] = 0x1000;
    buffer[2] = 0x2000;
    n = blendColors(buffer, 3);
    EXPECT_EQ(0x1000, n);

    buffer[0] = 0x000000;
    buffer[1] = 0x100000;
    buffer[2] = 0x200000;
    n = blendColors(buffer, 3);
    EXPECT_EQ(0x100000, n);

    buffer[0] = 0x002233;
    buffer[1] = 0x102322;
    buffer[2] = 0x202411;
    n = blendColors(buffer, 3);
    EXPECT_EQ(0x102322, n);
}

TEST(blendColors, overflow) {
    // values where the sum overflows the 8-bit channel
    int64_t buffer[10];

    buffer[0] = 0xf0e0d0;
    buffer[1] = 0xd8c8b8;
    int n = blendColors(buffer, 2);
    EXPECT_EQ(0xe4d4c4, n);

    buffer[0] = 0x123456;
    buffer[1] = 0x234567;
    buffer[2] = 0xabcdef;
    buffer[3] = 0x010203;
    buffer[4] = 0x975235;
    buffer[5] = 0x123123;
    buffer[6] = 0x635644;
    buffer[7] = 0x020381;
    buffer[8] = 0xba0a38;
    buffer[9] = 0xf03fbd;
    n = blendColors(buffer, 10);
    EXPECT_EQ(0x5c3e60, n);
}

TEST(blendColors, bounds) {
    // bounds checking
    int64_t buffer[10];

    buffer[0] = 0x000000;
    buffer[1] = 0x888888;
    buffer[2] = 0xcccccc;
    buffer[3] = 0xffffff;
    int n = blendColors(buffer + 1, 1);
    EXPECT_EQ(0x888888, n);
    n = blendColors(buffer + 2, 1);
    EXPECT_EQ(0xcccccc, n);
    n = blendColors(buffer + 1, 2);
    EXPECT_EQ(0xaaaaaa, n);
    n = blendColors(buffer, 4);
    EXPECT_EQ(0x949494, n);
}
