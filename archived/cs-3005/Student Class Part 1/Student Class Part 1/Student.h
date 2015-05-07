#include <iostream>
#include <cstring>

#ifndef _STUDENT_H_
#define _STUDENT_H_

const int MAX_STRING_LENGTH = 64;

class Student
{
    public:
        /* constructors */
        Student();
        Student(
            const int age,
            const char last_name[],
            const char first_name[],
            const char email[],
            const char social[]
        );

        /* accessor methods */
        int getAge() const;
        const char *getLast() const;
        const char *getFirst() const;
        const char *getEmail() const;
        const char *getSsn() const;
        bool setAge(const int age);
        bool setLast(const char last[]);
        bool setFirst(const char first[]);
        bool setEmail(const char email[]);
        bool setSsn(const char ssn[]);

    private:
        /* data members */
        int mAge;
        char mLastName[MAX_STRING_LENGTH];
        char mFirstName[MAX_STRING_LENGTH];
        char mEmail[MAX_STRING_LENGTH];
        char mSocial[12];
};

std::ostream &operator<<(std::ostream &os, const Student &rhs);
std::istream &operator>>(std::istream &is, Student &rhs);

#endif //_STUDENT_H_
