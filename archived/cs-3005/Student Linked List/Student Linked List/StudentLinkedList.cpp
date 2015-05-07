
#include "StudentLinkedList.h"

Node::Node()
: mNext(0)
{
    
}

Node::Node(Student value, Node *next)
: mData(value), mNext(next)
{
    
}

StudentLinkedList::StudentLinkedList()
{
    mHead = 0;
}

StudentLinkedList::StudentLinkedList(const StudentLinkedList &src)
{
    mHead = src.mHead;
}

StudentLinkedList::~StudentLinkedList()
{
//    Student *curr = mHead;
//    while (curr) {
//        Delete(*curr);
//        curr = curr->next;
//    }
//    mHead = 0;
}

StudentLinkedList &StudentLinkedList::operator=(const StudentLinkedList &rhs)
{
    mHead = rhs.mHead;
    return *this;
}

bool StudentLinkedList::Exists(const Student &key) const
{
    Node *curr = mHead;
    while (curr) {
        if (curr->mData == key) {
            return true;
        } else {
            curr = curr->mNext;
        }
    }
    return false;
}
bool StudentLinkedList::Insert(const Student &value)
{
    if (Exists(value)) {
        return false;
    } else {
        Node *newNode = new Node(value, mHead);
        newNode->mNext = mHead;
        mHead = newNode;
        return true;
    }
}
bool StudentLinkedList::Delete(const Student &key)
{
    Node *curr;
    Node *prev = 0;
    for(curr = mHead; curr; prev = curr, curr = curr->mNext) {
        if(curr->mData == key) {
            if(prev) {
                prev->mNext = curr->mNext;
            } else {
                mHead = curr->mNext;
            }
            return true;
        }
    }
    return false;
}

Student StudentLinkedList::Retrieve(const Student &key)
{
    Node *curr = mHead;
    while (curr) {
        if (curr->mData == key) {
            return curr->mData;
        } else {
            curr = curr->mNext;
        }
    }
    return Student();
}

//Add the stream operators to the StudentLinkedList class.
//The output operator should display each of the Student objects in the list, using the operator already defined for the Student class. Put a newline after each object's output, except the last one.
//
//The input operator should read each Student object from the input, and add it to the list. It should continue until the end of input is reached.

//Notes:
//
//It may be necessary to add one or more methods to facilitate these operators. Use your judgement.


std::ostream &operator<<(std::ostream &os, const StudentLinkedList &rhs)
{
    Node *curr = rhs.mHead;
    while (curr) {
        os << "\n" << curr->mData;
        curr = curr->mNext;
    }
    return os;
}

std::istream &operator>>(std::istream &is, StudentLinkedList &rhs)
{
    while (is) {
        Student *student = new Student();
        is >> *student;
        rhs.Insert(*student);
    }
    return is;
}

