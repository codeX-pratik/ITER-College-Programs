#include <iostream>
#include <string>
using namespace std;

class String {
public:
    string str;

    String() {
        str = "";
    }

    String(string s) {
        str = s;
    }

    String add(String s2) {
        String result;
        result.str = str + s2.str;
        return result;
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    String s1;
    cout << "s1 (empty): ";
    s1.display();

    String s2("Well done!");
    cout << "s2 (initialized): ";
    s2.display();

    String s3 = s1.add(s2);
    cout << "s3 = s1 + s2: ";
    s3.display();

    s1 = s2;
    cout << "s1 = s2: ";
    s1.display();

    return 0;
}

/*
s1 (empty): 
s2 (initialized): Well done!
s3 = s1 + s2: Well done!
s1 = s2: Well done!
*/