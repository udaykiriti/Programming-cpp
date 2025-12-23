#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define debug(x) cout << (x) << endl
#define FOR(i, a, b) for (int i = a; i < b; i++)
const int I = 1e9;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<int> a(n);
    FOR ( i, 0, n)
      cin >> a[i];

    if (n < 2)
    {
      cout << -1 << '\n';
      continue;
    }

    bool b = false;
    FOR (i,0, n - 1)
      if (abs(a[i] - a[i + 1]) <= 1)
      {
        b = true;
        break;
      }

    if (b)
    {
      cout << 0 << '\n';
      continue;
    }

    int m = I;
    FOR ( j , 0, n - 1)
    {
      vector<int> r(n, I), R(n, -I);
      if (j + 1 < n)
      {
        r[j + 1] = a[j + 1];
        R[j + 1] = a[j + 1];
        for (int k = j + 2; k < n; ++k)
          r[k] = min(r[k - 1], a[k]), R[k] = max(R[k - 1], a[k]);
      }

      int l = a[j], L = a[j], x = n - 1, y = n - 1;
      for (int i = j; i >= 0; --i)
      {
        l = min(l, a[i]), L = max(L, a[i]);
        while (x > j + 1 && R[x - 1] >= l - 1)
          --x;
        while (y > j + 1 && r[y - 1] <= L + 1)
          --y;

        int u = n, v = n;
        if (x >= j + 1 && R[x] >= l - 1)
          u = x;
        if (y >= j + 1 && r[y] <= L + 1)
          v = y;

        int k = max(u, v);
        if (k < n)
          m = min(m, (j - i) + (k - (j + 1)));
      }
    }

    cout << (m == I ? -1 : m) << '\n';
  }
}