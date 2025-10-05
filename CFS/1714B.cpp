#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, i; cin >> n;
  int a[n];
  map<int, int> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = n - 1; i >= 0; i--)
  {
    if (m[a[i]] > 0) break;
    else m[a[i]]++;
  }
  cout << i + 1 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}