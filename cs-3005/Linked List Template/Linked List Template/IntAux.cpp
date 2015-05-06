
#include "IntAux.h"


int ReadIntFile(const std::string &filename, LinkedList<int> &nums)
{
    int c = -1;
    std::ifstream fin(filename);
    bool exists;
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            int i;
            fin >> i;
//            std::cout << "Int: " << i << "\n";
            exists = nums.Insert(i);
            if (!exists) {
//                std::cout << "Exists" <<"\n";
                c++;
            }
        }
    }
    fin.close();
    //    std::cout << "Value of C: " << c << "\n";
    return c;
}

int RemoveInts(const std::string &filename, LinkedList<int> &nums)
{
    int c = -1;
    std::ifstream fin(filename);
    bool exists;
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            int i;
            fin >> i;
            exists = nums.Delete(i);
            if (!exists) {
                c++;
            }
        }
    }
    fin.close();
    //    std::cout << "Value of C: " << c << "\n";
    return c;
}

double AverageValue(const std::string &filename, LinkedList<int> &nums)
{
    double avg;
    double c = 0;
    double total = 0;
    std::ifstream fin(filename);
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            int i;
            fin >> i;
            int rI = nums.Retrieve(i);
            if (rI != 0) {
                total += rI;
                c++;
            }
        }
    }
    fin.close();
//    std::cout << "Value of C: " << c << "\n";
//    std::cout << "Value of total: " << total << "\n";
    avg = total / c;
//    std::cout << "Value of avg: " << avg << "\n";
    return avg;
}