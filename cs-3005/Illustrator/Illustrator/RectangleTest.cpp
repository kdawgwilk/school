//
//  RectangleTest.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/12/15.
//
//

#include "Rectangle.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>


TEST(RectangleClass, RECTANGLE_CREATION) {
    Point p1 = Point(13, 15);
    Point p2 = Point(10, 20);
    Rectangle r = Rectangle(p1, p2);
    
    EXPECT_EQ(r.getP1().getX(), 13);
    EXPECT_EQ(r.getP1().getY(), 15);
    EXPECT_EQ(r.getP2().getX(), 10);
    EXPECT_EQ(r.getP2().getY(), 20);
}