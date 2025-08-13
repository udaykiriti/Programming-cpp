#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
// #define int long long
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
// #define m1 cout << "-1\n";
#define no cout << "NO\n";
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;
const int LOGN = __lg(MAXN) + 1;
const int INF = 1000000007;

void solve()
{
  int n, m;
  cin >> n >> m;
  vec<int> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];
  vec<pii> v(m);
  for (int i = 0; i < m; i++)
  {
    int f = a[i] / 100;
    v[i] = {f, a[i]};
  }
  sort(all(v), [](const pii &x, const pii &y)
       {
        if(x.fi!=y.fi) return x.fi<y.fi;
        return x.se<y.se; });
  vec<int> fl(m), id(m);
  for (int i = 0; i < m; i++)
  {
    fl[i] = v[i].fi;
    id[i] = v[i].se;
  }
  vec<ll> T(n);
  for (int i = 0; i < n; i++)
  {
    T[i] = llabs((ll)fl[i] - (ll)fl[m - 1 - i]);
  }
  vec<ll> P(n + 1, 0);
  for (int i = 1; i <= n; i++)
    P[i] = P[i - 1] + T[i - 1];
  ll best = -1;
  int bk = 0;
  for (int k = 0; k <= n; k++)
  {
    ll val = P[k] + P[n - k];
    if (val > best)
    {
      best = val;
      bk = k;
    }
  }
  int k = bk;
  vec<int> A(n), B(n);
  int cnt = 0;
  for (int i = 0; i < k; i++)
  {
    A[cnt++] = id[i];
  }
  for (int i = m - (n - k); i < m; i++)
  {
    A[cnt++] = id[i];
  }
  cnt = 0;
  for (int i = 0; i < n - k; i++)
  {
    B[cnt++] = id[i];
  }
  for (int i = m - k; i < m; i++)
  {
    B[cnt++] = id[i];
  }
  for (int i = 0; i < n; i++)
  {
    int ar = A[i];
    int br = B[n - 1 - i];
    for (int j = 0; j < 6; j++)
    {
      if (j % 2 == 0)
        cout << ar;
      else
        cout << br;
      if (j < 5)
        cout << ' ';
    }
    cout << endl;
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests;
  cin >> tests;
  for (int i = 0; i < tests; ++i)
    solve();
}