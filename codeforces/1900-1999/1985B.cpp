#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void solve()
{
  int n; cin >> n;
  int maxSum = 0, bestX = 2;
  FOR(x, 2, n + 1)
  {
    int k = n / x;
    int sum = x * k * (k + 1) / 2;
    if (sum > maxSum)
      maxSum = sum, bestX = x;
  }
  cout << bestX << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}