/*
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

class Test{
    public:
        Test(){
            cout<<"constructor"<<endl;
        }
        ~Test(){
            cout<<"Deconstructor"<<endl;
        }
        void greet(){
            cout<<"Hello"<<endl;
        }
};

int main(void){
    unique_ptr<Test>ptr=make_unique<Test>();
    ptr->greet();
    unique_ptr<Test>ptr1=move(ptr);
}
*/
#include <bits/stdc++.h>
using namespace std;

class Dog {
public:
    Dog()  { cout << "Dog Created\n"; }
    ~Dog() { cout << "Dog Destroyed\n"; }
    void bark() { cout << "Woof!\n"; }
};

int main() {
    // In manual allocation and deallocation there are some problems
    // such as memory leakagea and dangling pointers 
    // In this cases memory never be freed it deallocates that 
    // But not be freed

    Dog* ptr = new Dog(); // Manual allocation
    ptr->bark();
    delete ptr;           // Manual deallocation
    /*
    // using smart pointers we don't need to delete the memory
    // the memory deleted when we dont use it
    unique_ptr<Dog> ptr = make_unique<Dog>();
    ptr->bark();
    */
    throw runtime_error("Crash");
    return 0;
}