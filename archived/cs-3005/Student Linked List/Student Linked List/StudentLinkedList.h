#ifndef _STUDENTLINKEDLIST_H_
#define _STUDENTLINKEDLIST_H_

#include "Student.h"

class Node
{
public:
    Node();
    Node(Student, Node *next);
    
    Student mData;
    Node *mNext;
};

class StudentLinkedList
{
    public:
        StudentLinkedList();
        StudentLinkedList(const StudentLinkedList &src);
        ~StudentLinkedList();

        StudentLinkedList &operator=(const StudentLinkedList &rhs);

        bool Exists(const Student &key) const;
        bool Insert(const Student &value);
        bool Delete(const Student &key);
        Student Retrieve(const Student &key);

        Node *mHead;
};

std::ostream &operator<<(std::ostream &os, const StudentLinkedList &rhs);
std::istream &operator>>(std::istream &is, StudentLinkedList &rhs);

#endif
