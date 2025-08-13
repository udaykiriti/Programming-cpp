#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    int x; cin >> x;
    vector<int> doors(4);
    for (int i = 1; i <= 3; ++i) cin >> doors[i];
    int first = x;
    int second = doors[first];
    if (first != 0 && second != 0 && doors[second] != 0) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}