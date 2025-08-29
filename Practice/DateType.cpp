#include<bits/stdc++.h>
using namespace std;
#include "DateType.h"

void DateType::Initialize(int newMonth, int newDay , int newYear){
    year = newYear;
    month = newMonth;
    day = newDay;
}
int DateType::GetMonth() const{
    return month;
}

int DateType::GetYear() const{
    return year;
}

int DateType::GetDay() const{
    return day;
}

int main(int argc , char *argv[]){
    DateType today;
    DateType anotherDay;
    today.Initialize(8,29,2025);
    anotherDay.Initialize(8,30,2025);
    cout << "Date: " << today.GetMonth() << "/" << today.GetDay() << "/" << today.GetYear() << endl;
}