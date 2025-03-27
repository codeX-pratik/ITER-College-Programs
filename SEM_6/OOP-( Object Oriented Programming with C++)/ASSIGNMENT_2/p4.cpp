#include<iostream>
#include<string>
using namespace std;

/*
Create a class distance with private data members km,m,cm. Include the following member
functions:
input distance() with 3 parameters to initialize the distance object.
display() to display a distance object.
add distance() to perform addition of 2 distance objects and will return the result.
In the main function, create an array of n distance objects, initialize and display them. Perform
addition of any 2 distance object by prompting the user for the index of 2 objects in the array.
Display the result.
*/

class Distance {
    private:
        float km, m, cm;
    
    public:
        void inpute_distance(float km = 0, float m = 0, float cm = 0) {
            this->km = km;
            this->m = m;
            this->cm = cm;
        }

        void display() {
            cout << "Distance in km: " << km << " km " << endl;
            cout << "Distance in m: " << m << " m " << endl;
            cout << "Distance in cm: " << cm << " cm " << endl;
        }

        Distance add_distance(Distance d) {
            Distance result;
            result.cm = cm + d.cm;
            result.m = m + d.m + (result.cm / 100);
            result.km = km + d.km + (result.m / 1000);
            return result;
        }
};

int main () {
    int n;
    cout << "Enter the number of distance objects: ";
    cin >> n;
    
    Distance* distances = new Distance[n];
    
    for (int i = 0; i < n; i++) {
        float km, m, cm;
        cout << "Enter distance " << i + 1 << " (km m cm): ";
        cin >> km >> m >> cm;
        distances[i].inpute_distance(km, m, cm);
    }
    
    for (int i = 0; i < n; i++) {
        cout << "Distance " << i + 1 << ": ";
        distances[i].display();
    }
    
    int index1, index2;
    cout << "Enter the indices of the two distances to add (0 to " << n - 1 << "): ";
    cin >> index1 >> index2;
    
    Distance result = distances[index1].add_distance(distances[index2]);
    
    cout << "Result of addition: " << endl;
    result.display();
    
    delete[] distances;
    
    return 0;
}