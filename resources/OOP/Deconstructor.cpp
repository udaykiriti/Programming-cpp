// A destructor is a member function that is automatically called when an object is destroyed

#include<bits/stdc++.h>
using namespace std;

class Demo{
    public:
        Demo(); //constroctar
        ~Demo();//deconstroctar
};

Demo::Demo(){
    cout<<"Welcom to con"<<endl;
}
Demo::~Demo(){
    cout<<"welcome to decon"<<endl;
}

int main(void){
    Demo dec;
    cout<<"this pro demonstrates an object"<<endl;
    cout<<"with a con and decon"<<endl;
}