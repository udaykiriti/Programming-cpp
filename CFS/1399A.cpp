#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());
  bool possible = true;
  for (int i = 1; i < n; ++i)
  {
    if (a[i] - a[i - 1] > 1)
    {
      possible = false;
      break;
    }
  }
  if (possible)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}