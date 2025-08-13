#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string repeated_yes = "";
  for (int i = 0; i < 100; i++) repeated_yes += "Yes";
  string s; cin >> s;
  if (repeated_yes.find(s) != string::npos) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}