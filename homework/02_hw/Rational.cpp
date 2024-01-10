#include <iostream>
#include <cassert>
#include "Rational.h"

Rational::Rational(){
	numer = 0;
	denom = 1;
}

Rational::Rational(int n){
	numer = n;
	denom = 1;
}

Rational::Rational(int n, int d){
	assert(d!=0);
	numer = n;
	denom = d;
}

void Rational::operator *=(Rational b){
	numer = (numer*b.numer);
	denom = (denom*b.denom);

	reduce();
}

void Rational::operator +=(Rational b){
	numer = b.numer*denom+numer*b.denom;
	denom = b.denom*denom;

	reduce();
}

Rational Rational::operator +(Rational b){
	Rational ans;
	ans.numer = b.numer*denom+numer*b.denom;
	ans.denom = b.denom*denom;

	ans.reduce();

	return ans;
}

void Rational::reduce() {

	int residue(-1), gcd;
	int starting_numer, starting_denom;

	starting_numer = numer;
	starting_denom = denom;

	if(numer == 0)
		return;

	if(numer == denom){
		numer = 1;
		denom = 1;
	}
	else if(numer > denom){
		while(residue != 0){
			residue = numer % denom;
			numer = denom;
			denom = residue;
		}
		gcd = numer;
		numer = starting_numer / gcd;
		denom = starting_denom / gcd;
	}
	else if(denom > numer){
		while(residue != 0){
			residue = denom % numer;
			denom = numer;
			numer = residue;
		}
		gcd = denom;
		numer = starting_numer / gcd;
		denom = starting_denom / gcd;
	}
}

// void Rational::reduce() {

// 	int greatest_common_divisor = gcd(numer, denom);

// 	if(numer != 0) {
// 		numer = numer / greatest_common_divisor;
// 		denom = denom / greatest_common_divisor;
// 	}
// }

Rational operator *(Rational a, Rational b){
	Rational ans(a.get_numer()*b.get_numer(),
				a.get_denom()*b.get_denom());

	ans.reduce();
	
	return ans;
}

bool operator ==(Rational lhs, Rational rhs) {

	if(lhs.get_numer() == 0 || rhs.get_numer() == 0) {
		if(lhs.get_numer() == 0 && rhs.get_numer() == 0)
			return(true);
		else
			return(false);
	}

	if(lhs.get_numer() >= rhs.get_numer()) {
		return((lhs.get_numer() % rhs.get_numer() == 0)
				&& (lhs.get_denom() % rhs.get_denom() == 0));
	}
	else {
		return((rhs.get_numer() % lhs.get_numer() == 0)
				&& (rhs.get_denom() % lhs.get_denom() == 0));
	}
}




