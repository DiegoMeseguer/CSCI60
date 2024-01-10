// Make the file #include-able
#ifndef ATM_H	// if not defined, matching endif at the end
#define ATM_H	// then define

#include <iostream>
#include <cassert>
#include "bankaccount.h"

using namespace std;

class ATM{
private:
	int twenties_;
	int tens_;
public:
	//Postcondition: initializes the number of bills
	// of any denomination to 0
	ATM();

	//Precondition: Positive or zero values are provided
	//Postcondition: The number of bills that the ATM has
	//available is initizaled to the provided values
	ATM(int amountTens, int amountTwenties);

	//Postcondition: returns the amount of twenty-dollar bills
	int get_twenties(){
		return twenties_;
	}

	//Postcondition: returns the amount of ten-dollar bills
	int get_tens(){
		return tens_;
	}

	//Precondition: amount is >= 0 and the ATM has enough bills of
	//the appropiate kind
	//Postcondition: The number of bills in the ATM is updated,
	//the bank account balance is updated and the bank account is returned
	BankAccount get_cash(int amount, BankAccount b);

	//Postcondition: The ATM the function was called on receives all
	//the funds of the argument ATM. The argument ATM now has zero bills
	void operator +=(ATM& rhs);

	//Precondition: Both new20s and new10s are >= 0
	//Postcondition: Adds new20s amount of bills and new10s amount of bills
	//to the ATM
	void restock(int new20s, int new10s);

};

//Postcondition: returns true if the ATMs contain the same number of
//10s and 20s bills, and false otherwise
 bool operator ==(ATM lhs, ATM rhs);

//Postcondition: Prints out the information of the ATM: # of 10s and 20s bills
 ostream& operator <<(ostream& out, ATM a);

#endif
 