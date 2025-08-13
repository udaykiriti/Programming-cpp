#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl
#define endl '\n'
#define BYE__ return 0

void solve()
{
  int n, m; cin >> n >> m;
  int steps = 0;
  while (m > n)
  {
    if (m % 2 == 0)
      m /= 2;
    else
      m += 1;
    steps++;
  }
  steps += (n - m);
  debug(steps);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(nullptr);
  solve();
  BYE__;
}