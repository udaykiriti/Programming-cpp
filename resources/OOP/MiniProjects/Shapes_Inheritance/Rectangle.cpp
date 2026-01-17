#include "Rectangle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Rectangle::Rectangle() {
    width = 10;
    length = 10;
}

void Rectangle::setLength(double l) {
    if (l > 0) length = l;
    else exit(EXIT_FAILURE);
}

void Rectangle::setWidth(double w) {
    if (w > 0) width = w;
    else exit(EXIT_FAILURE);
}

int main() {
    Rectangle r;
    r.setLength(5); // Set a valid length to test
    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.getArea() << endl;
    return 0;
}
