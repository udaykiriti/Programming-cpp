#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

void solve()
{
  string s; cin >> s;
  int countA = 0, countB = 0;
  FOR(i, 0, s.size())
  {
    if (s[i] == 'A') countA++;
    else if (s[i] == 'B') countB++;
  }

  if (countA > countB) cout << "A" << endl;
  else cout << "B" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}