#include <iostream>
using namespace std;

class Rectangle {
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

void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setLength(double l) {
    length = l;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getArea() const {
    return length * width;
}

int main() {
    Rectangle* rectptr = new Rectangle();
    double rwidth, rlength;
    
    cout << "Enter width and length: ";
    cin >> rwidth >> rlength;
    
    rectptr->setWidth(rwidth);
    rectptr->setLength(rlength);
    
    cout << "Length: " << rectptr->getLength() << endl;
    cout << "Width: " << rectptr->getWidth() << endl;
    cout << "Area: " << rectptr->getArea() << endl;
    
    delete rectptr;
    return 0;
}
