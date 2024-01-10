#include "rectangle.h"
#include <cassert>

Rect::Rect()
{
    h_ = w_ = 0.0;
}


Rect::Rect(double h, double w)
{
    assert(h >= 0.0 && w >= 0.0);
    h_ = h;
    w_ = w;
}

double Rect::area() const
{
    return  h_ * w_;
}

double Rect::perimeter() const
{
    return 2.0 * (h_ + w_);
}



double Rect::h() const
{
    return h_;
}


double Rect::w() const
{
    return w_;
}

std::ostream & operator << (std::ostream & os, const Rect & r)
{

    os << "[" <<  r.h() << ", " << r.w() << "]";
    return os;
}
