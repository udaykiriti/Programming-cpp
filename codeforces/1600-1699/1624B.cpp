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
  int a, b, c, m; cin >> a >> b >> c;
  m = -1;
  if ((2 * b - c) % a == 0 && (2 * b - c) > 0) m = (2 * b - c) / a;
  else if ((a + c) % (2 * b) == 0) m = (a + c) / (2 * b);
  else if ((2 * b - a) % c == 0 && (2 * b - a) > 0) m = (2 * b - a) / c;
  if (m == -1) cout << "NO\n";
  else cout << "YES\n";
}

int main()
{
  FastIO();
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}