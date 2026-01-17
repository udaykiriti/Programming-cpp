#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string s1, s2; cin >> s1 >> s2;
  if (s1.size() != s2.size()) cout << max(s1.size(), s2.size()) << endl;
  else if (s1 == s2) cout << -1 << endl;
  else cout << s1.size() << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}