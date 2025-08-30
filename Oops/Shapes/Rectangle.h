#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h);
    void draw() override;
    double area() override;
};

#endif // RECTANGLE_H
