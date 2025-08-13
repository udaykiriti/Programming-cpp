//#include<bits/stdc++.h>
#include<iostream>
//using namespace std;

class Demo
{
public:
    Demo();
};

Demo::Demo(/* args */)
{
    std::cout<<"welcome to constructor"<<std::endl;
}

int main(){
    Demo demoproje;
    std::cout<<"this program demonstrates an object"<<std::endl;
    std::cout<<"with a constructor"<<std::endl;
}