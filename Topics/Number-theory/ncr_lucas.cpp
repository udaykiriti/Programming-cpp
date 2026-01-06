/*
  Topic: nCr using Lucas Theorem (Competitive Programming)

  Problem:
  Compute C(n, r) % p efficiently when:
    - n, r are very large (up to 10^18 or more)
    - p is a prime number

  Key Concepts Used:
    1. Lucas Theorem
    2. Fermat's Little Theorem (Modular Inverse)
    3. Fast Exponentiation

  Time Complexity:
    - Precomputation: O(p)
    - Query: O(log_p(n))

  Space Complexity:
    - O(p) for factorial array


  References / Documentation:
  
  CP-Algorithms (Highly Recommended):
  https://cp-algorithms.com/combinatorics/binomial-coefficients.html#lucas-theorem

  GeeksforGeeks:
  https://www.geeksforgeeks.org/lucas-theorem/

  Wikipedia:
  https://en.wikipedia.org/wiki/Lucas%27s_theorem

  Modular Inverse (Fermat):
  https://cp-algorithms.com/algebra/module-inverse.html

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
  Fast Modular Exponentiation
  Computes (a^b) % mod
  Used for Fermat's modular inverse
*/
ll modexp(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

/*
  Computes nCr % p where:
    - p is prime
    - n, r < p

  Formula:
    nCr % p = fact[n] * inv(fact[r] * fact[n-r]) % p
*/
ll nCr_mod_p(ll n, ll r, ll p, vector<ll>& fact) {
    if (r > n) return 0;
    ll numerator = fact[n];
    ll denominator = (fact[r] * fact[n - r]) % p;
    return (numerator * modexp(denominator, p - 2, p)) % p;
}

/*
  Lucas Theorem:
  Breaks n and r into base-p digits

  C(n, r) % p =
  C(n0, r0) * C(n1, r1) * ... % p
*/
ll nCr_lucas(ll n, ll r, ll p, vector<ll>& fact) {
    if (r == 0) return 1;

    ll ni = n % p;
    ll ri = r % p;

    if (ri > ni) return 0;

    return (nCr_lucas(n / p, r / p, p, fact)
           * nCr_mod_p(ni, ri, p, fact)) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, r, p;
    cin >> n >> r >> p;   // p must be prime

    /*Precompute factorials modulo p */
    vector<ll> fact(p);
    fact[0] = 1;
    for (ll i = 1; i < p; i++)
        fact[i] = (fact[i - 1] * i) % p;

    cout << nCr_lucas(n, r, p, fact) << "\n";
    return 0;
}
