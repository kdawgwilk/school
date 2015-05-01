//
//  main.cpp
//  Student Class Part 2
//
//  Created by Kaden Wilkinson on 3/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "gtest/gtest.h"
#include "exponent_quiz.h"

//int main(int argc, char * argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
int main() {
    std::srand(int(time(0)));
    int *exponents = new int[50];
    std::time_t result = std::time(NULL);
    int wrong = 0;
    generate_exponents(0, 49, exponents);
    int i = 0;
    long long correct_answer;
    long long user_answer;
    bool correctness = false;
    char *answer = new char[128];
    for (i = 0; i < 50; i++)
    {
        do {
            std::cout << "What is 2^" << exponents[i] << ": ";
            std::cin >> answer;
            
            correct_answer = power_2(exponents[i]);
            user_answer = string_to_number(answer);
            correctness = correct_answer == user_answer;
            if (correctness)
            {
                std::cout << "Correct!" << std::endl;
            }
            else
            {
                std::cout << "Wrong, try again! " << std::endl;
                wrong++;
            }
        } while (!correctness);
        
    }
    std::time_t finished = std::time(NULL);
    std::cout << "That took you " << finished - result << " seconds." << std::endl;
    std::cout << "You missed " << wrong << " questions." << std::endl;
    std::cout << "Your score is: " << (finished - result) + ((wrong) * 5) << std::endl;
    
    delete [] answer;
    delete [] exponents;
    return 0;
}