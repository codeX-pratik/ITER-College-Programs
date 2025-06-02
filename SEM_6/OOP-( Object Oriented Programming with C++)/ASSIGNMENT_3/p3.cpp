#include <iostream>
using namespace std;

class Complex {
    double real;
    double imaginary;
public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}
    
    static Complex addcomplex(Complex a, Complex b) {
        return Complex(a.real + b.real, a.imaginary + b.imaginary);
    }
    
    // Display function
    void display() {
        cout << real << " + j " << imaginary << endl;
    }
};

int main() {
    double r1, i1, r2, i2;

    cout << "Enter real part of first complex number (A): ";
    cin >> r1;
    cout << "Enter imaginary part of first complex number (A): ";
    cin >> i1;

    cout << "Enter real part of second complex number (B): ";
    cin >> r2;
    cout << "Enter imaginary part of second complex number (B): ";
    cin >> i2;

    Complex A(r1, i1);
    Complex B(r2, i2);
    Complex C = Complex::addcomplex(A, B);
    
    cout << "\nA = "; A.display();
    cout << "B = "; B.display();
    cout << "C = A + B = "; C.display();
    
    return 0;
}

/*

A = 3.12 + j 5.65
B = 2.75 + j 1.21
C = A + B = 5.87 + j 6.86

*/