#include <bits/stdc++.h>
using namespace std;
#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define PRINT(x) cout << x << endl

void solve()
{
  string n; cin >> n;
  if ((n.back() - '0') % 2 == 0)
  {
    PRINT(0);
    return;
  }
  if ((n[0] - '0') % 2 == 0)
  {
    PRINT(1);
    return;
  }
  for (int i = 1; i < sz(n) - 1; i++)
  {
    if ((n[i] - '0') % 2 == 0)
    {
      PRINT(2);
      return;
    }
  }
  PRINT(-1);
}

// Main function
int32_t main()
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}