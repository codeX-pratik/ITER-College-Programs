#include <iostream>
#include <cmath>
using namespace std;

double power(double m, int n = 2) {
    return pow(m, n);
}

int power(int m, int n = 2) {
    return pow(m, n);
}

int main() {
    double m;
    int m2, n;
    char c;

    cout << "Enter the base (m) : ";
    cin >> m;
    
    cout << "Do you want to enter exponent (y / n) ? ";
    cin >> c;
    if (c == 'y' || c == 'Y') {
        cout << "Enter the exponent : ";
        cin >> n;
        cout << m << " raised to the power " << n << " is " << power(m, n) << endl;
    } else {
        cout << m << " square is " << power(m) << endl;
    }

    cout << endl << endl;

    cout << "Enter the base (m2) : ";
    cin >> m2;
    
    cout << "Do you want to enter exponent (y / n) ? ";
    cin >> c;
    if (c == 'y' || c == 'Y') {
        cout << "Enter the exponent : ";
        cin >> n;
        cout << m2 << " raised to the power " << n << " is " << power(m2, n) << endl;
    } else {
        cout << m2 << " square is " << power(m2) << endl;
    }

    return 0;
}

/*
Enter the base (m) : 2.2
Do you want to enter exponent (y / n) ? y
Enter the exponent : 3
2.2 raised to the power 3 is 10.648


Enter the base (m2) : 3
Do you want to enter exponent (y / n) ? y
Enter the exponent : 2
3 raised to the power 2 is 9
*/