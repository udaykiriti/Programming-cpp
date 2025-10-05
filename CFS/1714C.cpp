#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
  int s; cin >> s;
  string str = "";
  for (int i = 9; i >= 1; i--)
  {
    if (s >= i)
    {
      str = char(i + '0') + str;
      s -= i;
    }
  }
  cout << str << endl;
}

int32_t main()
{
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr);
  ll t; cin >> t;
  while (t--) solve();
  return 0;
}
