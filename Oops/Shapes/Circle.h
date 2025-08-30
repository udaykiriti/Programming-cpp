#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    void draw() override;
    double area() override;
};

#endif // CIRCLE_H