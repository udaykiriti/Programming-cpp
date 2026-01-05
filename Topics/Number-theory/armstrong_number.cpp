#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a number: ";
    cin >> n;
    if (is_armstrong(n)) cout << "YES, it is an Armstrong number" << endl;
    else cout << "NO, it is not an Armstrong number" << endl;
    return 0;
}
