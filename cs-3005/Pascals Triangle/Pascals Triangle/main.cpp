////
////  main.cpp
////  Pascals Triangle
////
////  Created by Kaden Wilkinson on 4/9/15.
////  Copyright (c) 2015 Trendly Creations. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//
//
////std::vector<std::vector<long long> > * createRows(const int num, std::vector<std::vector<long long> > &list)
////{
////    int i;
////    if (num == 1) {
////        list[0][0] = 1;
////        return &list;
////    }
////    for(i = 0; i < num; i++) {
////        list[num].push_back(i);
////    }
////    return createRows(num + 1, list);
////}
//
////std::vector<long long> getRow(const int num, std::vector<std::vector<long long> > &list)
////{
////    return list[num];
////}
//
////int main(int argc, const char * argv[])
////{
////    const int num = argc;
////    std::vector<std::vector<long long> > * list;
////    
////    list = createRows(num, *list);
////    
//////    std::cout << getRow(num, *list) << "\n";
////    
////    return 0;
////}
//
//int main(int argc, const char * argv[])
//{
//    std::stringstream ss;
//    ss << "1 2 0 1 2 1 0 1 0";
//
//    std::string result = "No Winner!";
//    
//    std::string grid00;
//    std::string grid10;
//    std::string grid20;
//    
//    std::string grid01;
//    std::string grid11;
//    std::string grid21;
//    
//    std::string grid02;
//    std::string grid12;
//    std::string grid22;
//    
//    ss >> grid00 >> grid10 >> grid20 >> grid01 >> grid11 >> grid21 >> grid02 >> grid12 >> grid22;
//    
//    if (grid00 == "1" && grid10 == "1" && grid20 == "1") {
//        result = "Winner is X!";
//    } else if (grid01 == "1" && grid11 == "1" && grid21 == "1") {
//        result = "Winner is X!";
//    } else if (grid02 == "1" && grid12 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    }
//    
//    else if (grid00 == "1" && grid01 == "1" && grid02 == "1") {
//        result = "Winner is X!";
//    } else if (grid10 == "1" && grid11 == "1" && grid12 == "1") {
//        result = "Winner is X!";
//    } else if (grid20 == "1" && grid21 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    }
//    
//    else if (grid00 == "1" && grid11 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    } else if (grid20 == "1" && grid11 == "1" && grid02 == "1") {
//        result = "Winner is X!";
//    }
//    
//    
//    
//    if (grid00 == "2" && grid10 == "2" && grid20 == "2") {
//        result = "Winner is O!";
//    } else if (grid01 == "2" && grid11 == "2" && grid21 == "2") {
//        result = "Winner is O!";
//    } else if (grid02 == "2" && grid12 == "2" && grid22 == "2") {
//        result = "Winner is O!";
//    }
//    
//    else if (grid00 == "2" && grid01 == "2" && grid02 == "2") {
//        result = "Winner is O!";
//    } else if (grid10 == "2" && grid11 == "2" && grid12 == "2") {
//        result = "Winner is O!";
//    } else if (grid20 == "2" && grid21 == "2" && grid22 == "2") {
//        result = "Winner is O!";
//    }
//    
//    else if (grid00 == "2" && grid11 == "2" && grid22 == "2") {
//        result = "Winner is O!";
//    } else if (grid20 == "2" && grid11 == "2" && grid02 == "2") {
//        result = "Winner is O!";
//    }
//
//    std::cout << "Result: " << result << "\n";
//    
//    return 0;
//}
//
//bool checkWinner(std::string a, std::string b, std::string c, )
//{
//    if (grid00 == "1" && grid10 == "1" && grid20 == "1") {
//        result = "Winner is X!";
//    } else if (grid01 == "1" && grid11 == "1" && grid21 == "1") {
//        result = "Winner is X!";
//    } else if (grid02 == "1" && grid12 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    }
//    
//    else if (grid00 == "1" && grid01 == "1" && grid02 == "1") {
//        result = "Winner is X!";
//    } else if (grid10 == "1" && grid11 == "1" && grid12 == "1") {
//        result = "Winner is X!";
//    } else if (grid20 == "1" && grid21 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    }
//    
//    else if (grid00 == "1" && grid11 == "1" && grid22 == "1") {
//        result = "Winner is X!";
//    } else if (grid20 == "1" && grid11 == "1" && grid02 == "1") {
//        result = "Winner is X!";
//    }
//}
//
//
//
//
