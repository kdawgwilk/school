#include "Student.h"
#include "Student.h" // included twice to test #ifndef
#include "gtest/gtest.h"
#include <cstring>

// default constructor
TEST(StudentClass, STUDENT_CLASS_1) {
  const Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// setAge
TEST(StudentClass, STUDENT_CLASS_2) {
  const char *ssn = "";
  Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
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
  const char *ssn = "";
  Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
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
  const char *last = "";
  const char *ssn = "";

  const char *text_short = "1234567890";
  const char *text_long = "123456789012345678901234567890123456789012345678901234567890123";
  const char *text_long1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *text_long2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";

  Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setLast(text_short);
  EXPECT_EQ(std::strcmp(s.getLast(), text_short), 0);
  s.setLast(last);
  EXPECT_EQ(std::strcmp(s.getLast(), last), 0);
  s.setLast(text_long);
  EXPECT_EQ(std::strcmp(s.getLast(), text_long), 0);
  s.setLast(0);
  EXPECT_EQ(s.getLast(), (void *)0);
  s.setLast(text_long1);
  EXPECT_EQ(std::strcmp(s.getLast(), text_long1), 0);
  s.setLast(text_long2);
  EXPECT_EQ(std::strcmp(s.getLast(), text_long2), 0);
  s.setLast(text_short);
  EXPECT_EQ(std::strcmp(s.getLast(), text_short), 0);
  s.setLast(0);
  EXPECT_EQ(s.getLast(), (void *)0);
}

// setFirst
TEST(StudentClass, STUDENT_CLASS_5) {
  const char *first = "";
  const char *ssn = "";

  const char *text_short = "1234567890";
  const char *text_long = "123456789012345678901234567890123456789012345678901234567890123";
  const char *text_long1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *text_long2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";

  Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setFirst(text_short);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_short), 0);
  s.setFirst(first);
  EXPECT_EQ(std::strcmp(s.getFirst(), first), 0);
  s.setFirst(text_long);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_long), 0);
  s.setFirst(0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  s.setFirst(text_long1);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_long1), 0);
  s.setFirst(text_long2);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_long2), 0);
  s.setFirst(text_short);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_short), 0);
  s.setFirst(0);
  EXPECT_EQ(s.getFirst(), (void *)0);
}


// setEmail
TEST(StudentClass, STUDENT_CLASS_6) {
  const char *email = "";
  const char *ssn = "";

  const char *text_short = "1234567890";
  const char *text_long = "123456789012345678901234567890123456789012345678901234567890123";
  const char *text_long1 = "1234567890123456789012345678901234567890123456789012345678901234";
  const char *text_long2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";

  Student s;

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setEmail(text_short);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_short), 0);
  s.setEmail(email);
  EXPECT_EQ(std::strcmp(s.getEmail(), email), 0);
  s.setEmail(text_long);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_long), 0);
  s.setEmail(0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  s.setEmail(text_long1);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_long1), 0);
  s.setEmail(text_long2);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_long2), 0);
  s.setEmail(text_short);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_short), 0);
  s.setEmail(0);
  EXPECT_EQ(s.getEmail(), (void *)0);
}

// setLast, setFirst, setEmail
TEST(StudentClass, STUDENT_CLASS_7) {
  const char *ssn = "";
  const char *text_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  Student s;


  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ssn), 0);

  s.setLast(text_over2);
  s.setFirst(text_over2);
  s.setEmail(text_over2);
  EXPECT_EQ(std::strcmp(s.getLast(), text_over2), 0);
  EXPECT_EQ(std::strcmp(s.getFirst(), text_over2), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_over2), 0);
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

// constructor with long string lengths
TEST(StudentClass, STUDENT_CLASS_11) {
  const char *text_over2 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  const int  age = 151;
  const char *last = text_over2;
  const char *first = text_over2;
  const char *email = text_over2;
  const char *ssn = "999-99-9999999999999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(std::strcmp(s.getLast(), text_over2), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_over2), 0);
  EXPECT_EQ(std::strcmp(s.getEmail(), text_over2), 0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// constructor with NULL pointer strings
TEST(StudentClass, STUDENT_CLASS_12) {
  const int  age = 151;
  const char *last = 0;
  const char *first = 0;
  const char *email = 0;
  const char *ssn = "999-99-9999999999999";
  const Student s(age, last, first, email, ssn);

  EXPECT_EQ(s.getAge(), 0);
  EXPECT_EQ(s.getLast(), (void *)0);
  EXPECT_EQ(s.getFirst(), (void *)0);
  EXPECT_EQ(s.getEmail(), (void *)0);
  EXPECT_EQ(std::strcmp(s.getSsn(), ""), 0);
}

// copy constructor
TEST(StudentClass, STUDENT_CLASS_13) {
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

  const Student t(s);

  EXPECT_EQ(t.getAge(), age);
  EXPECT_EQ(std::strcmp(t.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(t.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(t.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(t.getSsn(), ssn), 0);

  EXPECT_NE(t.getLast(), s.getLast());
  EXPECT_NE(t.getFirst(), s.getFirst());
  EXPECT_NE(t.getEmail(), s.getEmail());
  EXPECT_NE(t.getSsn(), s.getSsn());
}


// assignment operator
TEST(StudentClass, STUDENT_CLASS_14) {
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

  Student t;

  t = s;

  EXPECT_EQ(t.getAge(), age);
  EXPECT_EQ(std::strcmp(t.getLast(), last), 0);
  EXPECT_EQ(std::strcmp(t.getFirst(), first), 0);
  EXPECT_EQ(std::strcmp(t.getEmail(), email), 0);
  EXPECT_EQ(std::strcmp(t.getSsn(), ssn), 0);

  EXPECT_NE(t.getLast(), s.getLast());
  EXPECT_NE(t.getFirst(), s.getFirst());
  EXPECT_NE(t.getEmail(), s.getEmail());
  EXPECT_NE(t.getSsn(), s.getSsn());
}
