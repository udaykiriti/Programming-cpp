#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  vector<int> prefix_odd(n + 1, 0);
  for (int i = 1; i <= n; i++) 
    prefix_odd[i] = prefix_odd[i - 1] + (a[i - 1] % 2);
  while (q--)
  {
    int l, r, k; cin >> l >> r >> k;
    int odd_count = prefix_odd[r] - prefix_odd[l - 1];
    if (k % 2 == 0)
    {
      if ((prefix_odd[n] - odd_count) % 2 == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    else
    {
      int new_odd_count = odd_count - (r - l + 1);
      if ((prefix_odd[n] - odd_count + (r - l + 1)) % 2 == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}