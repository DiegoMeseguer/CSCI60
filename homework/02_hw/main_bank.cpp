#include <iostream>
#include "bankaccount.h"
using namespace std;

int main()
{
    BankAccount bill;
    BankAccount bob(1991821, 100, 928040892, "Bob Smith");
   // bob.print_client();
    bill=bob;
    //bill.print_client();
    cout<<bill<<bob;//Why we return out!!!!

    cout<<(bill==bob)<<endl;

    //cout<<(bill!=bob)<<endl; separate operator

    bill.withdraw(50);
    //bob.print_client();
    //bill.print_client();

    cout<<(bill==bob)<<endl;
    cout<<(bill<bob)<<endl;

    bill.withdraw(50);
    // bob.print_client();
    // bill.print_client();
    cout<<(bill==bob);

    return 0;
}
