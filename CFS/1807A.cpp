#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int a, b, c; cin >> a >> b >> c;
  if (a + b == c)
    cout << "+" << endl;
  else
    cout << "-" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}