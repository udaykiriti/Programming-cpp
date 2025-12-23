#include "Circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

void Circle::draw() {
    cout << "Drawing a Circle with radius " << radius << endl;
}

double Circle::area() {
    return M_PI * radius * radius;
}
