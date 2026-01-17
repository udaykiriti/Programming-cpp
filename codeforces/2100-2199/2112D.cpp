#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define all(x) x.begin(), x.end()
const int N = 1e5 + 5;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<vpi> a(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
      int u, v; cin >> u >> v;
      a[u].pb(mp(v, i));
      a[v].pb(mp(u, i));
    }
    int p = -1;
    for (int i = 1; i <= n; ++i)
      if (a[i].size() == 2)
      {
        p = i;
        break;
      }
    if (p == -1)
    {
      cout << "NO\n";
      continue;
    }

    int x = a[p][0].F, y = a[p][1].F;
    int ix = a[p][0].S, iy = a[p][1].S;
    vector<bool> v(n - 1);
    v[ix] = v[iy] = 1;
    vpi o;
    o.pb(mp(x, p)); o.pb(mp(p, y));

    stack<tuple<int, int, bool>> s;
    s.emplace(x, p, 1); s.emplace(y, p, 0);

    while (!s.empty())
    {
      auto [u, par, src] = s.top();
      s.pop();
      for (auto [w, id] : a[u])
      {
        if (v[id])
          continue;
        v[id] = 1;
        if (src)
          o.pb(mp(u, w)), s.emplace(w, u, 0);
        else
          o.pb(mp(w, u)), s.emplace(w, u, 1);
      }
    }

    cout << "YES\n";
    for (auto &[u, w] : o)
      cout << u << " " << w << "\n";
  }
}