#include <iostream>
#include "BankAccount.cpp"

int main() {
    BankAccount acc;
    acc.assign_values("John Hamalton", 123456, "Savings", 1000);
    acc.deposit(500);
    acc.withdraw(200);
    acc.display();
    return 0;
}

/*
Name: John Hamalton
Balance: 1300
*/