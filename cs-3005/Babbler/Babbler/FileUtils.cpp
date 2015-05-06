//
//  FileUtils.cpp
//  Babbler
//
//  Created by Kaden Wilkinson on 5/2/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include "FileUtils.h"


std::vector<std::string> FileUtils::read_words(const std::string filename)
{
    std::vector<std::string> words;
    std::ifstream fin(filename);
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    
    std::string tmp;
    while(fin)
    {
        fin >> tmp;
        if(fin)
        {
            // Remove Punctuation
            tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ispunct), tmp.end());
            // Remove numbers
            tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isdigit), tmp.end());
            if (tmp.size() >= 1) {
                // Convert to all lowercase
                std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);

                mWords.push_back(tmp);
                words.push_back(tmp);
            }
        }
    }
    fin.close();
    return words;
}

std::vector<std::string> FileUtils::get_random_group(int level) {
    int rand = std::rand() % mWords.size() - level;
    int i;
    std::vector<std::string> group;
    for (i = 0; i <= level; i++) {
        group.push_back(mWords[rand + i]);
    }
    return group;
}


bool FileUtils::write_words(const std::string filename, std::vector<std::string> words)
{
    std::ofstream fout(filename);
    if(!fout)
    {
        std::cerr << "Unable to open " << filename << std::endl;
        return false;
    }
    
    /* one item per line */
    int i;
    int size = int(words.size());
    for(i = 0; i < size; i++)
    {
        fout << words[i] << " ";
    }
    
    fout.close();
    return true;
}

bool FileUtils::copy_file(const std::string ifilename, const std::string ofilename)
{
    std::vector<std::string> input = read_words(ifilename);
    
    bool pass = write_words(ofilename, input);
    if(!pass)
    {
        return false;
    }
    return true;
}
