#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define pb push_back
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)

void solve()
{
  string s, ans;  
  FOR(i, 0, 8)
  {
    cin >> s;
    FOR(j, 0, 8)
    if (s[j] != '.')
      ans.pb(s[j]);
  }
  cout << ans << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}