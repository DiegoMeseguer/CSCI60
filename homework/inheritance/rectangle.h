#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rect
{
public:

    // pre: none
    // post: creates a rectangle with zero height & width
    Rect();

    // pre: h >= 0.0 && w >= 0.0
    // post: a rectangle has been created with given height, width
    Rect(double h, double w);

    // pre: none
    // post: returns the area of this Rect
    double area() const;

    // pre: none
    // post: returns the perimeter of this Rect
    double perimeter() const;

    double h() const;
    double w() const;

protected://Protected is like private EXCEPT the child
//class can directly access protected items
    double h_, w_;

    // invariants:
    //    1) h_ is the length of this Rect
    //    2) w_ is the width of this Rect

};

// pre: none
// post: outputs Rects in the form [(center.x, center.y), h, w]
std::ostream & operator << (std::ostream & os, const Rect & r);



#endif // RECTh_
