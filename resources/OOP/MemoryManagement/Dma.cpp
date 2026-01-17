#include <iostream>
#include <memory>
using namespace std;

class Dog {
public:
    Dog() { cout << "Dog Created\n"; } 
    ~Dog() { cout << "Dog Destroyed\n"; } 
    void bark() { cout << "Woof!\n"; } 
};

int main() {
    // Manual allocation and deallocation
    Dog* ptr = new Dog();
    ptr->bark();
    delete ptr;

    // Smart pointer (automatic memory management)
    unique_ptr<Dog> smartPtr = make_unique<Dog>();
    smartPtr->bark();
    
    return 0;
}

