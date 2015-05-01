#ifndef _NUMBERLIST_H_
#define _NUMBERLIST_H_


// const int MAX_STRING_LENGTH = 1024;

class NumberList
{
    public:
        /* constructors */
        NumberList();
        // copy constructor
        NumberList(const NumberList &src);
        //Destructor
        ~NumberList();
        // assignment operator
        NumberList &operator=(const NumberList &rhs);

        /* accessor methods */
        const int *getNumbers() const;
        int getNumberCount() const;
        bool addNumber(int new_num);
        bool clear();
        // const char *getLast() const;
        // const char *getFirst() const;
        // const char *getEmail() const;
        // const char *getSsn() const;
        // bool setAge(const int age);
        // bool setLast(const char last[]);
        // bool setFirst(const char first[]);
        // bool setEmail(const char email[]);
        // bool setSsn(const char ssn[]);

    private:
        /* data members */
        int mListLength;
        int * mNumArray;
};

// std::ostream &operator<<(std::ostream &os, const Student &rhs);
// std::istream &operator>>(std::istream &is, Student &rhs);



#endif // _NUMBERLIST_H_
