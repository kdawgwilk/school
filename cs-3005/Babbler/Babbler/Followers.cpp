//
//  Followers.cpp
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include "Followers.h"


Followers::Followers() {
    
}

Followers::Followers(std::vector<std::string> words, int level)
:   mLevel(level)
{
    if (level < 1) {
        mLevel = 1;
    }
    set_followers(words);
}

bool Followers::set_followers(std::vector<std::string> words) {
    mFollowers.clear();
    std::vector<std::string> prev;
    
    for (auto const itr : words) {
        if (prev.size() < mLevel) {
            prev.push_back(itr);
        } else {
            
            add_follower(prev, itr);
            prev.erase(prev.begin());
            prev.push_back(itr);
        }
    }
    return true;
}

bool Followers::add_follower(std::vector<std::string> words, std::string follower) {
        if (!mFollowers.count(words)) {
        mFollowers[words];
        if (!mFollowers[words].count(follower)) {
            mFollowers[words][follower] = 1;
        } else {
            mFollowers[words][follower] +=1;
        }
    } else {
        if (!mFollowers[words].count(follower)) {
            mFollowers[words][follower] = 1;
        } else {
            mFollowers[words][follower] += 1;
        }
    }
    return true;
}

std::string Followers::get_random_follower(std::vector<std::string> words) {
    std::string random;
    if (words.size() < mLevel) {
        for (auto const itr : mFollowers) {
            std::string match = itr.first[itr.first.size() - 1];
            std::string word = words[words.size() - 1];
            if (match == word) {
                random = pick_random(itr.second);
                return random;
            }
        }
    }
    std::vector<std::string> wordsLevel = std::vector<std::string>(words.end() - mLevel, words.end());
    std::map<std::string, int> followers;
    if (mFollowers.count(wordsLevel)) {
        followers = mFollowers[wordsLevel];
        random = pick_random(followers);
    } else {
        random = "Error";
    }
    
    return random;
}

std::string Followers::pick_random(std::map<std::string, int> followers) {
    int count = 0;
    int i = 0;
    for (auto const itr : followers) {
        count += itr.second;
    }
    if (count < 1) {
        std::cout << "Pick Random Count was < 1!" << std::endl;
        return "Error";
    } else if (count == 1) {
        i = 1;
    } else {
        i = rand() % count;
    }
    count = 0;
    for (auto const itr : followers) {
        count += itr.second;
        if (count >= i) {
            return itr.first;
        }
    }
    return "Error";
}

void Followers::print_followers() {
    std::cout << "Printing Followers:" << std::endl;
    long count = 0;
    for (auto const itr1 : mFollowers) {
        for (auto const itr2 : itr1.second) {
            count += itr2.second;
        }
        if (count < 1) {
            std::cout << std::endl << "Count was ZERO!!!!" << std::endl << std::endl;
        }
        for (auto const itr2 : itr1.first) {
            std::cout << itr2 << " ";
        }
        std::cout << count << " :: " << std::endl;
        for (auto const itr2 : itr1.second) {
            std::cout << itr2.first << " : ";
            std::cout << itr2.second << " " << std::endl;
        }
        count = 0;
    }
}
