//
//  TriangleTest.cpp
//  Illustrator
//
//  Created by Kaden Wilkinson on 4/12/15.
//
//

#include "Triangle.h"
#include "Point.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>


TEST(TriangleClass, TRIANGLE_CREATION) {
    Point p1 = Point(13, 15);
    Point p2 = Point(10, 20);
    Point p3 = Point(5, 12);
    
    Triangle t = Triangle(p1, p2, p3);
    
    EXPECT_EQ(t.getP1().getX(), 13);
    EXPECT_EQ(t.getP1().getY(), 15);
    
    EXPECT_EQ(t.getP2().getX(), 10);
    EXPECT_EQ(t.getP2().getY(), 20);
    
    EXPECT_EQ(t.getP3().getX(), 5);
    EXPECT_EQ(t.getP3().getY(), 12);
}

