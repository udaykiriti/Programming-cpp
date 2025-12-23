#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string b; cin >> b;
  string a;
  a += b[0];
  for (int i = 1; i < b.size(); i += 2) a += b[i];
  cout << a << "\n";

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}