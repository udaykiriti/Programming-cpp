#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s; cin >> s;
  int n = s.size();
  vector<int> prefix(n, 0);
  for (int i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + (s[i] == s[i - 1]);
  int m;  cin >> m;
  while (m--)
  {
    int l, r; cin >> l >> r;
    cout << prefix[r - 1] - prefix[l - 1] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}