#include "bag.h"

// CONSTRUCTORS

// pre: none
// post: creates an initially empty Bag
Bag::Bag(){
  size_=0;
}

// pre: size tells us how many ints are in arr
// post: creates an initially empty Bag
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
