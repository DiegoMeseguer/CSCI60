#include <iostream>
#include "ATM.h"
#include "bankaccount.h"

using namespace std;

int main(){

	ATM cajero1, cajero2(8, 10);
	BankAccount savings(123, 5000, 92040, "Miguel Perez");

	cout<<"# of ten-bills is: "<<cajero1.get_tens()<<endl;
	cout<<"# of twenty-bills is: "<<cajero1.get_twenties()<<endl;

	cout<<"# of ten-bills is: "<<cajero2.get_tens()<<endl;
	cout<<"# of twenty-bills is: "<<cajero2.get_twenties()<<endl;

	cout<<savings<<endl;

	cout<<cajero2.get_cash(50, savings)<<endl;

	cout<<"# of ten-bills is: "<<cajero2.get_tens()<<endl;
	cout<<"# of twenty-bills is: "<<cajero2.get_twenties()<<endl;

	ATM cajero3(500, 500);

	cajero2 += cajero3;

	cout<<"# of ten-bills is: "<<cajero2.get_tens()<<endl;
	cout<<"# of twenty-bills is: "<<cajero2.get_twenties()<<endl;

	cout<<"# of ten-bills is: "<<cajero3.get_tens()<<endl;
	cout<<"# of twenty-bills is: "<<cajero3.get_twenties()<<endl;

	cajero1.restock(508, 507);
	cout<<cajero1<<endl;

	cout<<(cajero1 == cajero2)<<endl;
	cout<<(cajero1 == cajero3)<<endl;

	ATM cajero13(60, 0);
	cout<<cajero13.get_cash(68, savings)<<endl;


	return 0;
}
