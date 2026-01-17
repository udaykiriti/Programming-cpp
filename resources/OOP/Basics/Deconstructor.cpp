// A destructor is a member function that is automatically called when an object is destroyed

#include <iostream>
using namespace std;

class Demo {
public:
    Demo();  // constructor
    ~Demo(); // destructor
};

Demo::Demo() {
    cout << "Welcome to constructor" << endl;
}

Demo::~Demo() {
    cout << "Welcome to destructor" << endl;
}

int main() {
    Demo dec;
    cout << "This program demonstrates an object" << endl;
    cout << "with a constructor and destructor" << endl;
    return 0;
}
