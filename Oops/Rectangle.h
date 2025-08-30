#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    /* data */
    double length,width;
public:
    Rectangle(/* args */);
    Rectangle(double,double);
    void setLength(double);
    void setWidth(double);
    double getLenth() const{
        return length;
    }
    double getWidth() const{
        return width;
    }
    double getArea() const{
        return length * width;
    }
};
#endif