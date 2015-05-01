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
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
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

// operator=
TEST(StudentClass, STUDENT_COMPARE_1) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 == s3, true);
  EXPECT_EQ(s3 == s1, true);
  EXPECT_EQ(s1 == s2, false);
  EXPECT_EQ(s2 == s1, false);
}

// operator!=
TEST(StudentClass, STUDENT_COMPARE_2) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 != s3, false);
  EXPECT_EQ(s3 != s1, false);
  EXPECT_EQ(s1 != s2, true);
  EXPECT_EQ(s2 != s1, true);
}

// operator<
TEST(StudentClass, STUDENT_COMPARE_3) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 < s3, false);
  EXPECT_EQ(s3 < s1, false);
  EXPECT_EQ(s1 < s2, true);
  EXPECT_EQ(s2 < s1, false);
}

// operator<=
TEST(StudentClass, STUDENT_COMPARE_4) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 <= s3, true);
  EXPECT_EQ(s3 <= s1, true);
  EXPECT_EQ(s1 <= s2, true);
  EXPECT_EQ(s2 <= s1, false);
}


// operator>
TEST(StudentClass, STUDENT_COMPARE_5) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 > s3, false);
  EXPECT_EQ(s3 > s1, false);
  EXPECT_EQ(s1 > s2, false);
  EXPECT_EQ(s2 > s1, true);
}

// operator>=
TEST(StudentClass, STUDENT_COMPARE_6) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn1 = "999-19-9999";
  const char *ssn2 = "999-29-9999";
  const Student s1(age, last, first, email, ssn1);
  const Student s2(age, last, first, email, ssn2);
  const Student s3(age, last, first, email, ssn1);

  EXPECT_EQ(s1 >= s3, true);
  EXPECT_EQ(s3 >= s1, true);
  EXPECT_EQ(s1 >= s2, false);
  EXPECT_EQ(s2 >= s1, true);
}
