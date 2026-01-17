#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << (x) << endl
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve()
{
  int n; cin >> n;
  vector<int> v(n);
  FOR(i, 0, n) cin >> v[i];
  sort(all(v));
  int g = v[n - 1], s = v[n - 2];
  ll a = 0;

  FOR(k, 2, n)
  {
    ll t = 2LL * v[k];
    ll m = (k == n - 1 ? s : g);
    ll x = max(t, m) - v[k];
    int l = 0, r = k - 1;

    while (l < r)
      if (v[l] + v[r] > x)
        a += (r - l), --r;
      else
        ++l;
  }
  cout << a << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
}