//
//  main.cpp
//  Data Set
//
//  Created by Kaden Wilkinson on 5/7/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<int> readFile(const std::string filename)
{
    std::vector<int> numbers;
    std::ifstream fin(filename);
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    
    int tmp;
    while(fin)
    {
        fin >> tmp;
        if(fin)
        {
            numbers.push_back(tmp);
        }
    }
    fin.close();
    return numbers;
}

std::vector<int> sort_int_asc(std::vector<int> nums)
{
    bool swapped = true;
    int j = 0;
    int tmp, i;
    while (swapped) {
        swapped = false;
        j++;
//        for (auto itr : nums) {
//
//        }
        for (i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
                swapped = true;
            }
        }
    }
    return nums;
}



int main(int argc, const char * argv[]) {
    std::vector<int> numbers;
    std::vector<int> numbersSorted;
    int n = 9999;
//    const std::string ifilename = "numbers1.txt";
    const std::string ifilename = "numbers2.txt";
    numbers = readFile(ifilename);
    numbersSorted = sort_int_asc(numbers);
    
        
    std::cout << n << "th number is: " << numbersSorted[numbersSorted.size() - n];
    
    return 0;
}

