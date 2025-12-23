/* Problem: Cut Ribbon
Kirito has a ribbon of length `n`. He wants to cut the ribbon into pieces of lengths `a`, `b`, and `c` such that the total number of pieces is maximized. Each piece must have a positive length.

Input:
The first line contains four integers `n`, `a`, `b`, and `c` (1 ≤ n, a, b, c ≤ 4000) — the length of the ribbon and the lengths of the pieces.

Output:
Print a single integer — the maximum number of pieces that the ribbon can be cut into.

Example:
Input:
5 5 3 2
Output:
2

Input:
7 5 5 2
Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, a, b, c; cin >> n >> a >> b >> c;
  vector<int> dp(n + 1, -1);
  dp[0] = 0;

  for (int i = 0; i <= n; i++)
  {
    if (dp[i] != -1)
    {
      if (i + a <= n)
        dp[i + a] = max(dp[i + a], dp[i] + 1);
      if (i + b <= n)
        dp[i + b] = max(dp[i + b], dp[i] + 1);
      if (i + c <= n)
        dp[i + c] = max(dp[i + c], dp[i] + 1);
    }
  }
  cout << dp[n] << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(NULL);
  solve();
  return 0;
}