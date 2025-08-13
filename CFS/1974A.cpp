#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve()
{
  long x, y; cin>>x>>y;
  long screens = (y + 1) / 2;
  x -= (15 * screens - 4 * y);
  x = max(x, 0L);
  screens += (x + 14) / 15;
  cout<<(screens);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}