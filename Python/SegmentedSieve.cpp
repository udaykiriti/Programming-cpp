#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORk for (int i = (a); i >= (b); i -= k)

#define pb push_back
#define eb emplace_back
#define all(x) sort((x).begin(), (x).end())
#define rall(x) sort((x).end(), (x).begin())

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
#define debugVec(v)    \
  cerr << #v << " = "; \
  for (auto &u : v)    \
    cerr << u << " ";  \
  cerr << endl

// Short Types
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using mii = map<int, int>;
using si = set<int>;

// typedef vector<int> vi;
// typedef vector<string> vs;

// Math Utils
inline bool isEven(int x) { return x % 2 == 0; }
inline bool isOdd(int x) { return x % 2 != 0; }
inline ll sqr(ll x) { return x * x; }
inline ll cube(ll x) { return x * x * x; }
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Fast power modulo
ll powerMod(ll base, ll exp, ll mod = MOD)
{
  ll res = 1;
  while (exp > 0)
  {
    if (exp & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

// Factorial modulo
ll factorialMod(ll n, ll mod = MOD)
{
  ll res = 1;
  for (ll i = 1; i <= n; ++i)
    res = (res * i) % mod;
  return res;
}

// Prime check
bool isPrime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return true;
}

// Bit tricks
#define popcount(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#define parity(x) __builtin_parityll(x)

const int msm = 31623; // sqrt(1e9)
bool pr[msm + 1];
bool p[100001];
vi prs;
vector<int> vec;

void sieve()
{
  fill(pr, pr + msm + 1, true);
  pr[0] = pr[1] = false;
  for (int i = 2; i * i <= msm; i++)
    if (pr[i])
      for (int j = i * i; j <= msm; j += i)
        pr[j] = false;

  for (int i = 2; i <= msm; i++)
    if (pr[i])
      prs.push_back(i);
}

void seg_seive(int N, int M)
{
  for (int i = 0; i <= M - N; i++)
    p[i] = true;
  if (N == 1)
    p[0] = false;

  int sm = int(sqrt(M));
  for (auto i : prs)
  {
    if (i > sm)
      break;
    int x = max(i * i, ((N + i - 1) / i) * i);
    for (int j = x; j <= M; j += i)
      p[j - N] = false;
  }

  for (int i = 0; i <= M - N; i++)
    if (p[i])
      cout << N + i << '\n';
}

void solve()
{
  int n, m;
  cin >> n >> m;
  seg_seive(n, m);
  cout << '\n';
}
int main()
{
  FAST_IO;
  sieve();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
