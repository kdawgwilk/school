#include "Student.h"


Student::Student()
    : mAge(0)
{
    this->mLastName[0] = 0;
    this->mFirstName[0] = 0;
    this->mEmail[0] = 0;
    this->mSocial[0] = 0;
}

Student::Student(
    const int age,
    const char last_name[],
    const char first_name[],
    const char email[],
    const char social[])
{
    setAge(age);
    setLast(last_name);
    setFirst(first_name);
    setEmail(email);
    setSsn(social);
}

int Student::getAge() const
{
    return mAge;
}

const char *Student::getLast() const
{
    return mLastName;
}

const char *Student::getFirst() const
{
    return mFirstName;
}

const char *Student::getEmail() const
{
    return mEmail;
}

const char *Student::getSsn() const
{
    return mSocial;
}

bool Student::setAge(const int age)
{
    if(age <= 150 && age > 0) {
        mAge = age;
        return true;
    }
    mAge = 0;
    return false;
}

bool Student::setLast(const char last[])
{
    if(std::strlen(last) < MAX_STRING_LENGTH) {
        std::strcpy(mLastName, last);
        return true;
    } else {
        std::strncpy(mLastName, last, MAX_STRING_LENGTH - 1);
        mLastName[MAX_STRING_LENGTH - 1] = 0;
        return false;
    }
}

bool Student::setFirst(const char first[])
{
    if(std::strlen(first) < MAX_STRING_LENGTH) {
        std::strcpy(mFirstName, first);
        return true;
    } else {
        std::strncpy(mFirstName, first, MAX_STRING_LENGTH - 1);
        mFirstName[MAX_STRING_LENGTH - 1] = 0;
        return false;
    }
}

bool Student::setEmail(const char email[])
{
    if(std::strlen(email) < MAX_STRING_LENGTH) {
        std::strcpy(mEmail, email);
        return true;
    } else {
        std::strncpy(mEmail, email, MAX_STRING_LENGTH - 1);
        mEmail[MAX_STRING_LENGTH - 1] = 0;
        return false;
    }
}

bool Student::setSsn(const char ssn[])
{
    if(std::strlen(ssn) == 11) {
        std::strcpy(mSocial, ssn);
        std::cout << "Social Param: " << ssn << "\n";
        return true;
    }
    mSocial[0] = 0;
    return false;
}


std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
    int age = rhs.getAge();
    char last_name[MAX_STRING_LENGTH];
    char first_name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char social[12];

    std::strcpy(last_name, rhs.getLast());
    std::strcpy(first_name, rhs.getFirst());
    std::strcpy(email, rhs.getEmail());
    std::strcpy(social, rhs.getSsn());

    std::cout << "Output Before if: " << "\n";

    std::cout << "Age: " << age << "\n";
    std::cout << "Last: " << last_name << "\n";
    std::cout << "First: " << first_name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Social: " << social << "\n";

    if(strcmp(last_name, "") == 0) {
        std::strcpy(last_name, "NONE");
    }
    if(strcmp(first_name, "") == 0) {
        std::strcpy(first_name, "NONE");
    }
    if(strcmp(email, "") == 0) {
        std::strcpy(email, "NONE");
    }
    if(strcmp(social, "") == 0) {
        std::strcpy(social, "NONE");
    }
    std::cout << "Output After if: " << "\n";

    std::cout << "Age: " << age << "\n";
    std::cout << "Last: " << last_name << "\n";
    std::cout << "First: " << first_name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Social: " << social << "\n";

    os << age << " " << last_name << " " << first_name << " " << email << " " << social;
    return os;
}

std::istream &operator>>(std::istream &is, Student &rhs)
{
    int age;
    char last_name[MAX_STRING_LENGTH];
    char first_name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char social[12];

    is >> age >> last_name >> first_name >> email >> social;

    std::cout << "Before if: " << "\n";

    std::cout << "Age: " << age << "\n";
    std::cout << "Last: " << last_name << "\n";
    std::cout << "First: " << first_name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Social: " << social << "\n";

    if(is)
    {
        if(strcmp(last_name, "NONE") == 0) {
            last_name[0] = 0;
        }
        if(strcmp(first_name, "NONE") == 0) {
            first_name[0] = 0;
        }
        if(strcmp(email, "NONE") == 0) {
            email[0] = 0;
        }
        if(strcmp(social, "NONE") == 0) {
            social[0] = 0;
        }

        std::cout << "After if: " << "\n";

        std::cout << "Age: " << age << "\n";
        std::cout << "Last: " << last_name << "\n";
        std::cout << "First: " << first_name << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Social: " << social << "\n";

        Student tmp(age, last_name, first_name, email, social);
        rhs = tmp;
    }
    return is;
}
