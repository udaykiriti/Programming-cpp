#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string matches = "codeforces";
  string s; cin >> s;
  int count = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != matches[i])
      count++;
  cout << count << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}