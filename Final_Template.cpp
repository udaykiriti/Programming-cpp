#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= k)

#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fora(a) for (auto u : a)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))
#define isEven(x) ((x) % 2 == 0)
#define isOdd(x) ((x) % 2 != 0)

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e18
#define EPS 1e-9
#define MAX 1000000000
#define MIN -1000000000

#define fraction(a)             \
  cout.unsetf(ios::floatfield); \
  cout.precision(a);            \
  cout.setf(ios::fixed, ios::floatfield);

#define debug(x) cout << #x << " = " << x << endl;
#define debugVec(v)    \
  cout << #v << " = "; \
  for (auto u : v)     \
    cout << u << " ";  \
  cout << endl;

#define EXIT return 0

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define vb vector<bool>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll powerMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod; 
    while (exp > 0) {
        if (exp & 1)  
            result = (__int128(result) * base) % mod; 
        base = (__int128(base) * base) % mod;
        exp >>= 1; 
    }
    return result;
}


ll factorialMod(ll n, ll mod)
{
  ll result = 1;
  for (ll i = 1; i <= n; i++)
    result = (result * i) % mod;
  return result;
}

void solve()
{
  vi example = {1, 2, 3, 4, 5};
  debugVec(example);
}

int main(int argc, char const *argv[])
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}
