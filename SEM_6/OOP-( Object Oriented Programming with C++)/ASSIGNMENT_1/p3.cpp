#include <iostream>
using namespace std;

int* createVector(int M) {
    int* vec = new int[M];
    for(int i=0; i<M; i++) {
        vec[i] = i + 1;
    }

    return vec;
}

int main() {
    int M;
    cout << "Enter the size of the vector : ";
    cin >> M;

    int* vector = createVector(M);

    cout << "Vector element : ";
    for (int i=0; i<M; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
    delete[] vector;
    return 0;
}

/*
Enter the size of the vector : 5
Vector element : 1 2 3 4 5

Enter the size of the vector : 10
Vector element : 1 2 3 4 5 6 7 8 9 10 
*/