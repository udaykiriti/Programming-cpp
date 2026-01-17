#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  int ans = 0;
  int bills[] = {100, 20, 10, 5, 1};
  for (int bill : bills)
  {
    ans += n / bill;
    n %= bill;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(NULL);
  solve();
  return 0;
}
