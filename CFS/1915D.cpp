#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define isVowel(c) ((c) == 'a' || (c) == 'e')
#define REVERSE(s) reverse(s.begin(), s.end())
#define FOR(i, a, b) for (int i = a; i < b; ++i)

void solve()
{
  ll n; string s, ans = ""; cin >> n >> s;
  REVERSE(s);
  FOR(i, 0, n)
  {
    if (!isVowel(s[i]) && isVowel(s[i + 1]) && !isVowel(s[i + 2]))
    {
      ans += s[i];
      ans += s[i + 1];
      ans += s[i + 2];
      ans += '.';
      i += 2;
    }
    else
    {
      ans += s[i];
      ans += s[i + 1];
      ans += '.';
      i += 1;
    }
  }

  REVERSE(ans);
  ans.erase(ans.begin());
  cout << ans << nl;
}

int main()
{
  FAST_IO;
  int T = 1; cin >> T;
  while (T--) solve();
  return 0;
}