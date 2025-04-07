#include<iostream>
#define MAX_NUMBER(a , b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
using namespace std;

int main() {
    int x,y,z;
    cout << "Enter the value of x, y and z : ";
    cin >> x >> y >> z;
    cout << "The largest number is " << MAX_NUMBER(x,y,z) << endl;

    return 0;
}

/*

Enter the value of x, y and z : 10 5 1
The largest number is 10

*/