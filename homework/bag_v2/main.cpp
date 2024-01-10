#include "bag.h"
#include <iostream>
using namespace std;

int main(){
//Create an empty Bag, then insert 1, 2, 3
//Then loop over the Bag and print out its contents
//Also print out CAPACITY
  Bag r;
  for(int i=1; i<4; i++){
    r.insert(i);
  }
  for(int i=0; i<r.size(); i++){
    cout<<r[i]<<" ";
  }
  cout<<Bag::CAPACITY<<endl;

  cout<<r<<endl<<endl;

  int arr[6] = {1, 2, 3, 4, 5, 6};
  Bag r2, r3(arr, 6);
  r2.insert(11);
  r2.insert(2);
  r2.insert(2);
  r2.insert(9);
  r2.insert(2);
  r2.insert(7);
  r2.insert(2);

  cout<<r2<<endl;
  cout<<r3<<endl;

  cout<<"r2 has size: "<<r2.size()<<" and r3 has size: "<<r3.size()<<endl;

  cout<<(r3.erase_one(2))<<endl;
  cout<<(r2.erase(2))<<endl;

  cout<<r2<<endl;
  cout<<r3<<endl;

  cout<<"r2 has size: "<<r2.size()<<" and r3 has size: "<<r3.size()<<endl;

  Bag suma;

  suma = r + r2;
  r2 += r3;

  cout<<suma<<endl;
  cout<<r2<<endl;

  return 0;
}







