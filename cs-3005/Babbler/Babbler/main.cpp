//
//  main.cpp
//  Babbler
//
//  Created by Kaden Wilkinson on 4/29/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include "Babbler.h"

int main(int argc, const char * argv[]) {
    std::srand(int(time(0)));
    // Complete Works of Edgar Allen Poe
//    const std::string ifilename = "eap.txt";
    // Book of Mormon
//    const std::string ifilename = "bom.txt";
    
    const std::string ifilename = "input.txt";
    const std::string ofilename = "output.txt";
    long length = 200;
    int level = 6;
    
    Babbler *b = new Babbler(length, level, ifilename, ofilename);
    
    if(!b->babble()) {
        std::cout << "There was an error babbling the file!/n";
    }
    
    if(!b->print_babbled()) {
        std::cout << "There was an error printing the babbled text the file!/n";
    }
    
    delete b;
    return 0;
}
