#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define GG return 0;

bool isCube(i64 num)
{
  i64 left = 1, right = 10007;
  while (left <= right)
  {
    i64 mid = (left + right) / 2;
    i64 cube = mid * mid * mid;
    if (cube == num)
      return true;
    else if (cube < num)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return false;
}

void solve()
{
  i64 x; cin >> x;
  bool ans = false;
  for (i64 p = 1; p * p * p <= x; p++)
  {
    i64 y = x - p * p * p;
    if (isCube(y))
    {
      ans = true;
      break;
    }
  }
  cout << (ans ? "YES" : "NO") << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  GG;
}