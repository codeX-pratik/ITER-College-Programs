#include <iostream>

class FLOAT {
private:
    float value;
public:
    FLOAT(float v = 0) : value(v) {}

    FLOAT operator+(const FLOAT& f) {
        return FLOAT(value + f.value);
    }

    FLOAT operator-(const FLOAT& f) {
        return FLOAT(value - f.value);
    }

    FLOAT operator*(const FLOAT& f) {
        return FLOAT(value * f.value);
    }

    FLOAT operator/(const FLOAT& f) {
        return FLOAT(value / f.value);
    }

    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    FLOAT f1(5.5), f2(2.2);
    FLOAT f3 = f1 + f2;
    FLOAT f4 = f1 - f2;
    FLOAT f5 = f1 * f2;
    FLOAT f6 = f1 / f2;

    f3.display();
    f4.display();
    f5.display();
    f6.display();

    return 0;
}

/*

Value: 7.7
Value: 3.3
Value: 12.1
Value: 2.5

*/