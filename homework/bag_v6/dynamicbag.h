#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>






template <typename T>
class dynamicBag
{
public:
    typedef std::size_t size_type;
    //typedef array_iterator<T> iterator;
    typedef T* iterator;
    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty dynamicBag
    dynamicBag();

    // copy constructor  (NEW! Before we used the built-in one)
    // pre: none
    // post: creates a new dynamicBag which is a copy of the given one
    dynamicBag(const dynamicBag &);

    // pre: none    (NEW!  Our first destructor)
    // post: destroys this dynamicBag; needed because we are using
    //       dynamically allocated memory
    ~dynamicBag();

    // CONSTANT MEMBERS
    // pre: none
    // post: returns the number of elements in this dynamicBag
    size_type size() const;

    // pre: none
    // post: returns the number of times entry appears in this dynamicBag
    size_type count(const T& entry) const;//Now that T could be a giant type, const&

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    T operator [](size_type pos) const;

    // MUTATING MEMBERS

    // pre: none
    // post: adds a copy of target to this dynamicBag
    void insert(const T& target);

    // pre: none
    // post: adds to this dynamicBag a copy of each element of b
    void operator += (const dynamicBag & b);

    // pre: none
    // post: if target appears in this dynamicBag, remove one copy and
    //       return true; else return false

    bool erase_one(const T& target);

    // pre: none
    // post: removes every copy of target in this dynamicBag and
    //       returns the number of elements removed
    size_type erase(const T& target);

    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void operator =(const dynamicBag &b);

    //iterator is just another name for T*
    iterator begin(){
      //iterator i= &data_[0];
      //&data_[0] = &*(data_+0) = data_
      iterator i = data_;
      return i;

    }


    iterator end(){
      iterator i=(data_+used_); //= &data_[used_]
      return i;
    }


private:
    T *data_;
    size_type capacity_;
    size_type used_;

    // INVARIANTS:
    //   data_ points a dynamically allocated array of size capacity_
    //   data_[0], data_[1], ..., data_[used_-1] store the elements
    //   of this dynamicBag
    //   we don't care about data_[used_], ..., data_[capacity_]


};

// pre: none
// post: returns the sum of a and b
template <typename T>
dynamicBag<T> operator +(const dynamicBag<T> & a, const dynamicBag<T> & b);

template <typename T>
dynamicBag<T>::dynamicBag(){
    used_ = 0;
    capacity_ = 0;
    data_ = NULL;//NULL doesn't have a type
}

template <typename T>
dynamicBag<T>::dynamicBag(const dynamicBag<T>& b){//Copy constructor
    capacity_ = b.capacity_;
    used_ = b.used_;
    data_ = new T[capacity_];
    for(size_type i = 0; i<used_; i++)
        data_[i] = b.data_[i];

}

template <typename T>
void dynamicBag<T>::operator =(const dynamicBag<T> &b){//because the built-in = just does data_ = b._data, so they share memory, which is bad!!
    if(this == &b){
        return;
    }
    if(capacity_!=b.capacity_){
        capacity_ = b.capacity_;
        delete [] data_;//add
        this->data_ = new T[capacity_];//(*this).data_
    }
    used_ = b.used_;
    for(size_type i = 0; i<used_; i++)
        data_[i] = b.data_[i];
}
template <typename T>
dynamicBag<T>::~dynamicBag(){//deallocate memory when an object is destroyed
    delete [] data_;//MUST HAVE
    data_ = NULL;//rest is nice to have
    capacity_ = 0;
    used_ = 0;
}

template <typename T>
typename dynamicBag<T>::size_type dynamicBag<T>::size() const{
 return used_;
}

template <typename T>
typename dynamicBag<T>::size_type dynamicBag<T>::count(const T& target) const{
    size_type count = 0;
    for(size_type i = 0; i<used_; i++){
     if(data_[i] == target)
         count++;
    }
    return count;

}

template <typename T>
T dynamicBag<T>::operator [](size_type pos) const {return data_[pos];}

template <typename T>
void dynamicBag<T>::insert(const T& target){
    if(used_==0 &&capacity_==0){
     T* newptr = new T[1];
    data_ = newptr;
    capacity_=1;
    }
    else if(used_==capacity_){
     T* newptr = new T[capacity_*2];
     for(size_type i = 0; i<capacity_; ++i){
         newptr[i] = data_[i];
    }
    delete [] data_;
    data_ = newptr;
    capacity_*=2;
    }
    data_[used_] = target;
    used_++;
}

template <typename T>
bool dynamicBag<T>::erase_one(const T& target){

    size_type i = 0;
    while(data_[i]!=target && i<used_) i++;

    if(i==used_)
        return false;
    else{
        for(size_type j=i; j<used_-1; j++){
        data_[j] = data_[j+1];
        }
        used_--;

        if(used_<=.25*capacity_){
            T* newptr = new T[capacity_/2];
            for(size_type i = 0; i<used_; ++i){
                newptr[i] = data_[i];
            }
            delete [] data_;
            data_ = newptr;
            capacity_/=2;
        }

        return true;
    }
}
/*
void dynamicBag::operator +=(const dynamicBag& b){//This will be homework
 assert(size()+b.size()<=CAPACITY);
 for(size_type i = 0; i<b.size(); i++)
 {
     insert(b[i]);
 }
}
*/
template <typename T>
typename dynamicBag<T>::size_type dynamicBag<T>::erase(const T& target){

    size_type count=0;
    while(erase_one(target)) count++;
    return count;
}


template <typename T>
dynamicBag<T> operator +(const dynamicBag<T> & a, const dynamicBag<T> & b){
    dynamicBag<T> ret;
    ret+= a;
    ret+=b;
    return ret;
}
#endif // DYNAMICBAG_H
