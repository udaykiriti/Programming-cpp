/*
              __                  __
             ( _)                ( _)
            / / \              / /\_\_
           / /   \            / / | \ \
          / /     \          / /  |\ \ \
         /  /   ,  \ ,       / /   /|  \ \
        /  /    |\_ /|      / /   / \   \_\
       /  /  |\/ _ '_|\    / /   /   \    \
      |  /   |/  0 \0\ \  / |    |    \    \
      |    |\|      \_\_ /  /    |     \    \
      |  | |/    \.\ o\o)  /      \     |    \
      \    |     /\`v-v  /        |    |     \
       | \/    /_| \_|  /         |    | \    \
       | |    /__/_     /   _____  |    |  \    \
       \|    [__]  \_/  |_________  \   |   \    ()
        /    [___] (    \         \  |\ |   |   //
       |    [___]                  |\| \|   /  |/
      /|    [____]                  \  |/\ / / ||
    (  \   [____ /     ) _\      \  \    \| | ||
      \  \  [_____|    / /     __/    \   / / //
      |   \ [_____/   / /        \    |   \/ //
      |   /  '----|   /=\____   _/    |   / //
   __ /  /        |  /   ___/  _/\    \  | ||
  (/-(/-\)       /   \  (/\/\)/  |    /  | /
                (/\/\)           /   /   //
                       _________/   /    /
                      \____________/    
                   buGs geT EaTeNN.
*/

/*
  author:  -----          
  created: 29 20:21:33    
*/


#undef _GLIBCXX_DEBUG
/* #include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector> */
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#ifdef USE_PBDS
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>

  using namespace __gnu_pbds;

  template <class T>
  using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

  template <class K, class V>
  using ordered_map = tree<K, V, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

  template <class T>
  using multiordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

  // optional convenience typedefs:
  using pii = std::pair<int,int>;
#endif


using int_64 = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // like python!

/* Pairs */
using pi = pair <int,int>;
using pll = pair<int_64, int_64>;
using pdb = pair<db,db>;

/* Complex to expand compared to normal ones, but looks cool.(Benq)*/
#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<int_64>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pll>;
using vpd = V<pdb>;

#define MaT2D(name, rows, cols) vector<vector<int>> name(rows, vector<int>(cols))

/*
#define os_insert(s, val) s.insert(val)
#define os_erase(s, val) s.erase(val)
#define os_kth(s, k) *s.find_by_order(k)
#define os_rank(s, val) s.order_of_key(val)
#define os_size(s) ((int)s.size())
#define oms_insert(ms, val) ms.insert({val, timer++})
#define oms_erase(ms, val) ms.erase(ms.lower_bound({val, 0}))
#define oms_kth(ms, k) ms.find_by_order(k)->first
#define oms_rank(ms, val) ms.order_of_key({val, 0})
*/

#define FIXED(x) cout << fixed << setprecision(x)

/* 
#define debug(x) cout << (x) << endl
#define debugVec(v) do { cout << #v << " = "; for (auto u : v) cout << u << " "; cout << endl; } while(0)
#define printm(m) do { cout << "[\n"; for (auto i : m) cout << i.first << " -> " << i.second << endl; cout << "...]\n"; } while(0)
#define prints(s) do { cout << "{"; for (auto i : s) cout << i << ' '; cout << "}\n"; } while(0)
*/

const int MOD = 998244353;  // 1e9+7;
double PI = 3.14159265358979323846;
int_64 INF = 1000000000000000000LL;
double EPS = 1e-9;
const int MX = (int)2e5 + 5;
const int_64 BIG = 1e18;  // not too close to LLONG_MAX
#define MIN -10000000
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!


#define sz(x)     int(size(x))
#define pb        push_back
#define eb        emplace_back
#define F         first
#define S         second
#define mp        make_pair
#define rsz       resize
#define ins       insert
#define all(a)    (a).begin(), (a).end()
#define rall(a)   (a).rbegin(), (a).rend()
#define SORT(a)   sort(all(a))
#define RSORT(a)  sort(rall(a))
#define lb        lower_bound
#define ub        upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

#define FOR(i, a, b)         for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b)        for (int i = (a); i >= (b); --i)
#define FORE(i, a, b)        for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k)     for (int i = (a); i < (b); i += k)
#define RFORK(i, a, b, k)    for (int i = (a); i >= (b); i -= k)
#define FORA(a)              for (auto u : a)
#define SCANA(x)             for (auto &i : x) cin >> i
#define lcm(a, b)            ((a) * ((b) / gcd((a), (b))))
#define setbits(x)          __builtin_popcountll(x)
#define ctz(x)               __builtin_ctzll(x)
#define clz(x)               __builtin_clzll(x)
#define parity(x)            __builtin_parityll(x)
#define sqr(x)               ((x) * (x))
#define cube(x)              ((x) * (x) * (x))
#define isEven(x)            (0 == (x) % 2)
#define isOdd(x)             (0 != (x) % 2)
#define uceil(a, b)          ((a + b - 1) / (b))

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void __print(T x) { cout << x; }

void __print(char x) { cout << x; }
void __print(const char* x) { cout << x; }
void __print(const string& x) { cout << x; }
void __print(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

template <typename T>
void __print(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        __print(v[i]);
        if (i + 1 != v.size()) cout << ", ";
    }
    cout << "]";
}

template <typename T>
void __print(const set<T>& s) {
    cout << "{";
    size_t i = 0;
    for (const auto& el : s) {
        __print(el);
        if (++i != s.size()) cout << ", ";
    }
    cout << "}";
}

template <typename K, typename V>
void __print(const map<K, V>& m) {
    cout << "{";
    size_t i = 0;
    for (const auto& [key, value] : m) {
        __print(key);
            cout << ": ";
        __print(value);
        if (++i != m.size()) cout << ", ";
    }
        cout << "}";
}


/* Utility Functions */
int_64 gcd(int_64 a, int_64 b){return b==0?a:gcd(b,a%b);}
bool isPrime(int n){if(n<=1)return 0;for(int i=2;i*i<=n;++i)if(n%i==0)return 0;return 1;}
bool isUp(char ch){locale loc;return isupper(ch,loc);}

/* Power & Combinatorics */

template <typename T>
T binpow(T a,int_64 e , T mod){
    T r = 1; a %= mod;
    while(e > 0){
        if(e & 1) r = (r * a) % mod;
        a = (a * a) % mod; e >>= 1;
    } return r;}

int_64 powerMod(int_64 a,int_64 b,int_64 m){return binpow(a,b,m);}
int_64 factorialMod(int_64 n,int_64 m){int_64 r=1;for(int_64 i=1;i<=n;++i)r=r*i%m;return r;}
int addmod(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int submod(int a, int b){ a -= b; if(a < 0) a += MOD; return a; }
int_64 mulmod(int_64 a, int_64 b){ return (a*b) % MOD; }
int_64 NcR(int_64 n,int_64 r){int_64 x=1,y=1;if(n-r<r)r=n-r;while(r){x*=n;y*=r;int_64 g=gcd(x,y);x/=g;y/=g;--n;--r;}return x;}
int_64 NpR(int_64 n,int_64 r){int_64 r1=1;while(r--)r1*=n--;return r1;}

/* XOR Range Queries */
int XOR1toN(int N){int m=N%4;if(m==0)return N;if(m==1)return 1;if(m==2)return N+1;return 0;}
int XORLtoR(int L,int R){return XOR1toN(R)^XOR1toN(max(L-1,0));}
/* ---------- TIMER ---------- */
const auto start_time = chrono::high_resolution_clock::now();
void _timer_(){
    const auto end_time = std::chrono::high_resolution_clock::now();
    double delta = (double) chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    FIXED(2);
    cout << "[time: "<< delta <<" ms]\n";
}
/**
 * Disjoint Set Union(DSU) 
 * Source : https://codeforces.com/blog/entry/120381
 * Time: almost constant O(alph(n))
 * It is Efficiently manages and merges disjoint sets used to track connectivity-
 * && group elements like kruskal's Algo for MST and connected compnent detection.
**/
struct DSU{
    int n;
    vi parent,size;
    DSU(int n) : n(n),parent(n),size(n,1){
        iota(all(parent),0);
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a , int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

/**
 * Fenwik Tree (BIT)
 * Source: https://codeforces.com/blog/entry/57292
 * Time: update = O(log n), query = O(log n)
 * Description: 
 * Uses binary index jumps based on lowest set bits
 * Good for range sums, inversion counting, frequncies
 * simple and faster than segment tree for point updates
**/
struct Fenwik{
    int n;
    vector<int_64> bit;
    Fenwik(int n) : n(n),bit(n+1,0){ }

    void update(int i, int_64 v){
        for( ; i <= n ; i += i & -i)
            bit[i] += v;
    }
    int_64 query(int i){
        int_64 s(0);
        for(; i > 0 ; i -= i & -i)
            s += bit[i];
        return s;
    }
    int_64 range(int l , int r){
        return query(r) - query(l-1);
    }
};

//#define TIME
//#define PRAGMA
//#define ONPC

#ifdef PRAGMA
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma optimize("gt",on)
#endif

void _GO() {
  // Solution Here.....
  int p, q, r;
  cin >> p >> q >> r;

  auto mb = [&](int ln) {
      vi v; 
      v.reserve(ln);
      for (int i = 0; i < ln; ++i) 
        v.pb((i % 2) == 0 ? 1 : 0);
      return v;
  };

  vi A = mb(p);
  vi B = mb(q);
  vi C = mb(r);

  auto build = [&](vi a, vi b){
    a.pb(2);
    a.ins(a.end(), b.begin(), b.end());
    return a;
  };

  vi tmp1 = build(A, B);
  vi tmp2 = build(A, C);
  vi tmp3 = build(B, C);


  auto ps = [&](const vi& s) {
      cout << s.size();
      for (int x : s) cout << ' ' << x;
      cout << '\n';
  };
  ps(tmp1);
  ps(tmp2);
  ps(tmp3);
}

int main(/* int argc, char *argv[] */) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0);
    #ifdef ONPC
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
        cout << "o_o >--< o_o >>>>>>>>>> Compiled <<<<<<<<<< o_o >--< o_o" << '\n';
    #endif
    int t(1),tcase(0); //cin >> t; 
    while (tcase++,t--){
        #ifdef TIME
            cout << "[ testcase: " << tcase << " ] "<< "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << "\n";
            _timer_();
        #endif
        _GO();
    }
    #ifdef TIME
        cout << "\nExecuted in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}

/* Look for |>
 * int overflow, array bounds , segmentation Faults
 * special cases (n=1?) ,Edge cases
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */