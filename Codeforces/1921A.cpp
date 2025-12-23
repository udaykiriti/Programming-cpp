#include <bits/stdc++.h>
using namespace std;

void solve()
{
    set<int> x, y;
    for (int i = 0; i < 4; ++i)
    {
      int xi, yi;
      cin >> xi >> yi;
      x.insert(xi);
      y.insert(yi);
    }
    int side = max(*x.rbegin() - *x.begin(), *y.rbegin() - *y.begin());
    cout << side * side << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}