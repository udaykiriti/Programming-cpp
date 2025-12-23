#include <bits/stdc++.h>
using namespace std;
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
using i64 = long long;

void solve()
{
  i64 n, k; cin >> n >> k;
  i64 min_packages = n;
  for (i64 i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      if (i <= k) min_packages = min(min_packages, n / i);
      if (n / i <= k) min_packages = min(min_packages, i);
    }
  }
  cout << min_packages << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}