#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln '\n'

void solve() {
  i64 n; string s; cin >> n >> s;
  i64 cnt = 0, idx = 0;
  while ((idx = s.find("mapie", idx)) != string::npos) {
    ++cnt; s[idx + 2] = '$'; ++idx;
  }

  idx = 0;
  while ((idx = s.find("map", idx)) != string::npos) {
    ++cnt; s[idx + 1] = '$'; ++idx;
  }

  idx = 0;
  while ((idx = s.find("pie", idx)) != string::npos) {
    ++cnt; s[idx + 1] = '$'; idx += 2;
  }
  cout << cnt << ln;
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
