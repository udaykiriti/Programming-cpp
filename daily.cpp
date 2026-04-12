/*
g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL p.cpp  -o p
./p <in.txt> out.txt
*/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using int_64 = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // like python!

/* Complex to expand compared to normal ones, but looks cool.*/
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUV tcT, class U, class V // It doesn't make any Sense
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT > using V1 = V<T>;
tcT > using VV = V<V<T>>;
tcT, size_t SZ > using AR = array<T, SZ>;

#define tcTP template <class... T
#define tcTPU tcTP, class... U

using vi = V<int>;
using vb = V<bool>;
using vl = V<int_64>;
using vd = V<db>;
using vs = V<str>;

#define FIXED(x) do { cout << fixed << setprecision(x); } while(0)


const int MOD = 998244353;  // 1e9+7;
const double PI = 3.14159265358979323846;
int_64 INF = 1e18;
double EPS = 1e-9;
const int MX = (int)2e5 + 5;
const int_64 MAXI = 1e18;  // not too close to LLONG_MAX
const int MIN_VAL = -1e7;

#define pb        push_back
#define eb        emplace_back
#define lb        lower_bound
#define ub        upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(a.begin(), a.end(), b) - a.begin()); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(a.begin(), a.end(), b) - a.begin()); }

#define FOR(i, a, b)         for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b)        for (int i = (a); i >= (b); --i)
#define FORE(i, a, b)        for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k)     for (int i = (a); i < (b); i += k)
#define RFORK(i, a, b, k)    for (int i = (a); i >= (b); i -= k)

tcT >
constexpr T lcm(T a, T b) { return a / gcd(a, b) * b; }
tcT >
constexpr T sqr(T x) { return x * x; }
tcT >
constexpr T cube(T x) { return x * x * x; }
tcT >
constexpr bool isEven(T x) { return 0 == x % 2; }
tcT >
constexpr bool isOdd(T x) { return 0 != x % 2; }
tcT >
constexpr T uceil(T a, T b) { return (a + b - 1) / b; }

template <class T>
[[nodiscard]] constexpr int sz(const T& c) { return static_cast<int>(std::size(c)); }

// #define ONPC

void _GO() {
  /* Solution Here..... */

}

int main(/* int argc, char *argv[] */) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin.tie(0)->ios::sync_with_stdio(0);
    #ifdef ONPC
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
        cout << "o_o >--< o_o >>>>>>>>>> Compiled <<<<<<<<<< o_o >--< o_o" << '\n';
    #endif
    int t{1},tcase{0}; cin >> t;
    while (tcase++,t--){
        _GO();
    }
    return 0;
}

/* Look for |>
 * Non-trivial problems with simple solutions, proofs, and implementations.
 * check for ub/lb.
 * Try working from backward or endcases.
 * Do not make large assumptions without a basic proof idea.
 * Overflow, bounds, and segfaults kill solutions;check them first.
 * Use DP to relax constraints; store only the minimum required state.
 * Always careful with Base conditions.
 * special cases (n=1?) ,Edge cases.
 * do smth instead of nothing; stay organized.
 * WRITE STUFF DOWN.
 * Eliminate Wrong Ideas First.
 * DON'T GET STUCK ON ONE APPROACH FOR TOO LONG.
 * If you dont get solution within time Just GIve Upp..
 */
