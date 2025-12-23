#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve()
{
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<int> distinct_count(n + 1, 0);
  unordered_set<int> seen;

  for (int i = n - 1; i >= 0; --i)
  {
    seen.insert(a[i]);
    distinct_count[i] = seen.size();
  }
  while (m--)
  {
    int li; cin >> li;
    cout << distinct_count[li - 1] << endl;
  }
}

int main()
{
  solve();
  return 0;
}