#include "PersonType.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    DateType d(15, 8, 2000);
    PersonType p("Uday", d);
    p.DisplayPerson();
    return 0;
}
