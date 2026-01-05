#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll base, exp, mod;
    cout << "Enter base, exponent and modulus: ";
    cin >> base >> exp >> mod;
    cout << "Result: " << mod_pow(base, exp, mod) << endl;
    return 0;
}
