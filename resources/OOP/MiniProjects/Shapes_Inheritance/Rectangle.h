#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double length, width;
public:
    Rectangle();
    Rectangle(double l, double w);
    void setLength(double);
    void setWidth(double);
    double getLength() const {
        return length;
    }
    double getWidth() const {
        return width;
    }
    double getArea() const {
        return length * width;
    }
};
#endif
