#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    int code;
    string name;
public:
    void getData(int c, string n) {
        code = c;
        name = n;
    }
    void display() {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

class Teacher : public Staff {
protected:
    string subject;
    string publication;
public:
    void getData(int c, string n, string s, string p) {
        Staff::getData(c, n);
        subject = s;
        publication = p;
    }
    void display() {
        Staff::display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

class Officer : public Staff {
protected:
    string grade;
public:
    void getData(int c, string n, string g) {
        Staff::getData(c, n);
        grade = g;
    }
    void display() {
        Staff::display();
        cout << "Grade: " << grade << endl;
    }
};

class Typist : public Staff {
protected:
    int speed;
public:
    void getData(int c, string n, int s) {
        Staff::getData(c, n);
        speed = s;
    }
    void display() {
        Staff::display();
        cout << "Speed: " << speed << endl;
    }
};

class Regular : public Typist {
public:
    void getData(int c, string n, int s) {
        Typist::getData(c, n, s);
    }
};

class Casual : public Typist {
protected:
    int daily_wages;
public:
    void getData(int c, string n, int s, int d) {
        Typist::getData(c, n, s);
        daily_wages = d;
    }
    void display() {
        Typist::display();
        cout << "Daily Wages: " << daily_wages << endl;
    }
};

int main() {
    Teacher t;
    Officer o;
    Regular reg;
    Casual cas;

    t.getData(101, "John Doe", "Mathematics", "Advanced Algebra");
    o.getData(201, "Jane Smith", "A");
    reg.getData(301, "Mike Johnson", 60);
    cas.getData(401, "Sarah Williams", 50, 1000);

    cout << "Teacher Details:" << endl;
    t.display();
    cout << "\nOfficer Details:" << endl;
    o.display();
    cout << "\nRegular Typist Details:" << endl;
    reg.display();
    cout << "\nCasual Typist Details:" << endl;
    cas.display();

    return 0;
}

/*

Teacher Details:
Code: 101
Name: John Doe
Subject: Mathematics
Publication: Advanced Algebra

Officer Details:
Code: 201
Name: Jane Smith
Grade: A

Regular Typist Details:
Code: 301
Name: Mike Johnson
Speed: 60

Casual Typist Details:
Code: 401
Name: Sarah Williams
Speed: 50
Daily Wages: 1000

*/