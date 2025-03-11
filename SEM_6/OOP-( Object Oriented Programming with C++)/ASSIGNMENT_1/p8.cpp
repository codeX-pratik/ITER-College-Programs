#include <iostream>
#include <cmath>
using namespace std;

double power(double m, int n = 2) {
    return pow(m, n);
}

int main() {
    double m;
    int n;
    char c;

    cout << "Enter the base : ";
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

    return 0;
}