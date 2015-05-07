//
//  FileUtils.h
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#ifndef __Babbler__FileUtils__
#define __Babbler__FileUtils__

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>


class FileUtils {
public:
    std::vector<std::string> read_words(const std::string);
    bool write_words(const std::string filename, std::vector<std::string> words);
    bool copy_file(const std::string ifilename, const std::string ofilename);
    
    std::vector<std::string> get_random_group(int level);
    
protected:
    
    
private:
    std::vector<std::string> mWords;
    
};



#endif /* defined(__Babbler__FileUtils__) */
