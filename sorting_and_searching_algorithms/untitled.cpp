#include <iostream>
#include <cctype>
using namespace std;

int main() {
	
	bool a, b;

	a = isspace('\n');
	b = iscntrl('\n');

	cout<<a<<endl;
	cout<<b<<endl;
	
	return 0;
}

