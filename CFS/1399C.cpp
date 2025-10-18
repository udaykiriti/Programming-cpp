/******************************
 *    author:  uday           *
 *    created: 18 11:56:39    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];

  int res = 0;

  for (int s = 2; s <= 2 * n; ++s)
  {
    vector<int> freq(n + 1, 0);
    for (int weight : w) freq[weight]++;
    int teams = 0;
    for (int i = 1; i <= n; ++i)
    {
      int j = s - i;
      if (j < 1 || j > n) continue;

      if (i == j)
      {
        teams += freq[i] / 2;
      }
      else
      {
        int pairs = min(freq[i], freq[j]);
        teams += pairs;
        freq[i] -= pairs;
        freq[j] -= pairs;
      }
    }
    res = max(res, teams);
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t(1),tcase(0); cin >> t;
  while (++tcase,t--) solve();
  return 0;
}