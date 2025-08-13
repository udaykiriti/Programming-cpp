#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    ll n, k;  cin >> n >> k;
    ll full_blocks = (k - 1) / (n - 1);
    ll result = k + full_blocks;
    cout << result << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}