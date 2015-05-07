#include "Student.h"
#include "Student.h" // included twice to test #ifndef
#include "gtest/gtest.h"
#include <cstring>

// default constructor
TEST(StudentClass, STUDENT_CLASS_1) {
  const Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), ""), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// setAge
TEST(StudentClass, STUDENT_CLASS_2) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setAge(-10);
  EXPECT_EQ(s.getAge(), 0);
  s.setAge(1);
  EXPECT_EQ(s.getAge(), 1);
  s.setAge(0);
  EXPECT_EQ(s.getAge(), 0);
  s.setAge(150);
  EXPECT_EQ(s.getAge(), 150);
  s.setAge(151);
  EXPECT_EQ(s.getAge(), 0);
}

// setSsn
TEST(StudentClass, STUDENT_CLASS_3) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setSsn("999-99-9999");
  EXPECT_EQ(std::strcmp(s.getSsn(), "999-99-9999"), 0);
  s.setSsn("999-99-999");
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
  s.setSsn("111-11-1111");
  EXPECT_EQ(std::strcmp(s.getSsn(), "111-11-1111"), 0);
  s.setSsn("999-99-99999");
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// setLast
TEST(StudentClass, STUDENT_CLASS_4) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  const char *last_short = "1234567890";
  const char *last_full = "123456789012345678901234567890123456789012345678901234567890123";
  const char *last_over1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *last_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setLast(last_short);
  EXPECT_EQ(std::strcmp(s.getLast(), last_short), 0);
  s.setLast(last);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  s.setLast(last_full);
  EXPECT_EQ(std::strcmp(s.getLast(), last_full), 0);
  s.setLast(last_over1);
  EXPECT_EQ(std::strcmp(s.getLast(), last_full), 0);
  s.setLast(last_over2);
  EXPECT_EQ(std::strcmp(s.getLast(), last_full), 0);
  s.setLast(last_short);
  EXPECT_EQ(std::strcmp(s.getLast(), last_short), 0);
}

// setFirst
TEST(StudentClass, STUDENT_CLASS_5) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  const char *first_short = "1234567890";
  const char *first_full = "123456789012345678901234567890123456789012345678901234567890123";
  const char *first_over1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *first_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setFirst(first_short);
  EXPECT_EQ(std::strcmp(s.getFirst(), first_short), 0);
  s.setFirst(first);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  s.setFirst(first_full);
  EXPECT_EQ(std::strcmp(s.getFirst(), first_full), 0);
  s.setFirst(first_over1);
  EXPECT_EQ(std::strcmp(s.getFirst(), first_full), 0);
  s.setFirst(first_over2);
  EXPECT_EQ(std::strcmp(s.getFirst(), first_full), 0);
  s.setFirst(first_short);
  EXPECT_EQ(std::strcmp(s.getFirst(), first_short), 0);
}

// setEmail
TEST(StudentClass, STUDENT_CLASS_6) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  const char *email_short = "1234567890";
  const char *email_full = "123456789012345678901234567890123456789012345678901234567890123";
  const char *email_over1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *email_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setEmail(email_short);
  EXPECT_EQ(std::strcmp(s.getEmail(), email_short), 0);
  s.setEmail(email);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  s.setEmail(email_full);
  EXPECT_EQ(std::strcmp(s.getEmail(), email_full), 0);
  s.setEmail(email_over1);
  EXPECT_EQ(std::strcmp(s.getEmail(), email_full), 0);
  s.setEmail(email_over2);
  EXPECT_EQ(std::strcmp(s.getEmail(), email_full), 0);
  s.setEmail(email_short);
  EXPECT_EQ(std::strcmp(s.getEmail(), email_short), 0);
}

// setLast, setFirst, setEmail
TEST(StudentClass, STUDENT_CLASS_7) {
  const int  age = 0;
  const char *last = "";
  const char *first = "";
  const char *email = "";
  const char *ssn = "";
  const char *text_full = "123456789012345678901234567890123456789012345678901234567890123";
  const char *text_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  Student s;

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setLast(text_over2);
  s.setFirst(text_over2);
  s.setEmail(text_over2);
  EXPECT_EQ(std::strcmp(s.getLast(), text_full), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_full), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_full), 0);
}

// main constructor
TEST(StudentClass, STUDENT_CLASS_8) {
  const int  age = 1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-9999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), age);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);
}

// main constructor with age and ssn invalid values
TEST(StudentClass, STUDENT_CLASS_9) {
  const int  age = -1;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// main constructor with age and ssn invalid values
TEST(StudentClass, STUDENT_CLASS_10) {
  const int  age = 151;
  const char *last = "a";
  const char *first = "b";
  const char *email = "c";
  const char *ssn = "999-99-99999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// constructor with invalid string lengths
TEST(StudentClass, STUDENT_CLASS_11) {
  const char *text_full = "123456789012345678901234567890123456789012345678901234567890123";
  const char *text_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  const int  age = 151;
  const char *last = text_over2;
  const char *first = text_over2;
  const char *email = text_over2;
  const char *ssn = "999-99-9999999999999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), text_full), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_full), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_full), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}
