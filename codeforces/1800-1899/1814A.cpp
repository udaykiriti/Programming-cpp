#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll n, k; cin >> n >> k;
  ll y_limit = min(k, n / k + 1);
  for (ll y = 0; y <= y_limit; ++y)
  {
    ll rem = n - k * y;
    if (rem >= 0 && rem % 2 == 0)
    {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
