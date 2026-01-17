#include<bits/stdc++.h>
using namespace std;


class Demo{
private:
    /* data */
public:
    Demo(/* args */);
    ~Demo();
};

Demo::Demo(/* args */){
    cout<<"This is Demo Class"<<endl;
}

Demo::~Demo(){
    cout<<"Destructor Called"<<endl;
}


int main(int argc , char *argv[]){
    Demo d;
    return 0;
}