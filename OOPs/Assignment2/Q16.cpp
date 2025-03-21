#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    int x;
    int y;
    int z;

public:
    Point(int x = 0, int y = 0, int z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double distance(Point p1, Point p2)
    {
        double d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
        return d;
    }
};

int main()
{
    Point p1, p2(1, 1, 1);
    cout << "the distance is: " << p1.distance(p1, p2);
return 0;
}
