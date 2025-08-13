#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  int size = n * (n - 1) / 2;
  vector<int> b(size);
  for (int i = 0; i < size; ++i)
    cin >> b[i];
  sort(b.begin(), b.end());
  vector<int> a;
  for (int i = 1, idx = 0; i < n; ++i)
  {
    a.push_back(b[idx]);
    idx += n - i;
  }
  a.push_back(1000000000);
  for (int x : a)
    cout << x << ' ';
  cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}