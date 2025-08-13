#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i)
    cin >> w[i];

  int max_teams = 0;

  for (int s = 2; s <= 2 * n; ++s)
  {
    vector<int> freq(n + 1, 0);
    for (int weight : w)
      freq[weight]++;
    int teams = 0;
    for (int i = 1; i <= n; ++i)
    {
      int j = s - i;
      if (j < 1 || j > n)
        continue;

      if (i == j)
      {
        teams += freq[i] / 2;
      }
      else
      {
        int pair_count = min(freq[i], freq[j]);
        teams += pair_count;
        freq[i] -= pair_count;
        freq[j] -= pair_count;
      }
    }
    max_teams = max(max_teams, teams);
  }
  cout << max_teams << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}