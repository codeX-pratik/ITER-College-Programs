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



/*

#include <iostream>
using namespace std;

// Function to read a matrix from the user
void readMatrix(int matrix[][100], int m, int n) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][100], int m, int n) {
    cout << "The entered matrix is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    int matrix[100][100]; // Assuming a maximum size of 100x100
    
    readMatrix(matrix, m, n);
    displayMatrix(matrix, m, n);

    return 0;
}


*/