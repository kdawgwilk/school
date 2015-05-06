#include "LinkedList.h"
#include "LinkedList.h"
#include "gtest/gtest.h"
#include <cstring>
#include <string>
#include <sstream>

// Output Operator
TEST(IntLinkedList, OSTREAM_1) {
  const LinkedList<int> lst;
  std::stringstream ss;
  ss << lst;
  EXPECT_EQ(std::strcmp(ss.str().c_str(), ""), 0);
}

// Output Operator
TEST(IntLinkedList, OSTREAM_2) {
  LinkedList<int> lst;
  int s;
  std::stringstream ss,tt;

  ss << "121" << std::endl;
  ss << "31" << std::endl;
  ss << "41" << std::endl;
  ss << "41" << std::endl;
  ss << "31" << std::endl;
  ss << "71" << std::endl;

  while(ss >> s)
    {
      lst.Insert(s);
    }

  tt << lst;

  // test for last character
  std::string str = tt.str();
  EXPECT_EQ(str[str.size()-1], '1');
  int count = 0;
  while(tt >> s)
    {
      EXPECT_EQ(lst.Exists(s), true);
      count ++;
    }
  EXPECT_EQ(count, 4); // unique entries
}

// Input Operator
TEST(IntLinkedList, ISTREAM_1) {
  LinkedList<int> lst;
  int s;
  std::stringstream ss,tt;

  ss << "121" << std::endl;
  ss << "31" << std::endl;
  ss << "41" << std::endl;
  ss << "41" << std::endl;
  ss << "31" << std::endl;
  ss << "71" << std::endl;

  ss >> lst;

  // check for existence
  ss.clear(); ss.seekg(0); // rewind to beginning
  while(ss >> s)
    {
      EXPECT_EQ(lst.Exists(s), true);
    }

  // check for duplicates
  ss.clear(); ss.seekg(0); // rewind to beginning
  int count = 0;
  while(ss >> s)
    {
      if(lst.Delete(s))
        {
          count ++;
        }
    }
  EXPECT_EQ(count, 4);
}
