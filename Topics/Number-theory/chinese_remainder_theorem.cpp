#include <iostream>
#include <vector>
#include "include/number_theory_basics.hpp"
#include "include/extgcd.hpp"

using namespace std;
using namespace NumberTheory;

ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = extendedGCD(a, mod, x, y);
    if (g != 1) return -1;
    return (x % mod + mod) % mod;
}

/*
 * Chinese Remainder Theorem (CRT)
 *
 * Concepts:
 *   - Solves a system of congruences with pairwise coprime moduli.
 *   - Uses Modular Inverse and Extended Euclidean Algorithm.
 *
 * Resources:
 *   - CP-Algorithms: https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
 *   - GeeksforGeeks: https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
 *
 * @param a  Vector of remainders
 * @param m  Vector of pairwise coprime moduli
 * @return   Smallest x such that x ≡ a[i] (mod m[i])
 */
ll CRT(vector<ll>& a, vector<ll>& m) {
    ll M = 1;
    for (ll mod : m) M *= mod;
    ll result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        ll Mi = M / m[i];
        ll inv = modInverse(Mi, m[i]);
        if (inv == -1) {
            cout << "Modular inverse doesn't exist\n";
            return -1;
        }
        result = (result + a[i] * Mi % M * inv % M) % M;
    }
    return result;
}

int main() {
    vector<ll> a = {2, 3, 2};
    vector<ll> m = {3, 5, 7};
    ll ans = CRT(a, m);
    if (ans != -1)
        cout << "Smallest solution x = " << ans << '\n';
    return 0;
}
