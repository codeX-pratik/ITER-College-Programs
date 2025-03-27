#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    int acc_no;
    string acc_type;
    float balance;

    public:
        void assign_values(string n, int a, string t, float b = 0) {
            name = n;
            acc_no = a;
            acc_type = t;
            balance = b;
        }

        int getAccountNumber() {
            return acc_no;
        }

        void deposit(float amount) {
            balance += amount;
        }

        void withdraw(float amount) {
            if (balance >= amount) {
                balance -= amount;
            } else {
                cout << "Insufficient balance" << endl;
            }
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }
};