#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define FOR(i, a, b)  for (int i = a; i < b; i++)
void solve()
{
  int n, k, q; cin >> n >> k >> q;
  int t[n];
  int pd = 0; ll ans = 0;
  FOR(i, 0, n)
  {
    cin >> t[i];
    if (t[i] <= q)
      pd++;
    else
      pd = 0;
    ans += max(0, pd - k + 1);
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
}