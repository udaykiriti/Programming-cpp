#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)

void solve()
{
  i64 a, b; cin >> a >> b;
  i64 dist = b - a;
  i64 left = 1, right = dist + 7, res = 1;

  while (left <= right)
  {
    i64 mid = (left + right) / 2;
    i64 tst = mid * (mid - 1) / 2;

    if (tst <= dist)
    {
      res = mid;
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  cout << res << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}