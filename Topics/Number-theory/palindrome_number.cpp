#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a number: ";
    cin >> n;
    if (is_palindrome(n)) cout << n << " is a Palindrome" << endl;
    else cout << n << " is NOT a Palindrome" << endl;
    return 0;
}
