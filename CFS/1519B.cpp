// Problem: 1519B - The Cake Is a Lie
// Link: https://codeforces.com/contest/1519/problem/B

#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define ll long long

void solve()
{
  int n, m, k; cin >> n >> m >> k;
  if (k == (n - 1) + (m - 1) * n)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  fastio;
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}