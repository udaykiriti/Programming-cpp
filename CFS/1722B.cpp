#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  string row1, row2; cin >> row1 >> row2;
  FOR(i, 0, n)
  if ((row1[i] == 'G' || row1[i] == 'B') && (row2[i] == 'G' || row2[i] == 'B'))
  {
    row1[i] = 'G';
    row2[i] = 'G';
  }
  if (row1 == row2) cout << "YES\n";
  else cout << "NO\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}