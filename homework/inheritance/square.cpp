#include "square.h"
#include <iostream>
// pre: none
// post: creates a new Square with side 0, and name ""
Square::Square(){
  name_ = "";
}

// pre: side >= 0.0
// post: creates a new Square with given side and name
Square::Square(double side, const std::string & name)
:Rect(side, side){
  name_ = name;
}

//pre:  none
//post:  returns the name
std::string Square::name() const{
  return name_;
}

//pre: none
//post:  returns the side length of the square
double Square::side()const{
  return Rect::h();
}

// pre: none
// post: returns the area of this Rect and prints its name
double Square::area() const{//We can replace the base class' functions with our own implementations
//Note that in order to replace the base class' function, our function must have the same parameters.
  std::cout<<name_<<std::endl;
  return Rect::area();
}
