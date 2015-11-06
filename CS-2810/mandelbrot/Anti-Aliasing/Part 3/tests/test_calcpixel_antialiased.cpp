#include "gtest/gtest.h"
#include <inttypes.h>

extern "C" void setupSubpixel(int antialias);
extern "C" int calcPixel(int maxiters, int column, int row, int xsize, int ysize, int antialias, double centerx, double centery, double magnification);

TEST(calcpixel_antialiased, one) {
    // make sure it still works with no antialiasing
    setupSubpixel(1);

    int rgb = calcPixel(1000, 385, 59, 843, 201, 1, -0.743643135, 0.131825963, 98264.36);
    EXPECT_EQ(0x3f0000, rgb);

    rgb = calcPixel(1000, 518, 473, 939, 547, 1, -0.743643135, 0.131825963, 8137.41);
    EXPECT_EQ(0xbf0000, rgb);

    rgb = calcPixel(1000, 256, 19, 557, 527, 1, -0.743643135, 0.131825963, 77010.00);
    EXPECT_EQ(0xcf0000, rgb);

    rgb = calcPixel(1000, 696, 772, 924, 819, 1, -0.743643135, 0.131825963, 3816.13);
    EXPECT_EQ(0x2f0000, rgb);

    rgb = calcPixel(1000, 95, 418, 191, 544, 1, -0.743643135, 0.131825963, 50793.26);
    EXPECT_EQ(0x8f0000, rgb);

    rgb = calcPixel(1000, 465, 207, 479, 414, 1, -0.743643135, 0.131825963, 95452.74);
    EXPECT_EQ(0xaf0000, rgb);

    rgb = calcPixel(1000, 17, 359, 856, 714, 1, -0.743643135, 0.131825963, 93558.61);
    EXPECT_EQ(0x1f0000, rgb);

    rgb = calcPixel(1000, 641, 131, 854, 173, 1, -0.743643135, 0.131825963, 24064.01);
    EXPECT_EQ(0x0000bf, rgb);

    rgb = calcPixel(1000, 89, 175, 465, 848, 1, -0.743643135, 0.131825963, 40721.32);
    EXPECT_EQ(0x00004f, rgb);

    rgb = calcPixel(1000, 605, 535, 713, 537, 1, -0.743643135, 0.131825963, 10894.61);
    EXPECT_EQ(0x5f0000, rgb);

    rgb = calcPixel(1000, 666, 70, 906, 306, 1, -0.743643135, 0.131825963, 66927.35);
    EXPECT_EQ(0x1f0000, rgb);

    rgb = calcPixel(1000, 383, 181, 764, 254, 1, -0.743643135, 0.131825963, 41663.28);
    EXPECT_EQ(0x7f0000, rgb);

    rgb = calcPixel(1000, 129, 28, 134, 176, 1, -0.743643135, 0.131825963, 62197.02);
    EXPECT_EQ(0x2f0000, rgb);

    rgb = calcPixel(1000, 445, 506, 995, 620, 1, -0.743643135, 0.131825963, 45426.71);
    EXPECT_EQ(0xaf0000, rgb);

    rgb = calcPixel(1000, 295, 946, 576, 953, 1, -0.743643135, 0.131825963, 63516.64);
    EXPECT_EQ(0x2f0000, rgb);

    rgb = calcPixel(1000, 317, 435, 476, 1051, 1, -0.743643135, 0.131825963, 32695.85);
    EXPECT_EQ(0x00008f, rgb);

    rgb = calcPixel(1000, 144, 161, 1097, 256, 1, -0.743643135, 0.131825963, 35383.57);
    EXPECT_EQ(0x2f0000, rgb);

    rgb = calcPixel(1000, 207, 133, 224, 830, 1, -0.743643135, 0.131825963, 72565.54);
    EXPECT_EQ(0x0000ef, rgb);

    rgb = calcPixel(1000, 75, 267, 124, 489, 1, -0.743643135, 0.131825963, 35149.96);
    EXPECT_EQ(0xcf0000, rgb);

    rgb = calcPixel(1000, 76, 463, 543, 760, 1, -0.743643135, 0.131825963, 47165.77);
    EXPECT_EQ(0xbf0000, rgb);
}

TEST(calcpixel_antialiased, two) {
    setupSubpixel(2);

    int rgb = calcPixel(1000, 372, 36, 557, 257, 2, -0.743643135, 0.131825963, 30702.10);
    EXPECT_EQ(0x1f0053, rgb);

    rgb = calcPixel(1000, 50, 66, 174, 151, 2, -0.743643135, 0.131825963, 96068.07);
    EXPECT_EQ(0x000013, rgb);

    rgb = calcPixel(1000, 270, 77, 923, 907, 2, -0.743643135, 0.131825963, 83863.36);
    EXPECT_EQ(0x170023, rgb);

    rgb = calcPixel(1000, 197, 328, 803, 431, 2, -0.743643135, 0.131825963, 66933.83);
    EXPECT_EQ(0x130053, rgb);

    rgb = calcPixel(1000, 182, 721, 319, 776, 2, -0.743643135, 0.131825963, 67365.69);
    EXPECT_EQ(0x53006f, rgb);

    rgb = calcPixel(1000, 100, 299, 122, 539, 2, -0.743643135, 0.131825963, 88273.56);
    EXPECT_EQ(0x47002b, rgb);

    rgb = calcPixel(1000, 742, 418, 995, 656, 2, -0.743643135, 0.131825963, 46364.19);
    EXPECT_EQ(0x8b0033, rgb);

    rgb = calcPixel(1000, 259, 514, 264, 558, 2, -0.743643135, 0.131825963, 743.83);
    EXPECT_EQ(0x0000b3, rgb);

    rgb = calcPixel(1000, 81, 67, 824, 425, 2, -0.743643135, 0.131825963, 89042.86);
    EXPECT_EQ(0x00009b, rgb);

    rgb = calcPixel(1000, 293, 34, 745, 638, 2, -0.743643135, 0.131825963, 21114.43);
    EXPECT_EQ(0x5f0033, rgb);

    rgb = calcPixel(1000, 257, 83, 615, 142, 2, -0.743643135, 0.131825963, 46507.93);
    EXPECT_EQ(0xe70000, rgb);

    rgb = calcPixel(1000, 203, 4, 302, 144, 2, -0.743643135, 0.131825963, 32918.33);
    EXPECT_EQ(0x57000b, rgb);

    rgb = calcPixel(1000, 35, 959, 322, 1039, 2, -0.743643135, 0.131825963, 77488.73);
    EXPECT_EQ(0x970000, rgb);

    rgb = calcPixel(1000, 138, 759, 409, 811, 2, -0.743643135, 0.131825963, 44526.15);
    EXPECT_EQ(0x4f0007, rgb);

    rgb = calcPixel(1000, 1, 102, 394, 156, 2, -0.743643135, 0.131825963, 68739.67);
    EXPECT_EQ(0x930033, rgb);

    rgb = calcPixel(1000, 348, 442, 403, 773, 2, -0.743643135, 0.131825963, 3619.38);
    EXPECT_EQ(0x5f003f, rgb);

    rgb = calcPixel(1000, 24, 29, 225, 253, 2, -0.743643135, 0.131825963, 92608.50);
    EXPECT_EQ(0x570000, rgb);

    rgb = calcPixel(1000, 476, 99, 1082, 183, 2, -0.743643135, 0.131825963, 95370.67);
    EXPECT_EQ(0x3b003b, rgb);

    rgb = calcPixel(1000, 428, 181, 947, 502, 2, -0.743643135, 0.131825963, 12946.00);
    EXPECT_EQ(0x170043, rgb);

    rgb = calcPixel(1000, 391, 371, 714, 618, 2, -0.743643135, 0.131825963, 14068.76);
    EXPECT_EQ(0x2b0000, rgb);
}

TEST(calcpixel_antialiased, 5) {
    setupSubpixel(5);

    int rgb = calcPixel(1000, 116, 23, 598, 191, 5, -0.743643135, 0.131825963, 62025.92);
    EXPECT_EQ(0x0000b5, rgb);

    rgb = calcPixel(1000, 119, 71, 177, 146, 5, -0.743643135, 0.131825963, 5859.19);
    EXPECT_EQ(0x0000d2, rgb);

    rgb = calcPixel(1000, 385, 27, 597, 119, 5, -0.743643135, 0.131825963, 52679.97);
    EXPECT_EQ(0x6b0000, rgb);

    rgb = calcPixel(1000, 525, 356, 891, 645, 5, -0.743643135, 0.131825963, 85247.93);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(1000, 477, 440, 702, 797, 5, -0.743643135, 0.131825963, 56488.07);
    EXPECT_EQ(0xae0000, rgb);

    rgb = calcPixel(1000, 171, 151, 343, 317, 5, -0.743643135, 0.131825963, 71057.87);
    EXPECT_EQ(0x000000, rgb);

    rgb = calcPixel(1000, 133, 316, 352, 1049, 5, -0.743643135, 0.131825963, 21208.55);
    EXPECT_EQ(0xd90000, rgb);

    rgb = calcPixel(1000, 331, 767, 435, 941, 5, -0.743643135, 0.131825963, 73552.97);
    EXPECT_EQ(0x120000, rgb);

    rgb = calcPixel(1000, 119, 360, 283, 977, 5, -0.743643135, 0.131825963, 42089.42);
    EXPECT_EQ(0x190000, rgb);

    rgb = calcPixel(1000, 614, 615, 894, 878, 5, -0.743643135, 0.131825963, 75629.43);
    EXPECT_EQ(0x3f0061, rgb);

    rgb = calcPixel(1000, 34, 105, 159, 461, 5, -0.743643135, 0.131825963, 25285.55);
    EXPECT_EQ(0x51005f, rgb);

    rgb = calcPixel(1000, 422, 276, 448, 835, 5, -0.743643135, 0.131825963, 23185.54);
    EXPECT_EQ(0x0000ad, rgb);

    rgb = calcPixel(1000, 468, 30, 919, 185, 5, -0.743643135, 0.131825963, 60050.88);
    EXPECT_EQ(0x340048, rgb);

    rgb = calcPixel(1000, 902, 118, 1022, 400, 5, -0.743643135, 0.131825963, 2822.05);
    EXPECT_EQ(0x2a0049, rgb);

    rgb = calcPixel(1000, 358, 71, 824, 327, 5, -0.743643135, 0.131825963, 39286.43);
    EXPECT_EQ(0x000047, rgb);

    rgb = calcPixel(1000, 64, 45, 136, 105, 5, -0.743643135, 0.131825963, 53484.15);
    EXPECT_EQ(0x34003d, rgb);

    rgb = calcPixel(1000, 628, 233, 885, 528, 5, -0.743643135, 0.131825963, 39598.22);
    EXPECT_EQ(0x2e0055, rgb);

    rgb = calcPixel(1000, 171, 248, 1006, 657, 5, -0.743643135, 0.131825963, 68527.72);
    EXPECT_EQ(0xc50003, rgb);

    rgb = calcPixel(1000, 282, 176, 526, 456, 5, -0.743643135, 0.131825963, 47230.27);
    EXPECT_EQ(0x5d002b, rgb);

    rgb = calcPixel(1000, 659, 88, 900, 157, 5, -0.743643135, 0.131825963, 12754.49);
    EXPECT_EQ(0x000060, rgb);
}
