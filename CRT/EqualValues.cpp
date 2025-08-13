#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int64_t ans = LLONG_MAX;
  int i = 0;
  while (i < n)
  {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[i])
      j++;
    int64_t v = a[i];
    int64_t cost = v * (int64_t(i) + (int64_t)(n - 1 - j));
    ans = min(ans, cost);
    i = j + 1;
  }
  cout << ans << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
