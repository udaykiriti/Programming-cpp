#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n-1,0)

#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)(x).size()

#define MOD 1000000007
#define INF 1e18
#define PI acos(-1)
#define EPS 1e-9

#define fraction(d) cout << fixed << setprecision(d)
#define debug(x) cerr << #x << " = " << x << endl
#define debugVec(v) cerr << #v << " = "; for(auto &u:v) cerr << u << " "; cerr << endl

// Short Types
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using mii = map<int,int>;
using si = set<int>;

// Math Utils
inline bool isEven(int x) { return x % 2 == 0; }
inline bool isOdd(int x) { return x % 2 != 0; }
inline ll sqr(ll x) { return x * x; }
inline ll cube(ll x) { return x * x * x; }
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Fast power modulo
ll powerMod(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Factorial modulo
ll factorialMod(ll n, ll mod = MOD) {
    ll res = 1;
    for (ll i = 1; i <= n; ++i) res = (res * i) % mod;
    return res;
}

// Prime check
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

// Bit tricks
#define popcount(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#define parity(x) __builtin_parityll(x)

// Solve Function
void solve() {
    // Write logic here
}

int main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}