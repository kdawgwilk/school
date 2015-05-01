//
//  CircleTest.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/12/15.
//
//

#include "Circle.h"
#include "Point.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>


TEST(CircleClass, CIRCLE_CREATION) {
    Point p = Point(13, 15);
    int r = 5;
    Circle c = Circle(p, r);
    
    EXPECT_EQ(c.getCenter().getX(), 13);
    EXPECT_EQ(c.getCenter().getY(), 15);
    EXPECT_EQ(c.getRadius(), 5);
}
