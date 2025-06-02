#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;
public:
    Account(string name, int accNum, string type, double bal) 
        : customerName(name), accountNumber(accNum), accountType(type), balance(bal) {}
    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    
    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
    
    virtual void computeInterest() {}
    virtual void withdraw(double amount) {}
    virtual void checkMinimumBalance() {}
};

class SavAcct : public Account {
    double interestRate;
public:
    SavAcct(string name, int accNum, double bal, double rate) 
        : Account(name, accNum, "Savings", bal), interestRate(rate) {}
    
    void computeInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }
    
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

class CurAcct : public Account {
    double minBalance;
    double serviceCharge;
public:
    CurAcct(string name, int accNum, double bal, double minBal, double charge) 
        : Account(name, accNum, "Current", bal), minBalance(minBal), serviceCharge(charge) {}
    
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            checkMinimumBalance();
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    
    void checkMinimumBalance() override {
        if (balance < minBalance) {
            balance -= serviceCharge;
            cout << "Service charge imposed: " << serviceCharge << endl;
        }
    }
};

int main() {
    SavAcct sav("John Doe", 1001, 5000, 5);
    CurAcct cur("Jane Smith", 2001, 10000, 2000, 50);
    
    sav.deposit(2000);
    sav.computeInterest();
    sav.displayBalance();
    sav.withdraw(1000);
    sav.displayBalance();
    
    cout << "\n";
    
    cur.deposit(5000);
    cur.displayBalance();
    cur.withdraw(12000);
    cur.displayBalance();
    cur.withdraw(5000);
    cur.displayBalance();
    
    return 0;
}

/*

Deposited: 2000
Interest added: 350
Balance: 7350
Withdrawn: 1000
Balance: 6350

Deposited: 5000
Balance: 15000
Withdrawn: 12000
Balance: 3000
Insufficient balance!
Balance: 3000

*/