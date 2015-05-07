#include "IntAux.h" // Should make the rest of the data types available.
#include "IntAux.h" // double include
#include "gtest/gtest.h"
#include <cstring>
#include <sstream>

// ReadIntFile
TEST(IntFiles, READ_FILE_1) {
  std::string name = "tests/4_InsertNums-CS3005.txt";
  LinkedList<int> lst;
  int n = ReadIntFile(name, lst);
  EXPECT_EQ(774, n);
}

// RemoveInts
TEST(IntFiles, REMOVE_1) {
  std::string name = "tests/4_InsertNums-CS3005.txt";
  LinkedList<int> lst;
  int n = ReadIntFile(name, lst);
  EXPECT_EQ(774, n);

  std::string rname = "tests/4_DeleteNums-CS3005.txt";
  int d = RemoveInts(rname, lst);
  EXPECT_EQ(3113, d);
}

// AverageValue
TEST(IntFiles, AVERAGE_1) {
  std::string name = "tests/4_InsertNums-CS3005.txt";
  LinkedList<int> lst;
  int n = ReadIntFile(name, lst);
  EXPECT_EQ(774, n);

  std::string rname = "tests/4_DeleteNums-CS3005.txt";
  int d = RemoveInts(rname, lst);
  EXPECT_EQ(3113, d);

  std::string aname = "tests/4_RetrieveNums-CS3005.txt";
  double avg = AverageValue(aname, lst);
  EXPECT_LE(30295.2, avg);
  EXPECT_GE(30295.4, avg);
}
