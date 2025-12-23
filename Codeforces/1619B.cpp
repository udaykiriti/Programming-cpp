#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
  int n, a, b, c; cin >> n;
  a = sqrt(n);
  b = cbrt(n);
  c = sqrt(cbrt(n));
  cout << a + b - c << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}