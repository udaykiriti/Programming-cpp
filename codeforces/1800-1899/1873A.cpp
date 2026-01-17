#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s; cin >> s;
  if (s == "abc")
  {
    cout << "YES" << endl;
  }
  else
  {
    int mismatches = 0;
    for (int i = 0; i < 3; i++)
    {
      if (s[i] != "abc"[i])
        mismatches++;
    }
    if (mismatches == 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}