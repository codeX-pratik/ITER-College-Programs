#include <iostream>
using namespace std;

class Number {
private:
    int num;

public:
    // Set number
    void setNumber(int n) {
        num = n;
    }

    // Get number
    int getNumber() {
        return num;
    }

    // Print number
    void printNumber() {
        cout << "Number: " << num << endl;
    }

    // Check if negative
    bool isNegative() {
        return num < 0;
    }

    // Check if divisible by n
    bool isDivisibleBy(int n) {
        return num % n == 0;
    }

    // Get absolute value
    int absoluteValue() {
        return num < 0 ? -num : num;
    }
};

int main() {
    Number n;
    n.setNumber(-15);
    n.printNumber();

    cout << "Is negative? " << (n.isNegative() ? "Yes" : "No") << endl;
    cout << "Is divisible by 3? " << (n.isDivisibleBy(3) ? "Yes" : "No") << endl;
    cout << "Absolute value: " << n.absoluteValue() << endl;

    return 0;
}

/*

Number: -15
Is negative? Yes
Is divisible by 3? Yes
Absolute value: 15

*/