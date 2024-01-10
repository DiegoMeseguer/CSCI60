#include <iostream>
#include "lbag.h"
using namespace std;

int main(int argc, char *argv[])
{
  LBag<int> b, d;
  b.insert(5);
  b.insert(2);
  b.insert(7);
  b.insert(1);
  cout<<b<<endl;
  d = b;
  cout<<b<<endl;
  cout<<d<<endl;
  d.insert(5);
  LBag<int> a(d);
  cout<<b<<endl;
  cout<<d<<endl;
  cout<<a<<endl;
  cout<<a.count(5)<<endl;
  cout<<a.size()<<endl;



    return 0;
}
