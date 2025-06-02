#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int code;
public:
    Person(string n, int c) : name(n), code(c) {}
    void display() {
        cout << "Name: " << name << ", Code: " << code << endl;
    }
};

class Account : virtual public Person {
protected:
    double pay;
public:
    Account(string n, int c, double p) : Person(n, c), pay(p) {}
    void display() {
        Person::display();
        cout << "Pay: " << pay << endl;
    }
};

class Admin : virtual public Person {
protected:
    int experience;
public:
    Admin(string n, int c, int exp) : Person(n, c), experience(exp) {}
    void display() {
        Person::display();
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Master : public Account, public Admin {
public:
    Master(string n, int c, double p, int exp) 
        : Person(n, c), Account(n, c, p), Admin(n, c, exp) {}
    
    void display() {
        Person::display();
        cout << "Pay: " << pay << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

int main() {
    Master m("Alice Johnson", 101, 50000, 5);
    m.display();
    return 0;
}

/*

Name: Alice Johnson, Code: 101
Pay: 50000
Experience: 5 years

*/