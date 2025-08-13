#include <bits/stdc++.h>
using namespace std;

#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

#define FOR(i, start, end) for (ll i = start; i <= end; ++i)

using ll = long long int;

ll aarray[1000005];

void solve()
{
  ll n, sum = 0, ans = 0;
  cin >> n;

  FOR(i, 1, n)
  {
    ll x;
    cin >> x;
    aarray[i] = x;
    sum += x;
  }

  if (sum % n != 0)
  {
    cout << -1 << "\n";
    return;
  }

  ll eq = sum / n;

  FOR(i, 1, n)
  {
    if (aarray[i] > eq)
      ans++;
  }

  cout << ans << "\n";
}

int main()
{
  FastIO
      ll t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
