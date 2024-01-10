#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"

template <class T>
class LBag
{
public:

    // pre: none
    // post: creates an empty LBag
    LBag();

    // pre: none
    // post: creates an LBag that is a copy of given LBag
    LBag(const LBag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    //~LBag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const LBag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    std::size_t size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    std::size_t count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const LBag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    std::size_t erase(const T &);//homework

    template <class T2>
    friend std::ostream& operator <<(std::ostream& out, const LBag<T2> &);
    //friend functions can use private members

private:
    node<T> *head, *tail;
};

template <class T>
LBag<T> operator +(const LBag<T> &, const LBag<T> &);
//template <class T>//This is a template function because it operates on
//a template class object, but it is NOT a member function of a template class
//std::ostream& operator <<(std::ostream& out, const LBag<T> &);



    // pre: none
    // post: creates an empty LBag
    template <class T>
    LBag<T>::LBag(){
      head=nullptr;
      tail=nullptr;
    }

    // pre: none
    // post: creates an LBag that is a copy of given LBag
    template <class T>
    LBag<T>::LBag(const LBag & b){
      list_copy(b.head, b.tail, head, tail);
    }
//ways to call the copy constructor
//Lbag<int> lb(lb1);
//Lbag<int> lb = lb1;

    //Returns all memory to the runtime environment and
    //sets head and tail to nullptr
/*    template <class T>
    LBag<T>::~LBag(){
      list_clear(head, tail);
      head=nullptr;
      tail=nullptr;
    }
*/
    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    template <class T>
    void LBag<T>::operator =(const LBag & b){
      //list_clear(head, tail);
      list_copy(b.head, b.tail, head, tail);
    }

    //pre: none
    //post:  returns the number of nodes in the linked list
    template <class T>
    std::size_t LBag<T>::size() const{
      return list_size(head);
    }

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    template <class T>
    std::size_t LBag<T>::count(const T & value) const{
      //use list_search
      node<T>* p = head;
      std::size_t count = 0;
      while(p!=nullptr){
        p=list_search(p, value);
        if(p!=nullptr)
          p=p->link();
        count++;
      }
      return count-1;
    }

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    template <class T>
    void LBag<T>::insert(const T & value){
      list_head_insert(head, tail, value);
    }

    template <class T>
    std::ostream& operator <<(std::ostream& out,
      const LBag<T> & b){
        out<<b.head;
        return out;
      }


#endif // LBAG_H
