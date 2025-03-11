#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    cout << "Enter value of a : ";
    cin >> a; 
    cout << "Enter value of b : ";
    cin >> b;
    swap(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

/*
Enter value of a : 5
Enter value of b : 4
a = 4
b = 5
*/