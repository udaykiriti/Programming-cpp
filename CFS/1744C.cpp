#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define TESTCASES() \
  ll t;             \
  cin >> t;         \
  while (t--)
#define READ(type, var) \
  type var;             \
  cin >> var
#define READSTR(s) \
  string s;        \
  cin >> s
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PRINT(x) cout << x << '\n'

int main()
{
  FASTIO();
  TESTCASES()
  {
    READ(ll, n);READ(char, c);READSTR(s);
    s += s;
    vector<ll> g_pos;

    for (ll i = 0; i < s.size(); ++i)
      if (s[i] == 'g')
        g_pos.push_back(i);
    ll ans = 0;

    for (ll i = 0; i < n; ++i)
    {
      if (s[i] == c)
      {
        auto it = lower_bound(g_pos.begin(), g_pos.end(), i);
        if (it != g_pos.end()) ans = MAX(ans, *it - i);
      }
    }
    PRINT(ans);
  }
  return 0;
}