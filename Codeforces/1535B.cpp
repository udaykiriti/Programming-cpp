#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  ll n, ans = 0; cin >> n;

  vector<ll> odds, evens, a;
  for (ll i = 0; i < n; ++i){
    ll x; cin >> x;
    if (x % 2 == 0) evens.push_back(x);
    else odds.push_back(x);
  }

  a = evens;
  a.insert(a.end(), odds.begin(), odds.end());

  for (size_t i = 0; i < a.size(); ++i)
    for (size_t j = i + 1; j < a.size(); ++j)
      if (__gcd(a[i], 2 * a[j]) > 1)
        ++ans;
  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll t; cin >> t;
  while (t--) solve();
  return 0;
}
