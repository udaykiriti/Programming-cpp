#include <iostream>
#include <vector>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

// Keeping specific Euler functions here or moving them?
// The original refactor simplified euler_totient, I will perform a minimal valid restoration.

/*
 * Euler's Totient Function (Phi)
 *
 * Counts the number of integers between 1 and n that are coprime to n.
 * Formula: phi(n) = n * (1 - 1/p1) * (1 - 1/p2) ...
 *
 * Resources:
 *   - CP-Algorithms: https://cp-algorithms.com/algebra/phi-function.html
 *   - GeeksforGeeks: https://www.geeksforgeeks.org/eulers-totient-function/
 */
ll phi_single(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

const int N = 1000000;
int phi[N + 1];
void phi_sieve() {
    for (int i = 1; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) { 
            for (int j = i; j <= N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    cout << "phi(" << n << ") = " << phi_single(n) << endl;
    phi_sieve();
    cout << "\nFirst 10 values of phi(n):\n";
    for (int i = 1; i <= 10; i++) cout << "phi(" << i << ") = " << phi[i] << endl;
    return 0;
}
