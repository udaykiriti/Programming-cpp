#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a number: ";
    cin >> n;
    if (is_prime(n)) cout << n << " is Prime" << endl;
    else cout << n << " is Not Prime" << endl;
    return 0;
}
