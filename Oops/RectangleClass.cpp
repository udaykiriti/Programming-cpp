#include "Rectangle.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

Rectangle::Rectangle(){
    width = 10;
    length = 10;
}

void Rectangle::setLength(double l){
    if(l>0) length = l;
    else exit(EXIT_FAILURE);
}
void Rectangle::setWidth(double w){
    if(w>0) width = w;
    else exit(EXIT_FAILURE);
}

int main(int argc , char *argv[]) {
    Rectangle r;
    r.setLength(0);
    cout<<r.getLenth()<<endl;
    cout<<r.getWidth()<<endl;
    cout<<r.getArea()<<endl;
}