//
//  Babbler.cpp
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include "Babbler.h"
#include "Words.h"
#include "Followers.h"

Babbler::Babbler() {
    mFile = new FileUtils();
    mWords = new Words();
    mFollowers = new Followers();
}

Babbler::Babbler(long length, int level, const std::string ifilename, const std::string ofilename)
:   mLength(length),
    mLevel(level),
    mIFilename(ifilename),
    mOFilename(ofilename)
{
    mFile = new FileUtils();
    mWords = new Words(mFile->read_words(ifilename));
    mFollowers = new Followers(mFile->read_words(ifilename), level);
}

Babbler::~Babbler() {
    delete mFollowers;
    delete mWords;
    delete mFile;
}

bool Babbler::read_file() {
    if(!mWords->add_words(mFile->read_words(mIFilename))) {
        return false;
    }
    return true;
}

bool Babbler::write_file() {
    if (!mFile->write_words(mOFilename, mBabbled)) {
        return false;
    }
    return true;
}

bool Babbler::babble() {
    int i;
    std::string randomWord;
    std::vector<std::string> randomGroup;
    if (mLength < 1 || mLevel < 1) {
        return false;
    }
    mBabbled.clear();
    randomGroup = mFile->get_random_group(mLevel);
    for (auto const itr : randomGroup) {
        mBabbled.push_back(itr);
    }
    for (i = 0; i < mLength; i++) {
        randomWord = mFollowers->get_random_follower(mBabbled);
        if (randomWord == "Error") {
            randomGroup = mFile->get_random_group(mLevel);
            for (auto const itr : randomGroup) {
                mBabbled.push_back(itr);
            }
        } else {
            mBabbled.push_back(randomWord);
        }
    }
    write_file();
    return true;
}

bool Babbler::print_babbled() {
//    mFollowers->print_followers();
    std::cout << "Printing Babbled Words:" << std::endl << std::endl;
    for (auto const itr : mBabbled) {
        std::cout << itr << " ";
    }
//    mWords->print_words();
    return true;
}
