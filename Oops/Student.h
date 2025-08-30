#ifndef STUDENT_H
#define STUDENT_H
#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int age;
    string name;
public:
    void setData(string n, int a);
    void GetData();
};
#endif