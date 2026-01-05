#include <cstdlib>   // for abs
#include <numeric>  // for gcd (C++17)
#include <cmath>    // for std::abs
#include "diophantine.hpp"
#include "extgcd.hpp"

bool solveLDE(ll a, ll b, ll c,
              ll &x, ll &y) {

    ll x0, y0;
    ll g = extendedGCD(std::abs(a), std::abs(b), x0, y0);

    if (c % g != 0)
        return false;

    x = x0 * (c / g);
    y = y0 * (c / g);

    if (a < 0) x = -x;
    if (b < 0) y = -y;

    return true;
}
