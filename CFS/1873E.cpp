#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0

void FastIO()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void solve()
{

  long long n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &i : a)
    cin >> i;

  long long l = 0, r = 2e9 + 10, ans = 0;
  while (r > l + 1)
  {
    long long mid = (l + r) / 2;
    long long cost = 0;
    for (auto height : a)
    {
      if (height < mid)
        cost += mid - height;
    }
    if (cost > x)
    {
      r = mid;
    }
    else
    {
      ans = mid;
      l = mid;
    }
  }
  cout << ans << '\n';
}

int main()
{
  FastIO();
  int t;
  cin >> t;
  while (t--)
    solve();
  EXIT;
}
