#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll   long long

void solve()
{
  ll n, k; cin >> n >> k;
  ll minSum = k * k;
  if (n >= minSum && (n - minSum) % 2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
}