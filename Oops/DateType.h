#ifndef DATETYPE_H
#define DATETYPE_H

class DateType {
public:
    DateType();                                   // default constructor
    DateType(int newMonth, int newDay, int newYear); // parameterized constructor

    void Initialize(int newMonth, int newDay, int newYear);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    void DisplayDate() const;

private:
    int year;
    int month;
    int day;
};

#endif