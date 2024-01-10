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

  cout<<r<<endl;

  return 0;
}
