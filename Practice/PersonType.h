#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <bits/stdc++.h>
#include "DateType.h"

class PersonType {
private:
    std::string name;
    DateType dob;

public:
    PersonType();
    PersonType(std::string n, DateType d);

    void setPerson(std::string n, DateType d);
    void DisplayPerson() const;
};

#endif
