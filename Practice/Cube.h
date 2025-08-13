#ifndef CUBE_H
#define CUBE_H
#include "Rectangle.h"

class Cube:public Rectangle
{
protected:
    double height,volume;
public:
    Cube():Rectangle(){
        height=0.0;
        volume=0.0;
    }
    Cube(double w,double l,double h):Rectangle(w,l){
        height=h;
        volume=getArea()*h;
    }
    double getHeight() const{
        return height;
    }
    double getVolume() const{
        return volume;  
    }
};
#endif