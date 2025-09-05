#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; string b; cin >> n >> b;
  set<char> s(b.begin(), b.end());
  vector<char> r(s.begin(), s.end());
  sort(r.begin(), r.end());

  map<char, char> m;
  for (int i = 0, len = r.size(); i < len; ++i)
    m[r[i]] = r[len - 1 - i];

  for (char c : b) cout << m[c];
  cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}
