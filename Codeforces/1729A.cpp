#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  long a, b, c; cin >> a >> b >> c;
  long time1 = abs(a - 1);
  long time2 = abs(b - c) + abs(c - 1);
  if (time1 < time2) cout << 1 << endl;
  else if (time2 < time1) cout << 2 << endl;
  else cout << 3 << endl;
}

int main()
{
  FastIO();
  int t ;cin >> t;
  while (t--) solve();
  return 0;
}