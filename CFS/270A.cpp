#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a; cin >> a;
  if (360 % (180 - a) == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}