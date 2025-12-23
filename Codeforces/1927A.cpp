#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)

void solve()
{
  int n; string s; cin >> n >> s;

  int l = -1, r = -1;
  FOR(i, 0, n - 1)
  {
    if (s[i] == 'B')
    {
      if (l == -1)
        l = i;
      r = i;
    }
  }

  cout << (r - l + 1) << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}