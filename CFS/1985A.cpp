#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string a, b; cin >> a >> b;
  swap(a[0], b[0]);
  cout << a << " " << b << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}