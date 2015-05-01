
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <iostream>

/////////////////////////
// Node Template Class //
/////////////////////////
template<class T>
class Node
{
public:
    Node();
    Node(T, Node *next);
    
    T mData;
    Node *mNext;
};

template<class T>
Node<T>::Node()
: mNext(0)
{
    
}

template<class T>
Node<T>::Node(T value, Node<T> *next)
: mData(value), mNext(next)
{
    
}


///////////////////////////////
// LinkedList Template Class //
///////////////////////////////
template<class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList &src);
    ~LinkedList();
    
    LinkedList &operator=(const LinkedList &rhs);
    
    bool Exists(const T &key) const;
    bool Insert(const T &value);
    bool Delete(const T &key);
    T Retrieve(const T &key);
    
    Node<T> *mHead;
};

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &rhs);

template<class T>
std::istream &operator>>(std::istream &is, LinkedList<T> &rhs);



/////////////////////////////////
// LinkedList Class Definition //
/////////////////////////////////
template<class T>
LinkedList<T>::LinkedList()
{
    mHead = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &src)
{
    mHead = src.mHead;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    //    Student *curr = mHead;
    //    while (curr) {
    //        Delete(*curr);
    //        curr = curr->next;
    //    }
    //    mHead = 0;
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    mHead = rhs.mHead;
    return *this;
}

template<class T>
bool LinkedList<T>::Exists(const T &key) const
{
    Node<T> *curr = mHead;
    while (curr) {
        if (curr->mData == key) {
            return true;
        } else {
            curr = curr->mNext;
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::Insert(const T &value)
{
    if (Exists(value)) {
        return false;
    } else {
        Node<T> *newNode = new Node<T>(value, mHead);
        newNode->mNext = mHead;
        mHead = newNode;
        return true;
    }
}

template<class T>
bool LinkedList<T>::Delete(const T &key)
{
    Node<T> *curr;
    Node<T> *prev = 0;
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

template<class T>
T LinkedList<T>::Retrieve(const T &key)
{
    Node<T> *curr = mHead;
    while (curr) {
        if (curr->mData == key) {
            return curr->mData;
        } else {
            curr = curr->mNext;
        }
    }
    return T();
}

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList &rhs)
{
    Node<T> *curr = rhs.mHead;
    while (curr) {
        os << "\n" << curr->mData;
        curr = curr->mNext;
    }
    return os;
}

template<class T>
std::istream &operator>>(std::istream &is, LinkedList &rhs)
{
    while (is) {
        T *student = new T();
        is >> *student;
        rhs.Insert(*student);
    }
    return is;
}

#endif
