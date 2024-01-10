// Make the file #include-able
#ifndef RATIONAL_H  // if not defined, matching endif at the end
#define RATIONAL_H  // then define

#include <iostream>
#include <cassert>

using namespace std;

class Rational{
private:
    int numer;
    int denom;
public:
  //pre-condition: none
  //post-condition:  return the numerator
    int get_numer(){
      return numer;
    }
    //pre-condition: none
    //post-condition:  return the denominator
    int get_denom(){
      return denom;
    }
    //pre-condition: none
    //post-condition:  re-set numer to the parameter
    void set_numer(int n){
      numer = n;
    }
    //pre-condition: d!=0
    //post-condition:  re-set denom to the parameter
    //if it's !=0.
    void set_denom(int d){//should not be called with 0!!
      assert(d!=0);
      denom = d;
    }
    //pre-condition: d!=0
    //post-condition:  Initializes numer and denom
    //using the parameter values.
   Rational(int n, int d);
      //pre-condition: none
      //post-condition:  Initializes numer using the parameter value
      //and the denom to 1, so it represents the whole number n
   Rational(int n);
    //pre-condition: none
    //post-condition:  Initializes numer to 0
    //and the denom to 1, representing the whole number 0
    Rational();

    void operator *=(Rational b);

    void operator +=(Rational b);
    //pre: none
    //post:  Returns a Rational that is the sum
    //of the Rational the function is called on
    //and the parameter
    Rational operator +(Rational b);

    void reduce();
};
//pre: none
//post:  Returns a Rational that is the product
//of the two parameter Rationals
//Rational mult(Rational b){

Rational operator *(Rational a, Rational b);
bool operator ==(Rational lhs, Rational rhs);

#endif
