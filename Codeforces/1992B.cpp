#include <bits/stdc++.h>
using namespace std;
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define endl '\n'
using i64 = long long;

void solve()
{
  i64 n, k; cin >> n >> k;
  i64 total = 0, mx = 0;
  for (i64 p = 0; p < k; p++)
  {
    i64 x; cin >> x;
    mx = max(mx, x);
    total += (2 * x - 1);
  }
  total -= (2 * mx - 1);
  cout << total << endl;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}