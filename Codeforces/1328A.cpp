#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b; cin >> a >> b;
  int remainder = a % b;
  if (remainder == 0) cout << 0 << endl;
  else cout << b - remainder << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}