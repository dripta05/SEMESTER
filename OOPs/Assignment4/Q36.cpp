#include <iostream>
#include <cmath>  
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    ~Point() {}

    double getX() const {
        return x;
    }

    void setX(double x) {
        this->x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        this->y = y;
    }

    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    void print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3.0, 4.0);
    Point p2(0.0, 0.0);

    p1.print();
    p2.print();

    double distance = p1 - p2;
    cout << "Distance between p1 and p2: " << distance << endl;

    return 0;
}

