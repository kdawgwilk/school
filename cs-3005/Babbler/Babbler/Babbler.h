//
//  Babbler.h
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#ifndef __Babbler__Babbler__
#define __Babbler__Babbler__

#include "FileUtils.h"
#include "Words.h"
#include "Followers.h"
#include <iostream>
#include <string>
#include <map>

class Babbler {
public:
    Babbler();
    Babbler(long length, int level, const std::string ifilename, const std::string ofilename);
    ~Babbler();
    
    bool read_file();
    bool write_file();
    bool babble();
    bool print_babbled();
    
protected:
    
    
private:
//    std::map<std::string, std::map<std::string, int> > mFollowers;
    std::vector<std::string> mBabbled;
    Followers *mFollowers;
    FileUtils *mFile;
    Words *mWords;
    std::string mIFilename;
    std::string mOFilename;
    long mLength;
    int mLevel;
};

#endif /* defined(__Babbler__Babbler__) */
