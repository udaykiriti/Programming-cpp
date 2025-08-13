#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
double divide(int nume,int deno){
    if(deno==0)
    {
       string exceptionString="Error";
       throw exceptionString;
    }else return static_cast<double>(nume)/deno;
}

int main(){
    int num1,num2; double que;
    cout<<"Enter two number : ";
    cin>>num1>>num2;
    try
    {
        que=divide(num1,num2);
        cout<<"The quotient is "<<que<<endl;
    }
    catch(string exceptionstring)
    {
        cout<<exceptionstring<<endl;
    }
}
*/

class Rectangle{
    private:
        double width;
        double length;
    public:
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

void Rectangle::setWidth(double w){
    width=w;
}
void Rectangle::setLength(double l){
    length=l;
}
double Rectangle::getWidth() const{
    return width;
}
double Rectangle::getLength() const{
    return length;
}
double Rectangle::getArea() const{
    return length*width;
}

int main(void){
    //Rectangle box;
    Rectangle *rectptr=nullptr;
    rectptr=new Rectangle();
    double rwidth,rlength;
    cin>>rwidth>>rlength;
    rectptr->setWidth(rwidth);
    rectptr->setLength(rlength);
    /*
    cout<<"Enter rwidrh and rlength: ";
    cin>>rwidth>>rlength;
    box.setLength(rlength); box.setWidth(rwidth);
    */
    cout<<rectptr->getLength()<<endl;
    cout<<rectptr->getWidth()<<endl;
    cout<<rectptr->getArea()<<endl;
    // delete rectptr;
    // rectptr=nullptr;
}