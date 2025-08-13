#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

void solve()
{
  int n, m;  cin >> n >> m;
  string a; cin >> a;
  vector<int> freq(7, 0);
  for (char ch : a) freq[ch - 'A']++;
  int to_create = 0;
  FOR(i, 0, 6)
    if (freq[i] < m)
      to_create += m - freq[i];
  cout << to_create << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}