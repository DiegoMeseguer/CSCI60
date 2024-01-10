#include <iostream>
#include <cassert>
#include "ATM.h"
#include "bankaccount.h"

ATM::ATM(){
	twenties_ = 0;
	tens_ = 0;
}

ATM::ATM(int amountTens, int amountTwenties){
	twenties_ = amountTwenties;
	tens_ = amountTens;

	if(amountTens < 0){
		cout<<"Input cannot be negative, setting value to"
			<<" zero instead.\n";
		tens_ = 0;
	}

	if(amountTwenties < 0){
		cout<<"Input cannot be negative, setting value to"
			<<" zero instead.\n";
		twenties_ = 0;
	}
}


BankAccount ATM::get_cash(int amount, BankAccount b){
	assert(amount >= 0);
	assert(twenties_*20 + tens_*10 >= amount);

	int number_twenties, number_tens, remainder;

	if(twenties_ > 0){
		number_twenties = amount / 20;
		remainder = amount - (number_twenties * 20);
 		number_tens = remainder / 10;
 		remainder = remainder - (number_tens * 10);
 	}
 	else{
 		number_twenties = 0;
 		number_tens = amount / 10;
 		remainder = amount - (number_tens * 10);
 	}

	twenties_ -= number_twenties;
	tens_ -= number_tens;

	cout<<"You will receive:\n"
		<<number_twenties<<" twenty-dollar bills\n"
		<<number_tens<<" ten-dollar bills\n"
		<<"and "<<remainder<<" dollars\n";

	b.withdraw(amount);

	return b;
}

// BankAccount ATM::get_cash(int amount, BankAccount b){
// 	assert(amount >= 0);

// 	int number_twenties, number_tens, remainder;

// 	number_twenties = amount / 20;
// 	if(amount == number_twenties * 20){
// 		number_tens = 0;
// 		remainder = 0;
// 	}
// 	else {
// 		remainder = amount - (number_twenties * 20);
// 		number_tens = remainder / 10;
// 		remainder = remainder - (number_tens * 10);
// 	}

// 	assert(twenties_ >= number_twenties);
// 	assert(tens_ >= number_tens);
// 	twenties_ -= number_twenties;
// 	tens_ -= number_tens;

// 	cout<<"You will receive:\n"
// 		<<number_twenties<<" twenty-dollar bills\n"
// 		<<number_tens<<" ten-dollar bills\n"
// 		<<"and "<<remainder<<" dollars\n";

// 	b.withdraw(amount);

// 	return b;
// }

void ATM::operator +=(ATM& rhs){
	twenties_ += rhs.twenties_;
	rhs.twenties_ = 0;

	tens_ += rhs.tens_;
	rhs.tens_ = 0;
}

void ATM::restock(int new20s, int new10s){
	assert(new20s >= 0);
	assert(new10s >= 0);
	twenties_ += new20s;
	tens_ += new10s;
}

bool operator ==(ATM lhs, ATM rhs){
	if(lhs.get_twenties() == rhs.get_twenties() && lhs.get_tens() == rhs.get_tens())
		return true;
	else
		return false;
}

ostream& operator <<(ostream& out, ATM a) {

	out<<"The number of twenty-dollar bills in the ATM is "
		<<a.get_twenties()<<endl;

	out<<"The number of ten-dollar bills in the ATM is "
		<<a.get_tens()<<endl;

	return out;
}
