#include <iostream>
#include "square.h"
#include "rectangle.h"
// WANT: a class to represent SQUARES
//       derive class SQUARE from existing class RECT
//
//       RECT is called the BASE class
//       SQUARE is called the DERIVED class

using namespace std;

int main(int argc, char *argv[])
{
    Square s(3, "somename");
    Square s2;
    cout<<s2.side()<<endl;
    cout<<s2.Rect::area()<<endl;

    cout << s.area() << endl;
    cout << s.perimeter() << endl;
    cout<<s.name()<<endl;
    cout<<s.h()<<endl;
    cout<<s.side()<<endl;
    cout<<s<<endl;

    return 0;
}
