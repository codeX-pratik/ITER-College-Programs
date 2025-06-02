#include <iostream>
using namespace std;

class Shape {
protected:
    double x, y;
public:
    void get_data(double a, double b) {
        x = a;
        y = b;
    }
    virtual void display_area() {
        cout << "Area: 0" << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() {
        cout << "Area of Triangle: " << 0.5 * x * y << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() {
        cout << "Area of Rectangle: " << x * y << endl;
    }
};

int main() {
    Shape *s;
    Triangle t;
    Rectangle r;
    
    double a, b;
    int choice;
    
    cout << "Enter 1 for Triangle or 2 for Rectangle: ";
    cin >> choice;
    cout << "Enter two values: ";
    cin >> a >> b;
    
    if (choice == 1) {
        s = &t;
        s->get_data(a, b);
        s->display_area();
    }
    else if (choice == 2) {
        s = &r;
        s->get_data(a, b);
        s->display_area();
    }
    
    return 0;
}

/*

Enter 1 for Triangle or 2 for Rectangle: 1
Enter two values: 5 8
Area of Triangle: 20

Enter 1 for Triangle or 2 for Rectangle: 2
Enter two values: 5 5
Area of Rectangle: 25

*/