#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll    long long

void solve()
{

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;

  ll l = 0, r = 2e9 + 10, ans = 0;
  while (r > l + 1)
  {
    ll mid = (l + r) / 2;
    ll cost = 0;
    for (auto height : a){
      if (height < mid)
        cost += mid - height;
    }
    if (cost > x){
      r = mid;
    }
    else{
      ans = mid;
      l = mid;
    }
  }
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
}