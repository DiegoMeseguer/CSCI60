#include "bankaccount.h"


BankAccount::BankAccount(){
    account_num=-1;
    ssn=-1;
    balance=0;
    name="";
}

BankAccount::BankAccount(int ba, double bal, int s, std::string n){
    assert(n!="" && ba>0 && s>0 && bal >=0);
    account_num=ba;
    ssn=s;
    balance=bal;
    name=n;
}

double BankAccount::withdraw(double amount){
    assert(amount >= 0);
    if(balance<amount){
        double overdraft_fee = 30;
        balance=balance-overdraft_fee;
    }

    balance=balance-amount;
    return balance;
}
double BankAccount::deposit(double amount){
    assert(amount >= 0);
    balance+=amount;
    return balance;
}




bool operator ==(BankAccount lhs, BankAccount rhs){
    return (lhs.get_account_num()==rhs.get_account_num() &&lhs.get_balance()==rhs.get_balance() &&
            lhs.get_name()==rhs.get_name()&&lhs.get_ssn()==rhs.get_ssn());
}

bool operator <(BankAccount lhs, BankAccount rhs){
 //return lhs.get_balance()<rhs.get_balance();
 if(lhs.get_balance()<rhs.get_balance())
     return true;
 else
     return false;
}

bool operator >(BankAccount lhs, BankAccount rhs){
 //return lhs.get_balance()>rhs.get_balance();
 if(lhs.get_balance()>rhs.get_balance())
     return true;
 else
     return false;
}


std::ostream& operator <<(std::ostream& out, BankAccount b){//can't be a member
    out<<"Name: "<<b.get_name()<<std::endl;
    out<<"Account number: "<<b.get_account_num()<<std::endl;
    out<<"Balance: "<<b.get_balance()<<std::endl;
    return out;
}
