#include "extgcd.hpp"

ll extendedGCD(ll a, ll b,
                      ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
