#include <iostream>
#include <string>
using namespace std;

class DB;

class DM {
    int metres, centimetres;
    public:
        DM(int m = 0, int cm = 0) : metres(m), centimetres(cm) {}
        void display() {
            cout << "Distance in DM: " << metres << " metres " << centimetres << " centimetres" << endl;
        }
        friend class DB;
        friend DM operator+(DM d, DB b);
};

class DB {
    int feet, inches;
    public:
        DB(int f = 0, int i = 0) : feet(f), inches(i) {}
        void display() {
            cout << "Distance in DB: " << feet << " feet " << inches << " inches" << endl;
        }
        friend DM operator+(DM d, DB b);
};



DM operator+(DM d, DB b) {
    int total_inches = (b.feet * 12) + b.inches;
    int total_centimetres = (d.metres * 100) + d.centimetres;
    total_centimetres += total_inches * 2.54;
    return DM(total_centimetres / 100, total_centimetres % 100);
}

int main() {
    int feet, inches, metres, centimetres;
    cout << "Enter distance in DB (feet and inches): ";
    cin >> feet >> inches;
    DB db(feet, inches);
    
    cout << "Enter distance in DM (metres and centimetres): ";
    cin >> metres >> centimetres;
    DM dm(metres, centimetres);
    
    DM result = dm + db;
    
    db.display();
    dm.display();
    result.display();
    
    return 0;
}

/*
Enter distance in DB (feet and inches): 5 20
Enter distance in DM (metres and centimetres): 2 50
Distance in DB: 5 feet 20 inches
Distance in DM: 2 metres 50 centimetres
Distance in DM: 4 metres 53 centimetres
*/