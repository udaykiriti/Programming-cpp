#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reversed: " << reverse_number(n) << endl;
    return 0;
}
