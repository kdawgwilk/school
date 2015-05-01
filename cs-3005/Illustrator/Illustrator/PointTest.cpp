//
//  PointTest.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/12/15.
//
//

#include "Point.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>


TEST(PointClass, POINT_CREATION) {
    Point p = Point(13, 15);
    EXPECT_EQ(p.getX(), 13);
    EXPECT_EQ(p.getY(), 15);
}