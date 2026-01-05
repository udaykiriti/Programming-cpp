#include <iostream>
#include "include/number_theory_basics.hpp"
#include "include/extgcd.hpp"

using namespace std;
using namespace NumberTheory;

/*
 * Modular Multiplicative Inverse
 *
 * Finds x such that (a * x) % m = 1.
 * Exists only if gcd(a, m) = 1.
 *
 * Resources:
 *   - CP-Algorithms: https://cp-algorithms.com/algebra/module-inverse.html
 *   - GeeksforGeeks: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
 */
ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = extendedGCD(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    ll a, m;
    cout << "Enter number (a) and modulo (m): ";
    cin >> a >> m;
    
    ll inv = modInverse(a, m);
    
    if (inv == -1)
        cout << "Modular Inverse does not exist (gcd != 1)" << endl;
    else
        cout << "Modular Inverse: " << inv << endl;
        
    return 0;
}
