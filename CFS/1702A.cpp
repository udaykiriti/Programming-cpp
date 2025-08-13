#include <bits/stdc++.h>
using namespace std;

#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
#define multicase \
  int t;          \
  cin >> t;       \
  while (t--)

using i64 = long long;
#define GG return 0;

void solve()
{
  i64 m; cin >> m;
  i64 digits = log10(m);
  i64 power = pow(10, digits);
  cout << (m - power) << ln;
}

int main()
{
  stop_sync;
  untie_ios;
  multicase
  {
    solve();
  }
  GG
}