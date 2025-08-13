// Standard Libraries
#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//=======================TIMER========================
#define START_TIMER auto start_time = chrono::high_resolution_clock::now();
#define END_TIMER auto end_time = chrono::high_resolution_clock::now(); \
    cerr << "Time: " << chrono::duration<double, milli>(end_time - start_time).count() << " ms\n";

// Typedefs
using ll = long long;
using i64 = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using mii = map<int, int>;
using si = set<int>;
using sc = set<char>;

// ========== PBDS Shortcuts ==========
#define ordered_set(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define os_insert(s, val) s.insert(val)
#define os_erase(s, val) s.erase(val)
#define os_kth(s, k) *s.find_by_order(k)
#define os_rank(s, val) s.order_of_key(val)
#define os_size(s) ((int)s.size())
#define oms_insert(ms, val) ms.insert({val, timer++})
#define oms_erase(ms, val) ms.erase(ms.lower_bound({val, 0}))
#define oms_kth(ms, k) ms.find_by_order(k)->first
#define oms_rank(ms, val) ms.order_of_key({val, 0})

// Fast I/O
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)

// Output Utilities
#define FIXED(x) cout << fixed << setprecision(x)
#define _flush endl
#define endl '\n'
#define debug(x) cout << (x) << endl
#define debugVec(v) do { cout << #v << " = "; for (auto u : v) cout << u << " "; cout << endl; } while(0)
#define printm(m) do { cout << "[\n"; for (auto i : m) cout << i.first << " -> " << i.second << endl; cout << "...]\n"; } while(0)
#define prints(s) do { cout << "{"; for (auto i : s) cout << i << ' '; cout << "}\n"; } while(0)

// Macros & Constants
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e18
#define EPS 1e-9
#define MAX 1000000000
#define MIN -1000000000

// STL Shorthand
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// Looping Macros
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= k)
#define FORA(a) for (auto u : a)
#define scanv(x) for (auto &i : x) cin >> i

// Math Utilities
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * ((b) / gcd((a), (b))))
#define popcount(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#define parity(x) __builtin_parityll(x)
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))
#define isEven(x) ((x) % 2 == 0)
#define isOdd(x) ((x) % 2 != 0)
#define uceil(a, b) ((a + b - 1) / (b))

// Binary Search Shorthand
#define bin_sc(a, x) binary_search(all(a), x)
#define lbd(a, x) lower_bound(all(a), x)
#define ubd(a, x) upper_bound(all(a), x)

// Utility Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
bool isUp(char ch) { locale loc; return isupper(ch, loc); }

// Power & Combinatorics
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll powerMod(ll base, ll exp, ll mod) { return binpow(base, exp, mod); }

ll factorialMod(ll n, ll mod) {
    ll res = 1;
    for (ll i = 1; i <= n; ++i)
        res = (res * i) % mod;
    return res;
}

i64 NcR(i64 n, i64 r) {
    i64 x = 1, y = 1;
    if (n - r < r) r = n - r;
    while (r) {
        x *= n;
        y *= r;
        i64 cm = gcd(x, y);
        x /= cm;
        y /= cm;
        --n;
        --r;
    }
    return x;
}

i64 NpR(i64 n, i64 r) {
    i64 res = 1;
    while (r--) res *= n--;
    return res;
}

// XOR Range Queries
int XOR1toN(int N) {
    int md = N % 4;
    if (md == 0) return N;
    if (md == 1) return 1;
    if (md == 2) return N + 1;
    return 0;
}

int XORLtoR(int L, int R) { return XOR1toN(R) ^ XOR1toN(max(L - 1, 0)); }

// Solution Function
void solve() {
    // Write your solution logic here
    string s; cin>>s;
    int a=s[0]-'0';
    int b=s[2]-'0';
    cout<<a+b<<endl;
}

// Main Function
int main() {
    stop_sync;
    untie_ios;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}