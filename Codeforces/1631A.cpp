#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  for (int i = 0; i < n; ++i)
    if (a[i] > b[i])
      swap(a[i], b[i]);
  int max_a = *max_element(a.begin(), a.end());
  int max_b = *max_element(b.begin(), b.end());
  cout << max_a * max_b << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}