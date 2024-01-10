#ifndef BAG_H//name of file all in caps, . becomes _
#define BAG_H

#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <ostream>

// WANT: a class Bag to store a collection of ints
//       (multiple copies are allowed)
//       there is a FIXED limit on how many elements can be in a
//       Bag called CAPACITY (same for every Bag)

// Supported operations:
//        size (number of elements in Bag), count number of times
//        a value appears in Bag insert, delete, find


class Bag{
public:
    // CONSTANTS and TYPES

    // known outside class as Bag::CAPACITY
     static const int CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates an initially empty Bag
    Bag();

    // pre: size tells us how many ints are in arr
    // post: creates an initially empty Bag
    Bag(int arr[], int size);

    // CONSTANT MEMBER FUNCTIONS

    // pre: none
    // post: returns the number of elements stored in this Bag
    int size() const{return size_;}

    // pre: none
    // post: if target appears in this Bag, returns the number of times it appears
    //       else, returns 0
    int count(int target) const;

    // pre: none
    // post: returns the item at given pos
    int operator [](int pos) const{return data_[pos];}

    // MODIFICATION (MUTATOR) MEMBER FUNCTIONS

    // pre: size() < CAPACITY
    // post: a copy of target has been added to this Bag
    void insert(int target);

    // pre: size() + b.size() <= CAPACITY
    // post: adds a copy of each element of b to this Bag
    void operator += (const Bag & b);

    // pre: none
    // post: if target appears in this Bag, removes one copy of target and returns true
    //       else returns false
    bool erase_one(int target);

    // pre: none
    // post: if target appears in this Bag k times, removes all copies and returns k
    //       else returns 0
    int erase(int target);

private:

    int data_[CAPACITY];
    int  size_;

    // INVARIANTS:

    // data_[0], data_[1], ..., data_[size_-1] contain the elements in this Bag
    // don't care about values in data_[size_], ..., data_[CAPACITY-1]

};

// pre: b1.size() + b2.size() <= CAPACITY
// post: returns a Bag containing all elements in b1 and b2
Bag operator + (const Bag & b1, const Bag & b2);

std::ostream& operator<<(std::ostream&  out, const Bag& b);
#endif // BAG_H
