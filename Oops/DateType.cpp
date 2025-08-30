#include "DateType.h"
#include <bits/stdc++.h>
using namespace std;

DateType::DateType() : month(1), day(1), year(2000) {} // default values

DateType::DateType(int newMonth, int newDay, int newYear)
    : month(newMonth), day(newDay), year(newYear) {}

void DateType::Initialize(int newMonth, int newDay, int newYear) {
    month = newMonth;
    day = newDay;
    year = newYear;
}

int DateType::GetMonth() const { return month; }
int DateType::GetYear() const { return year; }
int DateType::GetDay() const { return day; }

void DateType::DisplayDate() const {
    cout << month << "/" << day << "/" << year << endl;
}
