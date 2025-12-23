#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
  ll x, y, n; cin >> x >> y >> n;
  ll m = (n - y) / x;
  ll k = m * x + y;
  cout << k << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}