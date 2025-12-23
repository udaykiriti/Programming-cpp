#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll n; cin >> n;
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  auto minmax = minmax_element(b.begin(), b.end());
  ll diff = *minmax.second - *minmax.first;

  if (diff == 0)
  {
    ll cnt = n;
    cout << 0 << " " << cnt * (cnt - 1) / 2 << '\n';
    return;
  }
  ll cnt_min = count(b.begin(), b.end(), *minmax.first);
  ll cnt_max = count(b.begin(), b.end(), *minmax.second);
  cout << diff << " " << cnt_min * cnt_max << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  solve();
  return 0;
}
