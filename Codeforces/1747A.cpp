#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    ll pos_sum = 0, neg_sum = 0;
    for (int i = 0; i < n; ++i)
    {
      ll x; cin >> x;
      if (x >= 0) pos_sum += x;
      else neg_sum += x;
    }
    cout << abs(pos_sum - abs(neg_sum)) << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}