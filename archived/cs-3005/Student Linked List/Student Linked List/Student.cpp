#include "Student.h"


Student::Student()
    : mAge(0),
    mLastName(0),
    mFirstName(0),
    mEmail(0)
{
    mSocial[0] = 0;
}

Student::Student(
    const int age,
    const char *last_name,
    const char *first_name,
    const char *email,
    const char social[])
    : mAge(0),
    mLastName(0),
    mFirstName(0),
    mEmail(0)
{
    mSocial[0] = 0;

    setAge(age);
    setLast(last_name);
    setFirst(first_name);
    setEmail(email);
    setSsn(social);
}

Student::Student(const Student &src)
  : mAge(0),
    mLastName(0),
    mFirstName(0),
    mEmail(0)
{
    mSocial[0] = 0;
  *this = src;
}

// Destructor, deallocates the memory, if accessed.
Student::~Student()
{
    if(mLastName) {
        delete [] mLastName;
        mLastName = 0;
    }
    if(mFirstName) {
        delete [] mFirstName;
        mFirstName = 0;
    }
    if(mEmail) {
        delete [] mEmail;
        mEmail = 0;
    }
}

// Assignment operator uses Set methods to centralize
// the memory management work.
Student &Student::operator=(const Student &rhs)
{
    setAge(rhs.mAge);
    setLast(rhs.mLastName);
    setFirst(rhs.mFirstName);
    setEmail(rhs.mEmail);
    setSsn(rhs.mSocial);
    return *this;
}

bool Student::clear()
{
    return true;
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
    // release existing memory
    if(mLastName) {
        delete [] mLastName;
        mLastName = 0;
    }
    if(!last) {
        return false;
    }
    int i;
    int count = int(std::strlen(last));
    mLastName = new char[count + 1];

    // if memory was allocated, copy the data
    if(mLastName) {
        for(i = 0; i <= count; i++) {
            mLastName[i] = last[i];
        }
        mLastName[count] = '\0';
        return true;
    } else {
        return false;
    }
}

bool Student::setFirst(const char first[])
{
   // release existing memory
    if(mFirstName) {
        delete [] mFirstName;
        mFirstName = 0;
    }
    if(!first) {
        return false;
    }
    int i;
    int count = int(std::strlen(first));
    mFirstName = new char[count + 1];

    // if memory was allocated, copy the data
    if(mFirstName) {
        for(i = 0; i <= count; i++) {
            mFirstName[i] = first[i];
        }
        mFirstName[count] = '\0';
        return true;
    } else {
        return false;
    }
}

bool Student::setEmail(const char email[])
{
    // release existing memory
    if(mEmail) {
        delete [] mEmail;
        mEmail = 0;
    }
    if(!email) {
        return false;
    }
    int i;
    int count = int(std::strlen(email));
    mEmail = new char[count + 1];

    // if memory was allocated, copy the data
    if(mEmail) {
        for(i = 0; i <= count; i++) {
            mEmail[i] = email[i];
        }
        mEmail[count] = '\0';
        return true;
    } else {
        return false;
    }
}

bool Student::setSsn(const char ssn[])
{
    if(std::strlen(ssn) == 11) {
        std::strcpy(mSocial, ssn);
        return true;
    }
    mSocial[0] = 0;
    return false;
}

bool Student::operator==(const Student &rhs) const
{
    const char * lhs_social = getSsn();
    const char *rhs_social = rhs.getSsn();
    if (std::strcmp(lhs_social, rhs_social) == 0) {
        return true;
    }
    return false;
}
bool Student::operator!=(const Student &rhs) const
{
    const char * lhs_social = getSsn();
    const char *rhs_social = rhs.getSsn();
    if (std::strcmp(lhs_social, rhs_social) != 0) {
        return true;
    }
    return false;
}
bool Student::operator<(const Student &rhs) const
{
    if (std::strcmp(mSocial, rhs.mSocial) < 0) {
        return true;
    }
    return false;
}
bool Student::operator<=(const Student &rhs) const
{
    if (std::strcmp(mSocial, rhs.mSocial) <= 0) {
        return true;
    }
    return false;
}
bool Student::operator>(const Student &rhs) const
{
    if (std::strcmp(mSocial, rhs.mSocial) > 0) {
        return true;
    }
    return false;
}
bool Student::operator>=(const Student &rhs) const
{
    if (std::strcmp(mSocial, rhs.mSocial) >= 0) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
    int age = rhs.getAge();
    const char *last_name = rhs.getLast();
    const char *first_name = rhs.getFirst();
    const char *email = rhs.getEmail();
    char social[12];
    std::strcpy(social, rhs.getSsn());

    if(last_name == 0) {
        last_name = "NONE";
    }
    if(first_name == 0) {
        first_name = "NONE";
    }
    if(email == 0) {
        email = "NONE";
    }
    if(strcmp(social, "") == 0) {
        std::strcpy(social, "NONE");
    }

    os << age << " " << last_name << " " << first_name << " " << email << " " << social;

    return os;
}

std::istream &operator>>(std::istream &is, Student &rhs)
{
    int age;
    char *last_name = new char[MAX_STRING_LENGTH];
    char *first_name = new char[MAX_STRING_LENGTH];
    char *email = new char[MAX_STRING_LENGTH];
    char social[12];

    is >> age >> last_name >> first_name >> email >> social;

    if(is)
    {
        if(strcmp(last_name, "NONE") == 0) {
            last_name = 0;
        }
        if(strcmp(first_name, "NONE") == 0) {
            first_name = 0;
        }
        if(strcmp(email, "NONE") == 0) {
            email = 0;
        }
        if(strcmp(social, "NONE") == 0) {
            social[0] = 0;
        }
        Student tmp(age, last_name, first_name, email, social);
        rhs = tmp;
    }

    delete [] last_name;
    delete [] first_name;
    delete [] email;
    last_name = 0;
    first_name = 0;
    email = 0;
    return is;
}
