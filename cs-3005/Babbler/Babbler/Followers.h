//
//  Followers.h
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#ifndef __Babbler__Followers__
#define __Babbler__Followers__

#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <map>


class Followers {
public:
    
    Followers();
    Followers(std::vector<std::string> words, int level);
    
    bool set_followers(std::vector<std::string> words);
    bool add_follower(std::vector<std::string> words, std::string follower);
    
    std::string get_random_follower(std::vector<std::string> words);
    std::string pick_random(std::map<std::string, int> followers);
    
    void print_followers();
    
protected:
    
    
private:
    
    std::map<std::vector<std::string>, std::map<std::string, int> > mFollowers;
    int mLevel;

    
};

#endif /* defined(__Babbler__Followers__) */
