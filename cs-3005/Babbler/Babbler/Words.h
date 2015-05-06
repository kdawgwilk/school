//
//  Words.h
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#ifndef __Babbler__Words__
#define __Babbler__Words__

#include <iostream>
#include <string>
#include <vector>
#include <map>


class Words {
public:
    
    Words();
    Words(std::vector<std::string> words);
    
    bool add_word(std::string word);
    bool add_words(std::vector<std::string> words);
    std::string get_word(int index);
    std::map<std::string, int> get_words();
    
    std::string get_random_word();
    
    unsigned long size();
    
    void print_words();
    
protected:
    
    
private:
    
    std::map<std::string, int> mWords;
    
};

#endif /* defined(__Babbler__Words__) */
