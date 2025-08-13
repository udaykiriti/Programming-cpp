#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k; cin >> n >> k;
  if (n >= k && (n - k) % 2 == 0)
  {
    cout << "YES\n";
    for (int i = 0; i < k - 1; i++)
      cout << "1 ";
    cout << n - k + 1 << "\n";
  }
  else if (n >= 2 * k && (n - 2 * k) % 2 == 0)
  {
    cout << "YES\n";
    for (int i = 0; i < k - 1; i++)
      cout << "2 ";
    cout << n - 2 * (k - 1) << "\n";
  }
  else
  {
    cout << "NO\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}