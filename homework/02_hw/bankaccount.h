#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <iostream>
#include <cassert>


class BankAccount{
private:
    int account_num;
    double balance;
    int ssn;
    std::string name;
public:
    double withdraw(double amount);
    //pre:  amount>=0
    //Post:  Deducts amount money from the account, and returns how much money is left in the account.
    //$30 overdraft fee is applied if necessary.
    double deposit(double amount);
    //precondition:  amount >=0
    //postcondition:  Adds amount money to the account, returns the new balance.
    BankAccount(int ba, double bal, int s, std::string n);
    //Pre:  ba>0, bal>=0, s>0, n!=""
    //Post:  Sets balance = bal, account_num=ba, ssn=s, name=n
    BankAccount();
    //Pre:  none
    //Post:  Set balance to 0, ssn and account_num to -1, name to ""
    double get_balance(){return balance;}
    //Pre:  none
    //Post:  Returns the balance
    int get_account_num(){return account_num;}
    //Pre:  none
    //Post:  Returns the account_num
    int get_ssn(){return ssn;}
    //Pre:  none
    //Post:  Returns the ssn
    std::string get_name(){return name;}
    //Pre:  none
    //Post:  Returns the name
    void print_client();
    //pre:  none
    //post:  prints out the name, balance, and account_num


};

bool operator ==(BankAccount lhs, BankAccount rhs);
bool operator <(BankAccount lhs, BankAccount rhs);
bool operator >(BankAccount lhs, BankAccount rhs);
std::ostream& operator <<(std::ostream& out, BankAccount b);


#endif // BANKACCOUNT_H
