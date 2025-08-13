#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double width;
    double length;
public:
    Rectangle(double,double); //Constructor
    Rectangle(double l,double w){
        length=l;
        width=w;
    }
    Rectangle(){
        length=0.0;
        width=0.0;
    }
    void setWidth(double);
    void setLenght(double);
    double getWidth() const{
        return width;
    }
    double getLength() const{
        return length;
    }
    double getArea() const{
        return length*width;
    }
};
#endif