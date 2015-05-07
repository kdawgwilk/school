//
//  main.cpp
//  Student Class Part 2
//
//  Created by Kaden Wilkinson on 3/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Mouse.h"
#include "mouse_funcs.h"

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}