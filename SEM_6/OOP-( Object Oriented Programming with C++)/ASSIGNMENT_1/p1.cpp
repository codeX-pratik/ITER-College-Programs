#include <iostream>
using namespace std;

enum Days {
    SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

int main() {
    int dayNum;
    cout << "Enter the day number : (1 for sunday, 2 for monday, ... ) : ";
    cin >> dayNum;

    if (dayNum < 1 || dayNum > 7) {
        cout << "Invalid day number!";
    } else {
        Days day = static_cast<Days>(dayNum);

        switch (day) {
            case SUNDAY: cout << "The day is Sunday." << endl; break;
            case MONDAY: cout << "The day is Monday." << endl; break;
            case TUESDAY: cout << "The day is Tuesday." << endl; break;
            case WEDNESDAY: cout << "The day is Wednesday." << endl; break;
            case THURSDAY: cout << "The day is Thursday." << endl; break;
            case FRIDAY: cout << "The day is Friday." << endl; break;
            case SATURDAY: cout << "The day is Saturday." << endl; break;
        }
    }

    return 0;
}

/*
Enter the day number : (1 for sunday, 2 for monday, ... ) : 1
The day is Sunday.

Enter the day number : (1 for sunday, 2 for monday, ... ) : 3
The day is Tuesday.
*/