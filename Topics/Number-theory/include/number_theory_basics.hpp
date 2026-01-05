#ifndef NUMBER_THEORY_BASICS_HPP
#define NUMBER_THEORY_BASICS_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdint>

#define ll int64_t
#define ull uint64_t

namespace NumberTheory {

    // Calculate Factorial
    inline ull factorial(int n) {
        ull fact = 1;
        for (int i = 1; i <= n; ++i)
            fact *= i;
        return fact;
    }

    // Check if number is Prime
    inline bool is_prime(ll n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (ll i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    // Calculate GCD
    inline ll gcd(ll a, ll b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    // Calculate LCM
    inline ll lcm(ll a, ll b) {
        if (a == 0 || b == 0) return 0;
        return (a * b) / gcd(a, b);
    }

    // Modular Exponentiation (base^exp % mod)
    inline ll mod_pow(ll base, ll exp, ll mod) {
        ll res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    // Count Set Bits
    inline int count_set_bits(ll n) {
        return __builtin_popcountll(n);
    }

    // Reverse a number
    inline ll reverse_number(ll n) {
        ll reversed = 0;
        while(n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }

    // Check if Palindrome
    inline bool is_palindrome(ll n) {
        return n == reverse_number(n);
    }

    // Binary Search Square Root
    inline ll sqrt_binary_search(ll x) {
        if (x == 0 || x == 1) return x;
        ll low = 1, high = x, ans;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (mid <= x / mid) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Digital Root (O(1))
    inline ll digital_root(ll n) {
        if (n == 0) return 0;
        return 1 + (n - 1) % 9;
    }

    // Convert to Binary String
    inline std::string to_binary(ll n) {
        if (n == 0) return "0";
        std::string res;
        while (n) {
            res = char((n % 2) + '0') + res;
            n /= 2;
        }
        return res;
    }

    // Convert to Hex String
    inline std::string to_hex(ll n) {
        if (n == 0) return "0";
        std::string hex = "0123456789ABCDEF", res;
        while (n) {
            res = hex[n % 16] + res;
            n /= 16;
        }
        return res;
    }

    // Next Palindrome
    inline ll next_palindrome(ll n) {
        n++;
        while (!is_palindrome(n))
            n++;
        return n;
    }

    // Count Primes Sieve (returns count)
    inline int count_primes_sieve(ll n) {
        if (n <= 2) return 0;
        std::vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (ll i = 2; i * i < n; ++i)
            if (isPrime[i])
                for (ll j = i * i; j < n; j += i)
                    isPrime[j] = false;
        return std::count(isPrime.begin(), isPrime.end(), true);
    }

     // Check Armstrong Number
    inline bool is_armstrong(ll n) {
        ll digits = 0, org = n, temp = n;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        temp = n;
        ull sum = 0;
        while (temp != 0) {
            int digit = temp % 10;
            sum += (ull)std::pow(digit, digits);
            temp /= 10;
        }
        return sum == (ull)org;
    }

    // Check Perfect Number
    inline bool is_perfect(ll num) {
        ll sum = 0;
        for (ll i = 1; i < num; i++) {
            if (num % i == 0)
                sum += i;
        }
        return sum == num;
    }

    /*
     * Prime Factorization
     * Resources: https://cp-algorithms.com/algebra/factorization.html
     */
    inline std::vector<ll> get_prime_factors(ll n) {
        std::vector<ll> factors;
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        for (ll i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        if (n > 2) factors.push_back(n);
        return factors;
    }

    // Modular Inverse (requires Extended GCD logic, assume purely mathematical here or user provided)
    // Since we have extgcd.hpp, we might keep it separate, but for nCr we need it.
    // Let's implement a self-contained simple one or similar to extgcd for nCr.
    inline ll mod_inverse_simple(ll n, ll mod) {
        return mod_pow(n, mod - 2, mod); // Fermat's Little Theorem (for prime mod)
    }

    /*
     * Binomial Coefficient (nCr)
     * Uses Fermat's Little Theorem for modular inverse.
     * Resources: https://cp-algorithms.com/combinatorics/binomial-coefficients.html
     */
    inline ll nCr(ll n, ll r, ll mod) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        
        std::vector<ll> fact(n + 1);
        fact[0] = 1;
        for (ll i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % mod;
            
        return (fact[n] * mod_inverse_simple((fact[r] * fact[n - r]) % mod, mod)) % mod;
    }
}

#endif // NUMBER_THEORY_BASICS_HPP
