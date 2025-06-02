#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    vector<float> elements;

public:
    void createVector(vector<float> vals) {
        elements = vals;
    }

    void modifyElement(int index, float value) {
        if(index >= 0 && index < elements.size()) {
            elements[index] = value;
        }
    }

    void multiplyByScalar(float scalar) {
        for(float &elem : elements) {
            elem *= scalar;
        }
    }

    void display() {
        cout << "(";
        for(int i = 0; i < elements.size(); i++) {
            cout << elements[i];
            if(i != elements.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    // Add two vectors
    Vector addVectors(Vector v2) {
        Vector result;
        vector<float> temp;
        
        for(int i = 0; i < elements.size(); i++) {
            temp.push_back(elements[i] + v2.elements[i]);
        }
        
        result.createVector(temp);
        return result;
    }
};

int main() {
    Vector v1, v2;
    v1.createVector({1, 2, 3});
    v2.createVector({4, 5, 6});

    cout << "Vector 1: ";
    v1.display();
    cout << "Vector 2: ";
    v2.display();

    Vector v3 = v1.addVectors(v2);
    cout << "Sum of vectors: ";
    v3.display();

    return 0;
}

/*

Vector 1: (1, 2, 3)
Vector 2: (4, 5, 6)
Sum of vectors: (5, 7, 9)

*/