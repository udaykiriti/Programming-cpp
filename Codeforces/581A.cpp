#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b; cin >> a >> b;
  int diff = min(a, b);
  int same = (max(a, b) - diff) / 2;
  cout << diff << " " << same << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  solve();
  return 0;
}
