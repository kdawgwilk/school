//
//  Words.cpp
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include "Words.h"


Words::Words() {
    
}

Words::Words(std::vector<std::string> words) {
    add_words(words);
}

bool Words::add_word(std::string word) {
    if (mWords.count(word)) {
        mWords[word]++;
    } else {
        mWords[word] = 1;
    }
    return true;
}

bool Words::add_words(std::vector<std::string> words) {
    for (auto const itr : words) {
        if (mWords.count(itr)) {
            mWords[itr]++;
        } else {
            mWords[itr] = 1;
        }
    }
    return true;
}

std::string Words::get_word(int index) {
//    std::cout << "Random Number: " << index << std::endl;

    long count = 0;
    for (auto const itr : mWords) {
        count += itr.second;
        if (count >= index) {
            std::cout << "Random Word: " << itr.first << std::endl;
            return itr.first;
        }
    }
    return "Not Found!";
}

std::map<std::string, int> Words::get_words() {
    return mWords;
}

std::string Words::get_random_word() {
    int i = std::rand() % size();
//    std::cout << "Random Number: " << i << std::endl;

    return get_word(i);
}


unsigned long Words::size() {
    unsigned long count = 0;
    for (auto const itr : mWords) {
        count += itr.second;
    }
    return count;
}


void Words::print_words() {
    std::cout << "Printing Words:" << std::endl;
    for (auto const itr : mWords) {
        std::cout << itr.first << " :: " << itr.second << std::endl;
    }
}

