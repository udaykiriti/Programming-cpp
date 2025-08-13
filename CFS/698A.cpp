#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FOR_REV(i, a, b) for (ll i = a; i >= b; i--)
#define MIN3(a, b, c) min(a, min(b, c))
#define PRINT(x) cout << x << endl

int main()
{
  ll n; cin >> n; ll a[n];
  FOR(i, 0, n)
    cin >> a[i];

  ll dp[n + 1][3];
  FOR(i, 0, n + 1)
  {
    dp[i][0] = INT_MAX;
    dp[i][1] = INT_MAX;
    dp[i][2] = INT_MAX;
  }
  dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
  FOR(i, 1, n + 1)
  {
    dp[i][0] = 1 + MIN3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);

    if (a[i - 1] == 1 || a[i - 1] == 3)
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    if (a[i - 1] == 2 || a[i - 1] == 3)
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
  }
  PRINT(MIN3(dp[n][0], dp[n][1], dp[n][2]));
  return 0;
}