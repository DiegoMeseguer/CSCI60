#include "biguint.h"
using namespace std;

int main() {
	
	biguint test, test2("1994");

	cout<<"Test biguint:"<<endl;
	for(int i = 0; i < biguint::CAPACITY; i++)
		cout<<i<<": "<<test[i]<<endl;
	cout<<endl;

	cout<<"Test2 biguint:"<<endl;
	for(int i = 0; i < biguint::CAPACITY; i++)
		cout<<i<<": "<<test2[i]<<endl;
	cout<<endl;

	cout<<test2[2]<<endl;
	cout<<biguint::CAPACITY<<endl;

	biguint numero("20800");

	cout<<numero<<endl;

	biguint num1("22") , num2("99"), suma;

	cout<<"num1 is: "<<num1<<endl;
	cout<<"num2 is: "<<num2<<endl;

	num1 += num2;

	cout<<"num1 is: "<<num1<<endl;
	cout<<"num2 is: "<<num2<<endl;

	biguint num3("194"), num4("932");

	suma = num3 + num4;

	cout<<"suma is: "<<suma<<endl;

	biguint aCompare("85525768571141600906"), bCompare("85525768571141600916");

	cout<<aCompare.compare(bCompare)<<endl;

	biguint minuendo("2321"), sustraendo("572"), resta;

	cout<<"minuendo is: "<<minuendo<<endl;
	cout<<"sustraendo is: "<<sustraendo<<endl;

	minuendo -= sustraendo;

	cout<<"minuendo is: "<<minuendo<<endl;
	cout<<"sustraendo is: "<<sustraendo<<endl;

	minuendo = biguint("2540");
	sustraendo = biguint("1700");

	resta = minuendo - sustraendo;

	cout<<"resta is: "<<resta<<endl;

	biguint cadena("8123");

	string copy;
	copy = cadena.toString();

	cout<<"copy is: "<<copy<<endl;

	biguint backToCopy(copy);

	cout<<backToCopy<<endl;


	return 0;
}
