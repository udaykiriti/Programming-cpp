#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll n; cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll sum = 0;
  ll curr = a[0];
  for (ll i = 1; i < n; ++i)
  {
    if ((a[i] > 0 && curr > 0) || (a[i] < 0 && curr < 0))
    {
      curr = max(curr, a[i]);
    }
    else
    {
      sum += curr;
      curr = a[i];
    }
  }

  sum += curr;
  cout << sum << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}