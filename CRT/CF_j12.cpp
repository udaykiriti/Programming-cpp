#include <cstdio>
#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;
using ll = long long;

int main()
{
  int t;
  scanf("%d", &t);

  while (t--)
  {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<ll> p(n);
    vector<int> d(n);

    FOR(i, n)
    scanf("%lld", &p[i]);
    FOR(i, n)
    scanf("%d", &d[i]);

    int q;
    scanf("%d", &q);

    while (q--)
    {
      ll x;
      scanf("%lld", &x);

      int dir = 1;
      ll tm = 0;
      set<pair<int, int>> vis;

      int ii = int(lower_bound(ALL(p), x) - p.begin());
      if (ii < n && p[ii] == x && tm % k == d[ii])
      {
        dir = -dir;
        vis.insert({ii, dir});
      }

      bool ok = false;

      while (true)
      {
        int j;
        if (dir == 1)
        {
          j = int(upper_bound(ALL(p), x) - p.begin());
          if (j >= n)
          {
            ok = true;
            break;
          }
        }
        else
        {
          j = int(lower_bound(ALL(p), x) - p.begin()) - 1;
          if (j < 0)
          {
            ok = true;
            break;
          }
        }

        tm += llabs(p[j] - x);
        x = p[j];

        if (tm % k == d[j])
        {
          dir = -dir;
          if (!vis.insert({j, dir}).second)
            break;
        }
      }

      ok ? YES : NO;
    }
  }

  return 0;
}
