#include <iostream>
#include <vector>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n;
    cout << "Enter a number to factorize: ";
    cin >> n;
    
    vector<ll> factors = get_prime_factors(n);
    
    cout << "Prime Factors: ";
    for (size_t i = 0; i < factors.size(); ++i) {
        cout << factors[i] << (i == factors.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}
