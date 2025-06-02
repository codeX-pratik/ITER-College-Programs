#include <iostream>

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}

    Counter operator++() {
        return Counter(++count);
    }

    void display() {
        std::cout << "Count: " << count << std::endl;
    }
};

int main() {
    Counter c1(5);
    Counter c2 = ++c1;
    c2.display();
    return 0;
}

/*

Count: 6

*/