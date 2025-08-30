#include "Student.h"

void Student::setData(string n,int a){
    name=n;
    age=a;
}
void Student::GetData(){
    cout << name << endl;
    cout<< age << endl;
}