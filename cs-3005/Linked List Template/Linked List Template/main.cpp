//
//  main.cpp
//  Linked List Template
//
//  Created by Kaden Wilkinson on 3/18/15.
//  Copyright (c) 2015 Trendly Creations. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"
#include "StudentAux.h"
#include "IntAux.h"

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//    In this assignment, you will create a linked list to store any type of objects. It should be based on the results of your previous assignment, but converted into a class template. The template parameter is the type of data stored in the nodes of the list.
//
//    It will require any type to be stored to have the overloaded comparison operators, assignment operator, copy constructors, etc. Note that built-in types already have these.
//
//    The list will be an unordered, unique list. The list will use the comparison operators to insure uniqueness in the list.
//
//    Assignment
//
//    Convert the linked list of student class from the previous assignment into a template class. The template parameter is the type of data stored in the nodes of the list.
//
//    Each linked list will store unique items of the type specified.
//
//    When a list method needs a "search key", an object should be passed in by reference. Remember that only the fields of the object that are used in the comparison operator need be set for a key.
//
//    Implement the LinkedList class template.
//
//    Required methods of the class:
//
//    LinkedList() : default constructor
//    LinkedList(const StudentLinkedList &src) : copy constructor
//    ~LinkedList() : destructor
//    LinkedList &operator=(const LinkedList &rhs) : assignment operator
//    bool Exists(const Type &key) const : returns true if the Type object identified by key exists, false otherwise.
//    bool Insert(const Type &value) : returns true if the object was added to the list, false otherwise.
//    bool Delete(const Type &key) : returns true if the object was removed, false otherwise.
//    Type Retrieve(const Type &key) const : returns the object that matches the key, or the default object if none matches.
//    Additional notes:
//
//    The class must be stored in the file LinkedList.h.
//    The template must take 1 template parameter, the type of objects stored.
//    Insert must not add a duplicate item. (no duplicate entries).
//    Copy forward your code from Student.h and Student.cpp in the previous assignment.