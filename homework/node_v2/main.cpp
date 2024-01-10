#include <iostream>
#include "node.h"
using namespace std;

int main(){
node<int>* head = nullptr, * tail=nullptr, *nh, *nt;

list_head_insert(head, tail, 3);
list_head_insert(head, tail, 2);
list_tail_insert(head, tail, 1);
cout<<head;
cout<<endl;
list_copy(head, tail, nh, nt);
cout<<nh;
cout<<endl;
list_insert(head, 4);
cout<<head;
cout<<endl;
list_head_remove(head, tail);
cout<<head;
cout<<endl;
list_remove(head, tail);
cout<<head;



  return 0;
}
