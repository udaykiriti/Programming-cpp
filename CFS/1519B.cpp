#include <bits/stdc++.h>
using namespace std;
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
