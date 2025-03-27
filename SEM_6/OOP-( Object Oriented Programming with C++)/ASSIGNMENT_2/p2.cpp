#include <iostream>
#include "BankAccount.cpp"

const int totalCostomer = 10;

int accNumber(int accNum, BankAccount customer[]) {
    for(int i=0; i<totalCostomer; i++) {
        if(customer[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

int main() {
    BankAccount customer[totalCostomer];
    for(int i=0; i<totalCostomer; i++) {
        string name, accountType;
        double balance;
        int accountNumber;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account type: ";
        cin >> accountType;
        cout << "Enter balance: ";
        cin >> balance;
        customer[i].assign_values(name, accountNumber, accountType, balance);
    }

    int choice, custIndex;
    double amount;
    while(true) {
        cout << "1. Deposit\n2. Withdraw\n3. Display\n4. Exit\n" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 4) { break;}
        cout << "Enter account number: ";
        int accNum;
        cin >> accNum;
        custIndex = accNumber(accNum, customer);
        if(custIndex != -1) {
            switch(choice) {
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    customer[custIndex].deposit(amount);
                    break;
                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    customer[custIndex].withdraw(amount);
                    break;
                case 3:
                    customer[custIndex].display();
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        } else {
            cout << "Account not found" << endl;
        }
    }
    return 0;
}