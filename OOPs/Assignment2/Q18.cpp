#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    static double distance(const Point& p1, const Point& p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

class Device {
    int id;
    Point p;
    int range;

public:
    Device(int id = 0, Point p = Point(), int range = 0) : id(id), p(p), range(range) {}

    void neighbours(const Device devices[], int numDevices) const {
        cout << "Neighbours of device " << id << " are: ";
        for (int i = 0; i < numDevices; i++) {
            if (id != devices[i].id) {
                if (Point::distance(p, devices[i].p) <= range) {
                    cout << devices[i].id << ' ';
                }
            }
        }
        cout << '\n';
    }
};

int main() {
    const int numDevices = 10;
    Device devices[numDevices];
    for (int i = 0; i < numDevices; i++) {
        devices[i] = Device(i + 1, Point(i, i), 5);
    }
    for (int i = 0; i < numDevices; i++) {
        devices[i].neighbours(devices, numDevices);
    }
    return 0;
}

