#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"


template <class T>
class l_iterator{

public:
    l_iterator(node<T>* initial = nullptr){//nullptr is a default value, so if no parameter is passed in
      //the function will run as if nullptr was passed in
      current = initial;
    }


    T operator *() const{
      return current->data();
    }


    l_iterator operator ++() // pre-increment ++i
    {
        current = current->link();
        return (*this);
        //return l_iterator(current);
    }

//int x=7;
//cout<<++x;
//print 8
//cout<<x
//print 8

    l_iterator operator ++(int) // post-increment  i++
    {//fake parameter just so we can tell pre- and post-increment apart
          l_iterator temp(current);
          current = current->link();
          return temp;
    }
    //int x=7;
    //cout<<x++;
    //print 7
    //cout<<x;
    //print 8;
    bool operator == (const l_iterator other) const
    {
        return current==other.current;
    }
//same node*** or same value
    bool operator != (const l_iterator other) const
    {
        return current!=other.current;

    }


private://Keep track of where one item in the linked list is
  node<T>* current;
};



template <class T>
class lbag
{
public:
    typedef l_iterator<T> iterator;


    typedef T value_type;
    typedef std::size_t size_type;

    // pre: none
    // post: creates an empty lbag
    lbag();

    // pre: none
    // post: creates an lbag that is a copy of given lbag
    lbag(const lbag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    ~lbag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const lbag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    size_type size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    size_type count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const lbag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    size_type erase(const T &);//homework

    iterator begin(){
      return iterator(head);
    }
    iterator end(){
      return iterator(nullptr);
    }


    template <class T2>//Don't use class's type variable, because this is NOT part of the class
    friend std::ostream& operator <<(std::ostream& out, const lbag<T2> &);

private:
    node<T> *head, *tail;
};

template <class T>
lbag<T> operator +(const lbag<T> &, const lbag<T> &);





template <class T>
lbag<T>::lbag(){
head = nullptr;
tail = nullptr;
}


template <class T>
lbag<T>::lbag(const lbag<T> & b){
    head = tail = nullptr;
    list_copy(b.head, b.tail, head, tail);
}

template <class T>
lbag<T>::~lbag(){
list_clear(head, tail);
head = tail = nullptr;
}

template <class T>
void lbag<T>::operator =(const lbag<T> & b){
    list_clear(head, tail);
    head = tail = nullptr;
    list_copy(b.head, b.tail, head, tail);
}


template <class T>
typename lbag<T>::size_type lbag<T>::size() const{
    list_size(head);/*
    size_type count = 0;
    for(node<T>* p = head; p!=nullptr; p=p->link())
        count++;
    return count;*/
}


template <class T>
typename lbag<T>::size_type lbag<T>::count(const T & value) const{
    size_type count = 0;
    for(node<T>* p = head; p!=nullptr; p=p->link()){
        if(p->data()==value)
            count++;
    }
    return count;
    /*
    node<T>* temp = list_search(head, value);
    size_type count = 0;
    while(temp!=nullptr){
        count++;
        temp = list_search(temp->link(), value);
    }
    return count;
 */
}

template <class T>
void lbag<T>::insert(const T & value){
    list_head_insert(head, tail, value);
}



template <class T>
std::ostream& operator <<(std::ostream& out, const lbag<T> & b){//Use << from linked list toolkit.  Problems?
out<<b.head;
return out;
}




#endif // LBAG_H
