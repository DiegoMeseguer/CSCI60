#include "dynamicbag.h"

// CONSTRUCTORS

// pre: none
// post: creates an initially empty Bag
DynamicBag::DynamicBag(){
  capacity_=0;
  used_=0;
  data_=nullptr; //there isn't any memory yet
}

// pre: size tells us how many ints are in arr
// post: creates an initially empty Bag
DynamicBag::DynamicBag(int arr[], std::size_t size){
  capacity_ = size * 2;
  used_ = size;

  data_ = new int[capacity_];

  for(std::size_t i=0; i<used_; i++){
    data_[i]=arr[i];
  }
}

DynamicBag::~DynamicBag(){
  delete [] data_;
  capacity_ = 0;
  used_ = 0;
  data_ = nullptr;
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

// pre: size() < CAPACITY
// post: a copy of target has been added to this Bag
void DynamicBag::insert(int target){
  if(used_ == capacity_){
    //we have to make the bag bigger
    std::size_t new_capacity;
    if(capacity_ == 0)
      new_capacity = 2;
    else
      new_capacity = 2 * capacity_;
    int *temp = new int[new_capacity];
    for(std::size_t i = 0; i < used_; i++){
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    temp = nullptr;
    capacity_ = new_capacity;
  }

  data_[used_] = target;
  used_++;
}

// // pre: size() + b.size() <= CAPACITY
// // post: adds a copy of each element of b to this Bag
// void Bag::operator += (const Bag & b){
//   //Since b is const, can only call const functions
//   //Even though we're inside the class,
//   //can't access members
//   assert(size_ + b.size() <= CAPACITY);
//   for(int i=0;i<b.size(); i++){
//     insert(b[i]);
//   }
// }

//  bool Bag::erase_one(int target){
//   int temp;
//   bool ans;

//   for(int i = 0; i < size(); i++){
//     if(data_[i] == target){
//       for(int j = i; j < size() - 1; j++){
//         temp = data_[j];
//         data_[j] = data_[j + 1];
//         data_[j + 1] = temp;        
//       }
//       ans = true;
//       size_--;
//       break;
//     }
//     ans = false;
//   }

//   return ans;
//  }

// int Bag::erase(int target){
//   int counter;

//   counter = count(target);

//   for(int i = 0; i < counter; i++)
//     erase_one(target);

//   return counter;
// }
//===============================
// // pre: none
// // post: if target appears in this Bag, removes one copy of target and returns true
// //       else returns false
// bool Bag::erase_one(int target){
//   int index;
//   for(int i=0; i<size_; i++){
//     if(data_[i]==target)
//         index=i;
//   }
//   if(index!=size_){
//     for(int i = index; i<size_-1; i++){
//       data_[i] = data_[i+1];
//     }
//     size_--;
//     return true;
//   }
//   else{
//     return false;
//   }
// }

// // pre: none
// // post: if target appears in this Bag k times, removes all copies and returns k
// //       else returns 0
// int Bag::erase(int target){
//   int count = 0;
//   while(erase_one(target)){
//     count++;
//   }
//   return count;
// }
// ============================
//  Bag operator + (const Bag & b1, const Bag & b2){
//   assert(b1.size() + b2.size() <= Bag::CAPACITY);

//   Bag sum;

//   sum += b1;
//   sum += b2;

//   return sum;
//  }

std::ostream& operator<<(std::ostream&  out, const DynamicBag& b){
  for(std::size_t i = 0; i<b.size(); i++){
    out<<b[i]<<" ";
  }

  return out;
}
