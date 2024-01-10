#include "dbiguint.h"
using namespace std;

int main() {
	
	dbiguint zero("234"), abba("999");

	cout<<abba<<endl;
	cout<<zero<<endl;
	abba += zero;
	cout<<abba<<endl;
	cout<<abba[1]<<endl;
	cout<<zero<<endl;

	abba.reserve(6);

	cout<<abba<<endl;
	cout<<abba.size()<<endl;

	cout<<"=== Test of booleans and plus operator ==="<<endl;
	dbiguint subzero("234"), kirbo("5060"), test;

	cout<<(subzero == zero)<<endl;
	cout<<(kirbo > abba)<<endl;
	cout<<(kirbo < abba)<<endl;
	cout<<(subzero <= kirbo)<<endl;
	cout<<(test >= kirbo)<<endl;
	cout<<(abba > subzero)<<endl;
	cout<<(abba == test)<<endl;
	cout<<(kirbo != zero)<<endl;

	cout<<subzero + kirbo<<endl;

	cout<<"=== Test of = and >> operator ==="<<endl;
	dbiguint copia, fiio;

	copia = kirbo;
	zero = subzero;
	abba = fiio;

	cout<<copia<<endl;
	cout<<zero<<endl;
	cout<<abba<<endl;

	cout<<"Enter a number: ";
	cin>>fiio;
	cout<<"Enter second number: ";
	cin>>abba;

	cout<<fiio<<endl;
	cout<<abba<<endl;

	cout<<"=== Test of -=  and - operator ==="<<endl;
	dbiguint minuendo("1000"), sustraendo("999"), grande("85710"), peque("9389"); 
	dbiguint big("00790"), small("000023"), resta;

	minuendo -= sustraendo;
	cout<<minuendo<<endl;
	cout<<sustraendo<<endl;

	grande -= peque;
	cout<<grande<<endl;
	cout<<peque<<endl;

	big -= small;
	cout<<big<<endl;
	cout<<small<<endl;

	resta = peque - small;
	cout<<"resta is "<<resta<<endl;

	cout<<"=== Test of *= and * operator ==="<<endl;

	dbiguint arbol("12345678901234"), arbol2("98765");
	dbiguint a("12"), b("12"), c("00123"), d("5394"), product;


	arbol *= arbol2;
	cout<<"++++++++++++"<<endl;
	cout<<"The n is: "<<arbol2<<endl;
	cout<<"The product is: "<<arbol<<endl;

	a *= b;
	c *= d;

	cout<<a<<endl;
	cout<<c<<endl;

	product = b * d;
	cout<<"product is "<<product<<endl;

	return 0;
}
