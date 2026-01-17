#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;
  vector<int> candidates = {
      a1 + a2,
      a4 - a2,
      a5 - a4};

  int max_fib = 0;
  for (int a3 : candidates)
  {
    int cnt = 0;
    if (a3 == a1 + a2)
      cnt++;
    if (a4 == a2 + a3)
      cnt++;
    if (a5 == a3 + a4)
      cnt++;
    max_fib = max(max_fib, cnt);
  }

  cout << max_fib << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}