

#include "dynamicbag.h"

// CONSTRUCTORS

// pre: none
// post: creates an initially empty Bag
DynamicBag::DynamicBag(){
  used_=0;
  data_=nullptr;//There isn't any memory yet
  capacity_ = 0;
}

// pre: size tells us how many ints are in arr

DynamicBag::DynamicBag(int arr[], std::size_t size){
  //if(size>capacity_)//capacity_ doesn't have a value yet
  capacity_ = size*2;
  data_ = new int[capacity_];
  used_ = size;
  for(std::size_t i=0; i<used_; i++){
    data_[i]=arr[i];
  }
}
DynamicBag::~DynamicBag(){//we won't call it, C++ will call it for us
  delete [] data_;//Only REQUIRED thing
  capacity_=0;
  used_=0;
  data_ =nullptr;
}
// pre: none
// post: if target appears in this Bag, returns the number of times it appears
//       else, returns 0
std::size_t DynamicBag::count(int target) const{
  std::size_t counter=0;
  for(std::size_t i=0; i<used_; i++){
    if(data_[i]==target)
      counter++;
  }
  return counter;
}

// pre: none  (NEW!  Before we used the built-in one)
// post: makes this bag a copy of b
void DynamicBag::operator =(const DynamicBag &b){
  if(this==&b)
    return;
  if(capacity_ != b.capacity_){
    capacity_=b.capacity_;
    used_=b.used_;

    delete [] data_;

    data_ = new int[capacity_];
    for(std::size_t i=0; i < used_; i++){
      data_[i] = b[i];
    }
  }
  else{
    used_ = b.used_;
    for(std::size_t i=0; i < used_; i++){
    data_[i] = b[i];
    }
  }
}








// pre: none
// post: adds a copy of target to this DynamicBag
void DynamicBag::insert(int target){
  if(used_==capacity_){
    std::size_t new_capacity;
    if(capacity_==0){
      new_capacity = 2;
    }
    else {
      new_capacity = 2*capacity_;
    }
    //we have to make it bigger!
    int * temp = new int[new_capacity];
    for(std::size_t i=0; i<capacity_; i++){
      temp[i]=data_[i];
    }
    delete [] data_;
    data_=temp;
    temp = nullptr;//Not necessary, but not a bad idea
    capacity_=new_capacity;
  }
  data_[used_] = target;
  used_++;
}
//To "make a dynamic array bigger"
//1: Allocate new memory
int * temp = new int[20];
//2: copy from old memory into new memory
for(int i=0; i<10; i++){
  temp[i]=pa[i];
}
//3: Get rid of old memory
delete [] pa;
//4: Reset pointer
pa = temp;
//5 (optional)  reset temp to point at "nothing"
temp = nullptr;







// pre: size() + b.size() <= CAPACITY
// post: adds a copy of each element of b to this Bag
void DynamicBag::operator += (const Bag & b){
  //Since b is const, can only call const functions
  //Even though we're inside the class,
  //can't access members
  for(int i=0;i<b.used_(); i++){
    insert(b[i]);
  }
}

// pre: none
// post: if target appears in this Bag, removes one copy of target and returns true
//       else returns false
bool DynamicBag::erase_one(int target){
  int index=used_;
  for(std::size_t i=0; i<used_; i++){
    if(data_[i]==target)
        index=i;
  }
  if(index!=used_){
    for(int i = index; i<used_-1; i++){
      data_[i] = data_[i+1];
    }
    used_--;
    if(used_ <= 0.25*capacity_){
      int *temp = new int[capacity_ / 2];
      for(std::size_t i = 0; i < used_; i++) {
        temp[i] = data_[i];
       }
       delete [] data_;
       data_ = temp;
       capacity_ = capacity_ / 2;
       temp = nullptr;
     }
        
    return true;
  }
  else{
    return false;
  }
}

// pre: none
// post: if target appears in this Bag k times, removes all copies and returns k
//       else returns 0
int DynamicBag::erase(int target){
  int count = 0;
  while(erase_one(target)){
    count++;
  }
  return count;
}
std::ostream& operator<<(std::ostream&  out, const Bag& b){
  for(int i = 0; i<b.size(); i++){
    out<<b[i]<<" ";
  }
  return out;
}

// pre: b1.size() + b2.size() <= CAPACITY
// post: returns a Bag containing all elements in b1 and b2
Bag operator + (const Bag & b1, const Bag & b2){
  assert(b1.size() + b2.size() <= Bag::CAPACITY);
  Bag ret;
  ret+=b1;
  ret+=b2;
  return ret;
}
/*
#include "bag.h"

// CONSTRUCTORS

// pre: none
// post: creates an initially empty Bag
Bag::Bag(){
  size_=0;
}

// pre: size tells us how many ints are in arr

Bag::Bag(int arr[], int size){
  size_ = size;
  for(int i=0; i<size_; i++){
    data_[i]=arr[i];
  }
}

// pre: none
// post: if target appears in this Bag, returns the number of times it appears
//       else, returns 0
int Bag::count(int target) const{
  int counter=0;
  for(int i=0; i<size_; i++){
    if(data_[i]==target)
      counter++;
  }
  return counter;
}

// pre: size() < CAPACITY
// post: a copy of target has been added to this Bag
void Bag::insert(int target){
  assert(size_<CAPACITY);
  data_[size_] = target;
  size_++;
}


// pre: size() + b.size() <= CAPACITY
// post: adds a copy of each element of b to this Bag
void Bag::operator += (const Bag & b){
  //Since b is const, can only call const functions
  //Even though we're inside the class,
  //can't access members
  assert(size_ + b.size() <= CAPACITY);
  for(int i=0;i<b.size(); i++){
    insert(b[i]);
  }
}

// pre: none
// post: if target appears in this Bag, removes one copy of target and returns true
//       else returns false
bool Bag::erase_one(int target){
  int index;
  for(int i=0; i<size_; i++){
    if(data_[i]==target)
        index=i;
  }
  if(index!=size_){
    for(int i = index; i<size_-1; i++){
      data_[i] = data_[i+1];
    }
    size_--;
    return true;
  }
  else{
    return false;
  }
}

// pre: none
// post: if target appears in this Bag k times, removes all copies and returns k
//       else returns 0
int Bag::erase(int target){
  int count = 0;
  while(erase_one(target)){
    count++;
  }
  return count;
}
std::ostream& operator<<(std::ostream&  out, const Bag& b){
  for(int i = 0; i<b.size(); i++){
    out<<b[i]<<" ";
  }
  return out;
}

// pre: b1.size() + b2.size() <= CAPACITY
// post: returns a Bag containing all elements in b1 and b2
Bag operator + (const Bag & b1, const Bag & b2){
  assert(b1.size() + b2.size() <= Bag::CAPACITY);
  Bag ret;
  ret+=b1;
  ret+=b2;
  return ret;
}
*/








































/*
    // CONSTRUCTORS

    // pre: none
    // post: creates an initially empty DynamicBag
    DynamicBag::DynamicBag(){
      used_ = 0;
      capacity_ = 0;
      data_ = nullptr;
    }

    // copy constructor  (NEW! Before we used the built-in one)
    //e.g:  DynamicBag b2 = b1; OR DynamicBag b2(b1);
    // pre: none
    // post: creates a new DynamicBag which is a copy of the given one
    DynamicBag::DynamicBag(const DynamicBag &b){
      used_ = b.used_;
      capacity_ = b.capacity_;
      data_ = new int[capacity_];
      for(size_type i = 0; i<used_; ++i){
        data_[i] = b[i];
      }
    }
/*  This is what the built-in copy constructor (shallow copy) does.  Problem??
    DynamicBag::DynamicBag(const DynamicBag &b){
      used_ = b.used_;
      capacity_ = b.capacity_;
      data_ = b.data_;
    }
*/
/*
    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void DynamicBag::operator =(const DynamicBag &b){
      //this is a _pointer_ to the object you're inside of
      if(this==&b){
        return;//this.count(5);NO!!!!!!!!!!!!!!!!!!
      }//   (*this).count(5);  OR this->count();
      else{
        used_ = b.used_;
        capacity_ = b.capacity_;
        delete [] data_;
        data_ = new int[capacity_];//if = was called by b=b, what is the problem here?
        for(size_type i = 0; i<used_; ++i){//Values in the old array are lost!
          data_[i] = b[i];
        }
      }
    }


    // pre: none    (NEW!  Our first destructor)
    // post: destroys this DynamicBag; needed because we are using
    //       dynamically allocated memory
    //Called automatically by C++ when an object ceases to exist
    DynamicBag::~DynamicBag(){
        delete [] data_;//This is all you NEED
        data_ = nullptr;
        capacity_ = 0;
        used_ = 0;
    }

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    int DynamicBag::operator [](size_type pos) const{
      assert(pos<capacity_);
      return data_[pos];
    }

    // pre: none
    // post: if target appears in this DynamicBag, returns the number of times it appears
    //       else, returns 0
    //typename:  promises C++ that DynamicBag::size_type is a type
    typename DynamicBag::size_type DynamicBag::count(int target) const{
      size_type count = 0;
      for(size_type i = 0; i<used_; ++i){
        if(data_[i]==target)
          ++count;
      }
      return count;
    }


    // MODIFICATION (MUTATOR) MEMBER FUNCTIONS

    // pre: none
    // post: adds a copy of target to this DynamicBag
    void DynamicBag::insert(int target){
      if(used_>=capacity_){//== is fine
        int newsize = 0;
        if(capacity_ ==0)
          newsize = 1;
        else
          newsize = capacity_*2;
        int * temp = new int[newsize];
        for(std::size_t i = 0; i<used_; ++i){
          temp[i] = data_[i];
        }
        delete [] data_;
        data_ = temp;
        temp = nullptr;
        capacity_ = newsize;

      }
      data_[used_] = target;
      ++used_;
    }

    // pre: none
    // post: adds to this DynamicBag a copy of each element of b
    void DynamicBag::operator += (const DynamicBag & b){//Homework!!
      assert(used_+b.size()<=capacity_);
      for(size_type i = 0; i<b.size(); ++i){
        insert(b[i]);
      }

    }

    // pre: none
    // post: if target appears in this DynamicBag, removes one copy of target and returns true
    //       else returns false
    //Why would we want to reallocate memory in erase_one??
    bool DynamicBag::erase_one(int target){
      size_type i = 0;
      for(i = 0; i<used_ &&data_[i]!=target; ++i){
      }
      if(i==used_)
        return false;
      else{
        for(size_type j = i; j<used_-1; ++j){
          data_[j] = data_[j+1];
        }
        --used_;
        return true;
      }
      if(used_<.25*capacity_){
        int* temp = new int[capacity_/2];
        for(size_type i = 0; i<used_; ++i)
          temp[i] = data_[i];
        delete [] data_;
        data_ = temp;
        temp = nullptr;
        capacity_ = .5*capacity_;
      }
    }

    // pre: none
    // post: if target appears in this DynamicBag k times, removes all copies and returns k
    //       else returns 0
    typename DynamicBag::size_type DynamicBag::erase(int target)
    {
      size_type count = 0;
      while(erase_one(target)){++count;}
      return count;
    }


// pre: b1.size() + b2.size() <= capacity_
// post: returns a DynamicBag containing all elements in b1 and b2
DynamicBag operator + (const DynamicBag & b1, const DynamicBag & b2){
  DynamicBag b;
  for(DynamicBag::size_type i = 0; i<b1.size(); ++i)
    b.insert(b1[i]);
  for(DynamicBag::size_type i = 0; i<b2.size(); ++i)
    b.insert(b2[i]);
  return b;
}

std::ostream& operator<<(std::ostream&  out, const DynamicBag& b){
  for(DynamicBag::size_type i = 0; i<b.size(); ++i)
    out<<b[i]<< " ";
  out<<std::endl;
  return out;
}
*/
