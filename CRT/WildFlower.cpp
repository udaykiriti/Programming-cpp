#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int add(int a, int b)
{
  a += b;
  return a >= MOD ? a - MOD : a;
}
int mul(long long a, long long b) { return (int)(a * b % MOD); }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  int Nmax = 200000;
  vector<int> p2(Nmax + 5);
  p2[0] = 1;
  for (int i = 1; i <= Nmax; i++)
    p2[i] = add(p2[i - 1], p2[i - 1]);
  while (T--)
  {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1), c(n + 1);
    for (int i = 1, u, v; i < n; i++)
    {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> par(n + 1), dep(n + 1);
    queue<int> q;
    q.push(1);
    par[1] = 0;
    dep[1] = 0;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (int v : g[u])
      {
        if (v == par[u])
          continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        c[u].push_back(v);
        q.push(v);
      }
    }
    int leaf = 0;
    for (int i = 1; i <= n; i++)
    {
      if (c[i].empty())
        leaf++;
    }
    if (leaf > 2)
    {
      cout << 0 << "\n";
      continue;
    }
    if (leaf == 1)
    {
      cout << p2[n] << "\n";
      continue;
    }
    int u = 1;
    for (int i = 1; i <= n; i++)
      if ((int)c[i].size() == 2)
      {
        u = i;
        break;
      }
    int k = 0, l = 0;
    int x = c[u][0];
    while (true)
    {
      k++;
      if (c[x].size() == 1)
        x = c[x][0];
      else
        break;
    }
    x = c[u][1];
    while (true)
    {
      l++;
      if (c[x].size() == 1)
        x = c[x][0];
      else
        break;
    }
    int P = dep[u] + 1;
    int d = abs(k - l);
    int gkl;
    if (d == 0)
      gkl = 2;
    else
      gkl = mul(3, p2[d - 1]);
    int ans = mul(p2[P], gkl);
    cout << ans << "\n";
  }
  return 0;
}
// f