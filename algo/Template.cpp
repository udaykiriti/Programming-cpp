/*
....................................................................................................
....                                                                                               .
....                                                                                               .
....                                         .                                                     .
....                                   .........................                                   .
....                           .....   ......::=***===+=-:......                                   .
....                        .............=######%#####=-:...........                               .
....                        ....:=-...:*+==+#######*#####--=++*-....                               .
....                    ......-*####++-..:+###%*=--:.####*--*####+:...........                     .
....                    ..:+*##########*-.-=:..::....*###*:..:*####*+*:.......                     .
....               ......-**####*-*#####*=...........*###*:.*#####*####*+-......                   .
....               .....*#####*:....-####=... ....:+####*:.+###:...+#*-*##+.....                   .
....             ....:###*##%*..   ...####=.....:######*:..:###...:*##:.+##%%-....                 .
....             ...::-:-==#*-..   ..=%##*-..:*####%*#:.....+#%#%%%%#*...:+###+:..                 .
....          .......=-...=*-...   ..-####==######*=..........+##**+......:+####-....              .
....          ...-..............   ..-%#%##%###==:..:-+*#%%%%%%###+-:.. ...:*####+:..              .
....          ..-*.:-.=#+*#+++:......*#######*-..:*##################%*=:.....+###=....            .
....          ..#-=##*#%#########=..:#######-....:=###################%###+:..:+##*+...            .
....      .....+#######+-+++#####%#=:#####%=..   ..:########################*:.:+##*.....          .
....      ....+#####*-......:-*###%#####%#=...   ...+######*##%#=..:*#########*:.-*#%:...          .
....      ...==%###*-..     ....+##########=........+##%##-....::....-%##*##%###=.=##=+..          .
....      ...-#####=..  .   .....:##########+:.....+#%#%##*-.....+##+..=...+#%%##=:####..          .
....      ...=##*#*=:........:-:..+##########%####%###%#-......:+%##%##:....*####%+-###-.          .
....      ..:##.++#+:.....:*#%##-.-*################%#######*-=%########+...:%####%=:##=.          .
....      ...==:+:++-...-*#%####*..:*####################################*:..*######:-#+.          .
....      ...=++.........:+######:..:+####################################*:.=%%####*.++.          .
....      ...-*%:...........:+%##+....+####################################+....-*##%::+.          .
....      ...-##:.:--*#-=+:...-%##=....:*%################################%#=....=##%-.:.          .
....      ....*%=:*#%%%####+:.:%###+:.....-#%################################....=###=...          .
....      ...:*%#=#=.....+##*-*#*:*%#+....:*%#######%###############%#*######=...+###=...          .
....      .....###*:.....:+#*-#+...-####*::*###%#*+##################*.:#####*..-###%-...          .
....         ..*%#=.......+#*=.......:*#########+.+#################=+.:*#####..+###%....          .
....          ..=%#+:...:+##-...   ......=*####*..+##################=.:######...+##*....          .
....          ..+####%##%*-=......:--.......+#+...-*#######*=#######::.=%####*...-##:...           .
....          ...=#*-..+-....  ..-=*#*.....::......-*#####=.:#######*...-*###=...=#=...            .
....          ...-*#*:....... ..:=#####=............=#####-.=######++...-####...-#+..              .
....          ....:=##=...    ..+######%#*=:....:=+*######=.+######=...=##%%=..-*+...              .
....          . ...:+##*:.......:::.::*%#####%%%%#####%##*:-#######-.:####%+..-#=....              .
....             ....:=##=.............-#*:.............::.+#####=::######+..*#:....               .
....               ...:####=........ ..-##=...   ........+######+...:%###=.-#-...                  .
....               ......-*###=:.......:+:............:=#%###%-.....:%#*::+:......                 .
....                    ...-+*###*-:..............:-=######=+:...:-+##-.:.....                     .
....                    .....-+#######*++====+*######%**#+:..+**###*-........                      .
....                        .....:*###%######%###*+#*=.....:*###*=:....                            .
....                        ...........:===:.-+=-......:=+###+-:.....                              .
....                           .............:-+***####*+=-:.........                               .
....                                      ......................                                   .
....                                                 ....                                          .
....                                                                                               .
....                                                                                               .
....                                                                                               .
....................................................................................................
                                   (╯°□°）╯︵ ┻━┻
                     When in doubt, just flip the table and recompile.
*/

/******************************
 *    author:  -----          *
 *    created: 30 20:39:22    *
 ******************************/

#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <chrono>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

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

#define matrix2d(name, rows, cols) vector<vector<int>> name(rows, vector<int>(cols))

#define ordered_set(T)      tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_map(K, V)   tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>
#define multiordered_set    tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>

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
#define _flush endl
#define endl '\n'

/* 
#define debug(x) cout << (x) << endl
#define debugVec(v) do { cout << #v << " = "; for (auto u : v) cout << u << " "; cout << endl; } while(0)
#define printm(m) do { cout << "[\n"; for (auto i : m) cout << i.first << " -> " << i.second << endl; cout << "...]\n"; } while(0)
#define prints(s) do { cout << "{"; for (auto i : s) cout << i << ' '; cout << "}\n"; } while(0)
*/
#define MOD 1000000000
#define PI  3.141592653589793
#define INF 1000000000000000000LL
#define EPS 1e-9
#define MAX 10000000000000000LL
#define MIN -10000000

#define pb        push_back
#define eb        emplace_back
#define f         first
#define s         second
#define all(a)    (a).begin(), (a).end()
#define rall(a)   (a).rbegin(), (a).rend()
#define SORT(a)   sort(all(a))
#define RSORT(a)  sort(rall(a))

#define FOR(i, a, b)         for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b)        for (int i = (a); i >= (b); --i)
#define FORE(i, a, b)        for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k)     for (int i = (a); i < (b); i += k)
#define RFORK(i, a, b, k)    for (int i = (a); i >= (b); i -= k)
#define FORA(a)              for (auto u : a)
#define SCANA(x)             for (auto &i : x) cin >> i

#define lcm(a, b)            ((a) * ((b) / gcd((a), (b))))
#define popcount(x)          __builtin_popcountll(x)
#define ctz(x)               __builtin_ctzll(x)
#define clz(x)               __builtin_clzll(x)
#define parity(x)            __builtin_parityll(x)
#define sqr(x)               ((x) * (x))
#define cube(x)              ((x) * (x) * (x))
#define isEven(x)            ((x) % 2 == 0)
#define isOdd(x)             ((x) % 2 != 0)
#define uceil(a, b)          ((a + b - 1) / (b))

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << x; }
void __print(const char* x) { cout << x; }
void __print(const string& x) { cout << x; }
void __print(bool x) { cout << (x ? "true" : "false"); }

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

// Variadic version to print multiple things
template <typename T, typename... Args>
void __print(T&& first, Args&&... rest) {
    __print(forward<T>(first));
        cout << " ";
    __print(forward<Args>(rest)...);
}

// Final case for 0 arguments (do nothing)
void __print() {
    cout << endl;
}


// Utility Functions
ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
bool isPrime(int n){if(n<=1)return 0;for(int i=2;i*i<=n;++i)if(n%i==0)return 0;return 1;}
bool isUp(char ch){locale loc;return isupper(ch,loc);}

// Power & Combinatorics
ll binpow(ll a,ll b){ll r=1;while(b){if(b&1)r*=a;a*=a;b>>=1;}return r;}
ll binpow(ll a,ll b,ll m){a%=m;ll r=1;while(b){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
ll powerMod(ll a,ll b,ll m){return binpow(a,b,m);}
ll factorialMod(ll n,ll m){ll r=1;for(ll i=1;i<=n;++i)r=r*i%m;return r;}
i64 NcR(i64 n,i64 r){i64 x=1,y=1;if(n-r<r)r=n-r;while(r){x*=n;y*=r;i64 g=gcd(x,y);x/=g;y/=g;--n;--r;}return x;}
i64 NpR(i64 n,i64 r){i64 r1=1;while(r--)r1*=n--;return r1;}

// XOR Range Queries
int XOR1toN(int N){int m=N%4;if(m==0)return N;if(m==1)return 1;if(m==2)return N+1;return 0;}
int XORLtoR(int L,int R){return XOR1toN(R)^XOR1toN(max(L-1,0));}
//=======================TIMER========================
const auto start_time = chrono::high_resolution_clock::now();
void _timer_(){
    const auto end_time = std::chrono::high_resolution_clock::now();
    double delta = (double) chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    FIXED(2);
    cout << "[time: "<< delta <<" ms]\n";
}

//#define TIME
//#define PRAGMA
//#define ONPC

#ifdef PRAGMA
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma optimize("gt",on)
#endif

void _GO(void) {
    // Solution Here.....
    
}

int main() {
    /* ios_base::sync_with_stdio(0);
    cin.tie(0); */ 
    cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0);
    #ifdef ONPC
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
        cout<<"===========================Compilation Done==============================="<<endl;
    #endif
    int t(1),tcase(0); cin >> t; 
    while (tcase++,t--){
        #ifdef TIME
            cout << "[testcase: " << tcase <<"]---------------------------------";
            _timer_();
        #endif
        _GO();
    }
    #ifdef TIME
        cout << "\nfinished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}