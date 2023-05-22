//Create a structure to describe a 3D-point. Write a program that calculates distance between two 3D-points. 
//To calculate the distance, create a function with two parameters of structure type to represent the points.

#include <iostream>
#include <cmath>

struct Point
{
    double x, y, z;
};

double calculateDistance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main(void) 
{
    Point p1, p2;
    std::cout << "input p1 X: ";
    std::cin >> p1.x;
    std::cout << "input p1 Y: ";
    std::cin >> p1.y;
    std::cout << "input p1 Z: ";
    std::cin >> p1.z;

    std::cout << "input p2 X: ";
    std::cin >> p2.x;
    std::cout << "input p2 Y: ";
    std::cin >> p2.y;
    std::cout << "input p2 Z: ";
    std::cin >> p2.z;

    std::cout << "\nDistance between p1 and p2 is: " << calculateDistance(p1, p2);
    return 0;
}