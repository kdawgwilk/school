#include "gtest/gtest.h"

extern "C" int calcPixel(int maxiters, int col, int row);

TEST(calcPixel, black) {
    // test some black pixels
    int rgb = calcPixel(255, 142, 113);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 97, 163);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 125, 165);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 140, 153);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 125, 130);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 86, 110);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 132, 136);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 110, 157);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 121, 157);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 68, 125);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(255, 114, 87);
    EXPECT_EQ(0x000000, rgb);
}

TEST(calcPixel, lowiters) {
    // test some low iteration values
    int rgb = calcPixel(255, 254, 212);
    EXPECT_EQ(0x010101, rgb);

    rgb = calcPixel(255, 210, 30);
    EXPECT_EQ(0x010101, rgb);

    rgb = calcPixel(255, 132, 243);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 249, 19);
    EXPECT_EQ(0x010101, rgb);

    rgb = calcPixel(255, 185, 120);
    EXPECT_EQ(0x030303, rgb);

    rgb = calcPixel(255, 236, 152);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 164, 30);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 212, 146);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 113, 197);
    EXPECT_EQ(0x060606, rgb);

    rgb = calcPixel(255, 64, 50);
    EXPECT_EQ(0x030303, rgb);

    rgb = calcPixel(255, 32, 160);
    EXPECT_EQ(0x030303, rgb);

    rgb = calcPixel(255, 5, 70);
    EXPECT_EQ(0x010101, rgb);

    rgb = calcPixel(255, 43, 250);
    EXPECT_EQ(0x010101, rgb);

    rgb = calcPixel(255, 175, 223);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 183, 221);
    EXPECT_EQ(0x020202, rgb);

    rgb = calcPixel(255, 86, 251);
    EXPECT_EQ(0x010101, rgb);
}

TEST(calcPixel, highiters) {
    // test some high iteration values
    int rgb = calcPixel(255, 114, 79);
    EXPECT_EQ(0x343434, rgb);

    rgb = calcPixel(255, 139, 90);
    EXPECT_EQ(0x373737, rgb);

    rgb = calcPixel(255, 153, 113);
    EXPECT_EQ(0x353535, rgb);

    rgb = calcPixel(255, 50, 118);
    EXPECT_EQ(0xdcdcdc, rgb);

    rgb = calcPixel(255, 50, 138);
    EXPECT_EQ(0xdcdcdc, rgb);

    rgb = calcPixel(255, 49, 135);
    EXPECT_EQ(0x808080, rgb);

    rgb = calcPixel(255, 115, 76);
    EXPECT_EQ(0xd0d0d0, rgb);

    rgb = calcPixel(255, 145, 97);
    EXPECT_EQ(0x333333, rgb);

    rgb = calcPixel(255, 70, 111);
    EXPECT_EQ(0x353535, rgb);

    rgb = calcPixel(255, 127, 80);
    EXPECT_EQ(0x343434, rgb);

    rgb = calcPixel(255, 153, 113);
    EXPECT_EQ(0x353535, rgb);

    rgb = calcPixel(255, 70, 113);
    EXPECT_EQ(0x414141, rgb);

    rgb = calcPixel(255, 50, 120);
    EXPECT_EQ(0xfefefe, rgb);

    rgb = calcPixel(255, 104, 89);
    EXPECT_EQ(0x4f4f4f, rgb);

    rgb = calcPixel(255, 39, 129);
    EXPECT_EQ(0x585858, rgb);

    rgb = calcPixel(255, 75, 115);
    EXPECT_EQ(0x353535, rgb);

    rgb = calcPixel(255, 82, 110);
    EXPECT_EQ(0xc5c5c5, rgb);

    rgb = calcPixel(255, 154, 148);
    EXPECT_EQ(0x363636, rgb);

    rgb = calcPixel(255, 102, 90);
    EXPECT_EQ(0x686868, rgb);

    rgb = calcPixel(255, 110, 169);
    EXPECT_EQ(0x7a7a7a, rgb);
}
