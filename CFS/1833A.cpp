#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define FastIO             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define BYE return 0

void solve()
{
  int n; string s; cin >> n >> s;
  map<string, int> mp;
  for (int i = 0; i < n - 1; i++)
  {
    string t;
    t.push_back(s[i]);
    t.push_back(s[i + 1]);
    mp[t]++;
  }

  cout << (int)mp.size() << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
#endif
  FastIO;
  int t = 1; cin >> t;
  while (t--) solve();
  BYE;
}