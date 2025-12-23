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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  FOR(i, 0, n - 1)
      cin >> a[i];
  sort(a.begin(), a.end());
  int maxLen = 1, currLen = 1;

  FOR(i, 1, n - 1)
  {
    if (a[i] - a[i - 1] <= k)
    {
      currLen++;
    }
    else
    {
      maxLen = max(maxLen, currLen);
      currLen = 1;
    }
  }
  maxLen = max(maxLen, currLen);
  cout << n - maxLen << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}