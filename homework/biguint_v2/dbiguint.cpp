#include "dbiguint.h"

dbiguint::dbiguint(){
  capacity_ = 1;
  data_ = new unsigned short[capacity_];
  data_[0]=0;
}

dbiguint::dbiguint(const std::string & s){
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++){
    assert(isdigit(s[i]));
    data_[i] = s[s.length() - 1 - i]-'0';
  }
}

dbiguint::~dbiguint(){
  delete [] data_;
  capacity_ = 0;
  data_=nullptr;
}

std::size_t dbiguint::size() const{
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos)const{
  if (pos >= capacity_){
    return 0;
  }
  return data_[pos];
}

void dbiguint::reserve(std::size_t newcapacity_){
  if (newcapacity_>capacity_){
    unsigned short* temp = new unsigned short [newcapacity_];
    for (std::size_t i =0; i<newcapacity_;i++){
      temp[i] = (i<capacity_) ? data_[i]: 0;
    }
    capacity_=newcapacity_;
    delete []data_;
    data_=temp;
    temp=nullptr;
  }
  else if(newcapacity_<capacity_){
    unsigned short* temp = new unsigned short [newcapacity_];
    for(std::size_t i = 0; i < newcapacity_; i++) {
      temp[i] = data_[i];
    }
    capacity_ = newcapacity_;
    delete [] data_;
    data_ = temp;
    temp = nullptr;
  }
}


void dbiguint::operator += (const dbiguint & b){
  int sum;
  int one=0;
  std::size_t newcapacity_=(b.capacity_>capacity_) ? b.capacity_ : capacity_;
  reserve(newcapacity_);
  for (std::size_t i=0;i<capacity_;i++){
    sum=data_[i]+b[i]+one;
    if (sum>=10){
      sum%=10;
      one=1;
    }
    else{
      one = 0;
    }
    data_[i]=sum;
  }
  if (one == 1){
    reserve(capacity_+1);
    data_[capacity_-1]=1;
  }
} 

void dbiguint::operator -=(const dbiguint & b){

  int rest, carry(0), sus;
  std::size_t max_index(0), counter(0);

  if(compare(b) == 1){
    for(std::size_t i = 0; i < capacity_; i++){
      if(i >= b.capacity_)
        sus = 0;
      else
        sus = b[i];

      if(data_[i] < sus){
        rest = (data_[i] + 10 + carry) - sus;
        data_[i] = rest;
        carry = -1;
      }
      else{
        rest = (data_[i] + carry) - sus;
        if(rest == -1){
          rest = 9;
          carry = -1;
        }
        else{
          carry = 0;
        }
        data_[i] = rest;
      }
    }

    for(std::size_t i = capacity_ - 1; i>=0; i--){
      if(data_[i] != 0)
       counter++;
      if(counter == 0){
       if(i==0)
        break;
       else
        continue;
      }
      else{
        max_index = i;
        break;
      }
    }

    reserve(max_index + 1);
  }
  else{
    reserve(1);
    data_[0]=0;
  }
}

void dbiguint::operator *=(const dbiguint & b){
  dbiguint zero, one("1"), counter, add;

  if(*this == zero || b == zero){
    *this = zero;
    return;
  }

  add = *this;
  counter = b;
  while(counter.compare(one) != 0){
    *this = *this + add;
    counter -= one;
  }
}

void dbiguint::operator = (const dbiguint & b){
  if(this==&b)
    return;

  if(capacity_ == b.capacity_){
    for(std::size_t i = 0; i < capacity_; i++){
      data_[i] = b[i];
    }
  }
  else{

    capacity_ = b.capacity_;

    delete [] data_;
    data_ = new unsigned short[capacity_];
    for(std::size_t i = 0; i < capacity_; i++){
      data_[i] = b[i];
    }
  }
}


int dbiguint::compare(const dbiguint & b) const{
  std::size_t max_index(0), bmax_index(0);
  int counter(0);

  for(std::size_t i = capacity_ - 1; i>=0; i--){
    if(data_[i] != 0)
      counter++;
    if(counter == 0){
      if(i==0)
        break;
      else
        continue;
    }
    else
      max_index = i;
      break;
  }
  
  counter = 0;
  for(std::size_t i = b.capacity_ - 1; i>=0; i--){
    if(b[i] != 0)
      counter++;
    if(counter == 0){
      if(i==0)
        break;
      else
        continue;
    }
    else
      bmax_index = i;
      break;
  }

  if(max_index > bmax_index)
    return 1;
  else if(max_index < bmax_index)
    return -1;

  if(max_index == bmax_index){
    for(std::size_t i = max_index; i>=0; i--){
      if(data_[i] > b[i])
        return 1;
      else if(data_[i] < b[i])
        return -1;

      if(i == 0)
        break;
    }
  }

  return 0;
}

bool operator < (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) == -1)
    return true;
  else
    return false;
}

bool operator > (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) == 1)
    return true;
  else
    return false;
}

bool operator <= (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) == -1 || a.compare(b) == 0)
    return true;
  else
    return false;
}

bool operator >= (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) == 1 || a.compare(b) == 0)
    return true;
  else
    return false;
}

bool operator == (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) == 0)
    return true;
  else
    return false;
}

bool operator != (const dbiguint & a, const dbiguint & b){
  if(a.compare(b) != 0)
    return true;
  else
    return false;
}

dbiguint operator +(const dbiguint & a, const dbiguint & b){
  dbiguint sum;

  sum += a;
  sum += b;

  return sum;
}

dbiguint operator -(const dbiguint & a, const dbiguint & b){
  dbiguint rest;

  rest = a;
  rest -= b;

  return rest;
}

dbiguint operator *(const dbiguint & a, const dbiguint & b){
  dbiguint product;

  product = a;
  product *= b;

  return product;
}



std::istream & operator >> (std::istream & in, dbiguint & b){

  std::string number;

  in>>number;
  b = dbiguint(number);

  return in;
}

// std::istream & operator >> (std::istream & in, dbiguint & b){

//   for(std::size_t i = 0; i < b.size(); i++) {
//     in>>b[i];
//   }

//   return in;
// }



// std::istream & operator >> (std::istream & in, dbiguint & b){

//   unsigned short digit;

//   for(std::size_t i = 0; i < b.size(); i++) {
//     in>>digit;
//     b[i]=digit;
//   }

//   return in;
// }


std::ostream& operator <<(std::ostream& out, const dbiguint& b){
  for (std::size_t i =b.size()-1; i>=0; i--){
    out<<b[i];
    if(i==0)
      break;
  }
  return out;
}