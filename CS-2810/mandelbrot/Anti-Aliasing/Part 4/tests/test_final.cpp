#include "gtest/gtest.h"
#include <inttypes.h>

extern "C" double xcenter, ycenter, mag;
extern "C" int64_t xsize, ysize, iters, antialias;
extern "C" int start();
extern "C" int calcPixel(int maxiters, int column, int row, int xSize, int ySize, double centerX, double centerY, double magnification);

int linecount(char *buff, int size);
int words_in_4th_line(char *buff, int size);

TEST(dynamicimage, all) {
    // set up the test image
    xcenter = -0.743643135;
    ycenter = 0.131825963;
    mag = 91152.0;
    xsize = 128;
    ysize = 200;
    iters = 1000;
    antialias = 9;

    // generate it
    int status = start();

    // self-reported status code should be zero (success)
    EXPECT_EQ(0, status);

    // open and read the file
    FILE *fp = fopen("fractal.ppm", "r");
    ASSERT_FALSE(fp == NULL);
    const int maxSize = 256*256*12 + 1000;
    char buffer[maxSize+1];
    size_t size = fread(buffer, 1, maxSize, fp);
    ASSERT_TRUE(size > 0);
    buffer[size] = 0;
    status = fclose(fp);
    ASSERT_EQ(0, status);

    // read the comparison file
    fp = fopen("tests/fractal.ppm", "r");
    ASSERT_FALSE(fp == NULL);
    char buffer2[maxSize+1];
    size_t size2 = fread(buffer2, 1, maxSize, fp);
    ASSERT_TRUE(size2 > 0);
    buffer2[size2] = 0;
    status = fclose(fp);
    ASSERT_EQ(0, status);

    // check for a match
    EXPECT_EQ(size, size2);

    // compare number of lines (proxy for rows)
    int linesFound = linecount(buffer, size);
    int linesExpected = linecount(buffer2, size2);
    EXPECT_EQ(linesExpected, linesFound);

    // compare number of words in 4th line (proxy for columns)
    int wordsFoundIn1stRow = words_in_4th_line(buffer, size);
    int wordsExpectedIn1stRow = words_in_4th_line(buffer2, size2);
    EXPECT_EQ(wordsExpectedIn1stRow, wordsFoundIn1stRow);

    int line = 1, col = 0;
    int mismatchcount = 0;
    for (size_t i = 0; i < size && mismatchcount < 10; i++) {
        if (buffer[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
        if (buffer[i] != buffer2[i]) {
            ADD_FAILURE() << "Mismatch at line " << line << " column " << col;
            mismatchcount++;
        }
    }
    if (mismatchcount >= 10) {
        ADD_FAILURE() << "Too many mismatches, quitting";
    }
}

int linecount(char *buff, int size) {
    int newlines = 0;
    for (int i = 0; i < size; i++)
        if (buff[i] == '\n')
            newlines++;
    return newlines;
}

int words_in_4th_line(char *buff, int size) {
    int newlines = 0;
    int spaces = 0;
    for (int i = 0; i < size; i++) {
        if (buff[i] == '\n') {
            newlines++;
            if (newlines == 4)
                return spaces + 1;
            spaces = 0;
        }
        if (buff[i] == ' ')
            spaces++;
    }
    return 0;
}
