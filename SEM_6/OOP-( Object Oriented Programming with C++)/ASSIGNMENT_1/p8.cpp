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

/*

Enter the base : 4
Do you want to enter exponent (y / n) ? n
4 square is 16


Enter the base : 4
Do you want to enter exponent (y / n) ? y
Enter the exponent : 4
4 raised to the power 4 is 256

*/