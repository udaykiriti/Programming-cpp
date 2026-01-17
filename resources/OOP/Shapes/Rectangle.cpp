#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

void Rectangle::draw() {
    cout << "Drawing a Rectangle (" << width << " x " << height << ")" << endl;
}

double Rectangle::area() {
    return width * height;
}
