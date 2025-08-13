#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vp vector<pair<int, int>>
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define is(x) cout << ((x) ? "YES\n" : "NO\n");
#define THENGEY return
using namespace std;

void solve()
{
  int n, s, m; cin >> n >> s >> m;
  vector<pair<int, int>> intervals(n);
  for (auto &i : intervals)
    cin >> i.first >> i.second;

  bool can = false;

  if (intervals[0].first >= s)
    can = true;

  for (int i = 1; i < n; ++i)
    if (intervals[i].first - intervals[i - 1].second >= s)
      can = true;

  if (m - intervals[n - 1].second >= s)
    can = true;

  is(can)
      THENGEY;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t;
  while (t--) solve();
  return 0;
}