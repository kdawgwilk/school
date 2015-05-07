//
//  LookAndSay.cpp
//  Pascals Triangle
//
//  Created by Kaden Wilkinson on 4/21/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{
    string input = "122344111";
//    string input = "1112344111";
    cout << "Input: " << input << "\n";

    string output;
    int i = 0;
    int count = 1;
    bool new_char = true;
    
    while (input[i]) {
        cout << "Value of I: " << i << "\n";
        cout << "Input[" << i << "]: " << input[i] << "\n";

        if (input[i] == input[i + 1]) {
            new_char = true;
            count++;
        } else {
            new_char = false;
        }
        if (new_char == false) {
            output += to_string(count) + input[i];
            cout << "Should be added to output: " << to_string(count) + input[i] << "\n";
            count = 1;
        }
        cout << "Value of count: " << count << "\n";
        i++;
    }
    cout << "Output: " << output << "\n";

    return 0;
}

void logger() {
    
}


