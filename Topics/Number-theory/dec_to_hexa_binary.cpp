#include <iostream>
#include <string>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "Binary: " << to_binary(n) << ", Hex: " << to_hex(n) << endl;
    return 0;
}
