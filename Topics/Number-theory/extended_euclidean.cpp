#include <iostream>
#include "include/number_theory_basics.hpp"
#include "include/extgcd.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    ll x, y;
    ll g = extendedGCD(a, b, x, y);
    cout << "gcd(" << a << ", " << b << ") = " << g << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "Verification: a*x + b*y = " << a * x + b * y << endl;
    return 0;
}
