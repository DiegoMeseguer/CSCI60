#include "dynamicbag.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
void add(int& n){
  n++;
}

int main(){
dynamicBag<int> b;
b.insert(5);
b.insert(70);
for(int i=0; i<5; i++)
    b.insert(i+1);
for(int i=0; i<b.size(); i++)
    cout<<b[i]<<" ";
cout<<endl<<endl;
b.erase(5);
for(int i=0; i<b.size(); i++)
    cout<<b[i]<<" ";
cout<<endl<<endl;

for(auto e:b)
  cout<<e<<" ";
cout<<endl<<endl;

dynamicBag<int>::iterator f = find(b.begin(), b.end(), 100);
if(f!=b.end())
  cout<<"in!"<<endl;
else
  cout<<"not in"<<endl;

cout<<"Max: "<<(*max_element(b.begin(), b.end()))<<endl;

for_each(b.begin(), b.end(), add);
cout<<"After add: ";
for(auto e:b)
  cout<<e<<" ";
cout<<endl<<endl;

sort(b.begin(), b.end());
cout<<"After sort: ";
for(auto e:b){
  cout<<e<<" ";
}

}
