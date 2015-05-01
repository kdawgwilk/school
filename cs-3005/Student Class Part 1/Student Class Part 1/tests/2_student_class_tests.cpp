#include "Student.h"
#include "gtest/gtest.h"
#include <cstring>
#include <sstream>

// Output Operator
TEST(StudentClass, STUDENT_STREAM_1) {
  const Student s;
  std::stringstream ss;
  ss << s;
  EXPECT_EQ(std::strcmp(ss.str().c_str(), "0 NONE NONE NONE NONE"), 0);
}

// Output Operator
TEST(StudentClass, STUDENT_STREAM_2) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-9999";
  const Student s(age, last, first, email, ssn);

  std::stringstream ss;
  ss << s;
  EXPECT_EQ(std::strcmp(ss.str().c_str(), "1 a b c 999-99-9999"), 0);
}

// Input Operator
TEST(StudentClass, STUDENT_STREAM_3) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-9999";
  Student s(age, last, first, email, ssn);

  std::stringstream ss;
  ss << "0 NONE NONE NONE NONE";
  ss >> s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// Input Operator
TEST(StudentClass, STUDENT_STREAM_4) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-9999";
  Student s;

  std::stringstream ss;
  ss << "1 a b c 999-99-9999";
  ss >> s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);
}
