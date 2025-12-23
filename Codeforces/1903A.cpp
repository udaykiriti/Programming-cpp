#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) cin >> v[i];
  if (is_sorted(v.begin(), v.end())) {
    cout << "YES\n";
    return;
  }
  if (k == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) solve(); 
  return 0;
}