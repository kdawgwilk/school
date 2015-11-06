#include "gtest/gtest.h"

extern "C" int fibonacci(int n);

TEST(fibonacci, all) {
    int n = fibonacci(1);
    EXPECT_EQ(1, n);

    n = fibonacci(2);
    EXPECT_EQ(1, n);

    n = fibonacci(3);
    EXPECT_EQ(2, n);

    n = fibonacci(4);
    EXPECT_EQ(3, n);

    n = fibonacci(5);
    EXPECT_EQ(5, n);

    n = fibonacci(6);
    EXPECT_EQ(8, n);

    n = fibonacci(7);
    EXPECT_EQ(13, n);

    n = fibonacci(8);
    EXPECT_EQ(21, n);

    n = fibonacci(9);
    EXPECT_EQ(34, n);

    n = fibonacci(10);
    EXPECT_EQ(55, n);

    n = fibonacci(20);
    EXPECT_EQ(6765, n);

    n = fibonacci(30);
    EXPECT_EQ(832040, n);

    n = fibonacci(40);
    EXPECT_EQ(102334155, n);
}
