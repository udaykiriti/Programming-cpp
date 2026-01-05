#include <iostream>
#include <string>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll num;
    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Binary of " << num << " is: " << to_binary(num) << endl;
    return 0;
}
