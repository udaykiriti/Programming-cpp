#ifndef SHAPE_H
#define SHAPE_H

#include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
        virtual void draw() = 0;
        virtual double area() = 0;
        
        virtual ~Shape(){}
};

#endif