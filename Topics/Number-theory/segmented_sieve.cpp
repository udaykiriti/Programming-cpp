#include <iostream>
#include <vector>
#include <cmath>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

/*
 * Segmented Sieve of Eratosthenes
 *
 * Efficiently finds primes in a range [L, R] where R can be large (up to 10^12)
 * but R - L is relatively small (e.g., 10^6).
 *
 * Concepts:
 *   - Standard Sieve to find primes up to sqrt(R).
 *   - Use these "small primes" to mark composites in the range [L, R].
 *
 * Resources:
 *   - CP-Algorithms: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve
 *   - GeeksforGeeks: https://www.geeksforgeeks.org/segmented-sieve/
 */
void segmentedSieve(ll L, ll R) {
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes) {
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    }
    if (L == 1) isPrime[0] = false;

    cout << "Primes in range [" << L << ", " << R << "]:\n";
    for (ll i = 0; i <= R - L; ++i) {
        if (isPrime[i])
            cout << (L + i) << " ";
    }
    cout << endl;
}

int main() {
    ll L, R;
    cout << "Enter range L and R: ";
    cin >> L >> R;
    segmentedSieve(L, R);
    return 0;
}
