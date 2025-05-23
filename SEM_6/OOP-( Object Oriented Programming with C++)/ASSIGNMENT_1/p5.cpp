#include <iostream>
using namespace std;

void readMatric(int* M, int r, int c) {
    cout << "Enter the element of the matrix : " << endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c ; j++) {
            cin >> *(M + i * c + j);
        }
    }
}

void displayMatric(int* M, int r, int c) {
    cout << "Displaying the matrix : " << endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << *(M + i * c + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int r, c;
    cout << "Enter the number of rows : ";
    cin >> r;
    cout << "Enter the number of column : ";
    cin >> c;
    
    int matrix[r][c];
    readMatric(&matrix[0][0], r, c);
    displayMatric(&matrix[0][0], r, c);

    return 0;
}

/*
Enter the number of rows : 2
Enter the number of column : 2
Enter the element of the matrix : 
1 2
3 4
Displaying the matrix : 
1 2
3 4
*/