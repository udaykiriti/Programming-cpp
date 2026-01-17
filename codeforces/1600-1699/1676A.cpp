#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    string s; cin >> s;
    int sum1 = s[0] + s[1] + s[2];
    int sum2 = s[3] + s[4] + s[5];
    if (sum1 == sum2) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main()
{
  solve();
  return 0;
}