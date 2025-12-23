#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int x, y; cin >> x >> y;
  cout << min(x, y) << " " << max(x, y) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}