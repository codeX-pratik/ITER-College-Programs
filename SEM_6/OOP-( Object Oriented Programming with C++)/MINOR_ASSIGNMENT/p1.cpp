#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    vector<float> elements;

public:
    // (a) Create a vector
    void createVector(vector<float> vals) {
        elements = vals;
    }

    // (b) Modify value of given element
    void modifyElement(int index, float value) {
        if(index >= 0 && index < elements.size()) {
            elements[index] = value;
        }
    }

    // (c) Multiply by scalar value
    void multiplyByScalar(float scalar) {
        for(float &elem : elements) {
            elem *= scalar;
        }
    }

    // (d) Display vector
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
};

int main() {
    Vector v;
    v.createVector({10, 20, 30});
    cout << "Original vector: ";
    v.display();

    v.modifyElement(1, 25);
    cout << "After modification: ";
    v.display();

    v.multiplyByScalar(2);
    cout << "After scalar multiplication: ";
    v.display();

    return 0;
}

/*

Original vector: (10, 20, 30)
After modification: (10, 25, 30)
After scalar multiplication: (20, 50, 60)

*/