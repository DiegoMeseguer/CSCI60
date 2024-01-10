#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
#include <string>
//A Square has all the stuff a Rect has, plus maybe more
//If we do class Square: private Rect
//public members of Rect will be private members of Square

class Square: public Rect//This is how we inherit from Rect
{
public:
    // pre: none
    // post: creates a new Square with side 0, and name ""
    Square();

    // pre: side >= 0.0
    // post: creates a new Square with given side and name
    Square(double side, const std::string & name);

    //pre:  none
    //post:  returns the name
    std::string name() const;

    //pre: none
    //post:  returns the side length of the square
    double side()const;

    // pre: none
    // post: returns the area of this Rect and prints its name
    double area() const;//We can replace the base class' functions with our own implementations
    //Note that in order to replace the base class' function, our function must have the same parameters.

private:

    std::string name_;
    double h(){side();}//Hides the h() method from Rectangle
    double w(){side();}

};

// pre: none
// post: outputs given Square in format [side, name]
//std::ostream & operator << (std::ostream &, const Square &);

#endif // SQUARE_H
