#include "Circle.h"
#include "Rectangle.h"

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);

    s1->draw();
    cout << "Area: " << s1->area() << endl;

    s2->draw();
    cout << "Area: " << s2->area() << endl;

    delete s1;
    delete s2;

    return 0;
}
