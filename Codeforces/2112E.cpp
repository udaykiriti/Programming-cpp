#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define debug(x) cout << (x) << endl
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
const int I = 1e9;

int main()
{
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t; cin >> t;
  vi q(t), a;
  a.reserve(t);
  int m = 0;
  FOR(i, 0, t)
      cin >> q[i],
      m = max(m, q[i]);

  int k = m + 2;
  vvi d(m + 1);
  FORE(i, 3, m)
  for (int j = i; j <= m; j += i)
    d[j].pb(i);

  vi f(m + 1, I), s(k + 1, I);
  f[1] = 0;
  if (m >= 2)
    f[2] = I;

  FORE(i, 3, k)
  {
    s[i] = 1 + f[i - 2];
    if (i > m)
      break;
    f[i] = s[i];
    for (int j : d[i])
    {
      int x = i / j;
      if (f[x] < I)
        f[i] = min(f[i], f[x] + s[j]);
    }
  }
  for (int i : q)
    cout << (i == 1 ? 1 : (f[i] >= I ? -1 : 1 + f[i])) << endl;
}