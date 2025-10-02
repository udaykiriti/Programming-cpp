#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string res = "";
  for (int i = 0; i < 100; i++) res += "Yes";
  string s; cin >> s;
  if (res.find(s) != string::npos) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
