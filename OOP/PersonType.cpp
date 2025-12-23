#include "PersonType.h"
#include <iostream>
using namespace std;

PersonType::PersonType() : name("Unknown"), dob(DateType()) {}

PersonType::PersonType(string n, DateType d) : name(n), dob(d) {}

void PersonType::setPerson(string n, DateType d) {
    name = n;
    dob = d;
}

void PersonType::DisplayPerson() const {
    cout << "Name: " << name << endl;
    cout << "DOB: ";
    dob.DisplayDate();
}
