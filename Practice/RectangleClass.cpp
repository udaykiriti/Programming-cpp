#include<bits/stdc++.h>
using namespace std;
#include "Rectangle.h"

Rectangle::Rectangle(double wid,double len){
    width=wid;
    length=len;
}

void Rectangle::setWidth(double w){
    if(w>=0){
        width=w;
    }else{
        cout<<"Invalid width"<<endl;
        exit(EXIT_FAILURE);
    }
}
void Rectangle::setLenght(double l){
    if(l>=0){
    length=l;
    }else{
        cout<<"Invalid length"<<endl;
        exit(EXIT_FAILURE);
    }
}

int main(void){
    cout<<"Enter len and wid: ";
    double len,wid; cin>>len>>wid;
    // box.setLenght(len); box.setWidth(wid);
    Rectangle box(len,wid);

    cout<<"Width :"<<box.getWidth()<<endl;
    cout<<"Length"<<box.getLength()<<endl;
    cout<<"Area"<<box.getArea()<<endl;
}