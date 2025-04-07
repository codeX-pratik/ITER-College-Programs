#include<iostream>
using namespace std;

class Distance {
private:
    float km, m, cm;

    void normalize() {
        if (cm >= 100) {
            m += cm / 100;
            cm = (int)cm % 100;
        }

        if (m >= 1000) {
            km += m / 1000;
            m = (int)m % 1000;
        }
    }

public:
    void inpute_distance(float k = 0, float me = 0, float c = 0) {
        km = k;
        m = me;
        cm = c;
        normalize();
    }

    void display() {
        cout << "Distance in km: " << km << " km" << endl;
        cout << "Distance in m: " << m << " m" << endl;
        cout << "Distance in cm: " << cm << " cm" << endl;
    }

    Distance add_distance(Distance d) {
        Distance result;
        result.km = km + d.km;
        result.m = m + d.m;
        result.cm = cm + d.cm;
        result.normalize();
        return result;
    }
};

int main() {
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
        cout << "Distance " << i + 1 << ":" << endl;
        distances[i].display();
    }

    int index1, index2;
    cout << "Enter the indices of the two distances to add (0 to " << n - 1 << "): ";
    cin >> index1 >> index2;

    Distance result = distances[index1].add_distance(distances[index2]);

    cout << "Result of addition:" << endl;
    result.display();

    delete[] distances;
    return 0;
}

/*

Enter the number of distance objects: 2
Enter distance 1 (km m cm): 2 500 75
Enter distance 2 (km m cm): 1 750 50
Distance 1:
Distance in km: 2 km
Distance in m: 500 m
Distance in cm: 75 cm
Distance 2:
Distance in km: 1 km
Distance in m: 750 m
Distance in cm: 50 cm
Enter the indices of the two distances to add (0 to 1): 0 1
Result of addition:
Distance in km: 4.25125 km
Distance in m: 251 m
Distance in cm: 25 cm

*/