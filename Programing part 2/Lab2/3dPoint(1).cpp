#include <cmath>
#include <iostream>

class Point3D {
public:
    Point3D() : x(0.0), y(0.0), z(0.0) {}
    Point3D(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double X) { x = X; }
    void setY(double Y) { y = Y; }
    void setZ(double Z) { z = Z; }

    friend double operator-(const Point3D& p1, const Point3D& p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        double dz = p1.z - p2.z;
        return std::sqrt(dx*dx + dy*dy + dz*dz);
    }

private:
    double x, y, z;
};

int main() {
    Point3D p1; // default constructor
    Point3D p2(1.0, 2.0, 3.0); // parameterized constructor

    // accessing and printing the coordinates
    std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << std::endl;
    std::cout << "p2: (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")" << std::endl;

    // calculating the distance between the two points
    double dist = p1 - p2;
    std::cout << "Distance between p1 and p2: " << dist << std::endl;

    // changing the coordinates of p1
    p1.setX(3.0);
    p1.setY(2.0);
    p1.setZ(1.0);

    // calculating the distance again
    dist = p1 - p2;
    std::cout << "Distance between p1 and p2 after coordinates change: " << dist << std::endl;

    return 0;
}
