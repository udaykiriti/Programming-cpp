#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  long n, m; cin >> n >> m;
  string x, s; cin >> x >> s;
  int cnt = -1;
  FOR (p ,0,6)
  {
    if (x.find(s) != string::npos)
    {
      cnt = p;
      break;
    }
    x = x + x;
  }
  cout << cnt << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}