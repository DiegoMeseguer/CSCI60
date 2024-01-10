#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;

int main() {

	Rational r1, r2;

	cout<<(r1 == r2)<<endl;

	r1.set_numer(5);
	r1.set_denom(3);

	cout<<(r1 == r2)<<endl;

	r2.set_numer(25);
	r2.set_denom(15);

	cout<<(r1 == r2)<<endl;

	Rational r3, r4(80, 100);
	r3 = Rational(12, 36);

	r3.reduce();
	r4.reduce();

	cout<<r3.get_numer()<<"/"<<r3.get_denom()<<endl;
	cout<<r4.get_numer()<<"/"<<r4.get_denom()<<endl;

	Rational r5(12, 36), r6(3, 3);
	r5 *= r6;
	cout<<r5.get_numer()<<"/"<<r5.get_denom()<<endl;

	Rational r7(5, 4), r8(3, 3), ans;
	ans = r7 * r8;
	cout<<ans.get_numer()<<"/"<<ans.get_denom()<<endl;

    return 0;
}