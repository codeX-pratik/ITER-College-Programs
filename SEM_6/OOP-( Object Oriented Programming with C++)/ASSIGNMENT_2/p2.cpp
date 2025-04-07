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
        cout << "Enter details for customer " << i+1 << endl;
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
        if(choice == 4) { 
            cout << "Exiting..." << endl;
            break;
        }
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

/*

Enter details for customer 1
Enter name: person_1
Enter account number: 101
Enter account type: savings
Enter balance: 10000
Enter details for customer 2
Enter name: person_2
Enter account number: 102
Enter account type: savings
Enter balance: 20000
Enter details for customer 3
Enter name: person_3
Enter account number: 103
Enter account type: savings
Enter balance: 30000
Enter details for customer 4
Enter name: person_4
Enter account number: 104
Enter account type: savings
Enter balance: 40000
Enter details for customer 5
Enter name: person_5
Enter account number: 105
Enter account type: savings
Enter balance: 50000
Enter details for customer 6
Enter name: person_6
Enter account number: 106
Enter account type: savings
Enter balance: 60000
Enter details for customer 7
Enter name: person_7
Enter account number: 107
Enter account type: savings
Enter balance: 70000
Enter details for customer 8
Enter name: person_8
Enter account number: 108
Enter account type: savings
Enter balance: 80000
Enter details for customer 9
Enter name: person_9
Enter account number: 109
Enter account type: savings
Enter balance: 90000
Enter details for customer 10
Enter name: person_10
Enter account number: 110
Enter account type: savings
Enter balance: 100000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter choice: 3
Enter account number: 105
Name: person_5
Balance: 50000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter choice: 1
Enter account number: 102
Enter amount to deposit: 10000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter choice: 3
Enter account number: 102
Name: person_2
Balance: 30000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter choice: 2
Enter account number: 102
Enter amount to withdraw: 20000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter account number: 102
Name: person_2
Balance: 10000
1. Deposit
2. Withdraw
3. Display
4. Exit

Enter choice: 4
Exiting...

*/