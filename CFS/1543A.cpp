#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;
#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

void solve()
{
  ll a, b;
  cin >> a >> b;
  ll diff = (a >= b) ? (a - b) : (b - a);
  if (a > b)
    cout << diff << " " << min(diff - (a % diff), b % diff) << endl;
  else if (b > a)
    cout << diff << " " << min(diff - (b % diff), a % diff) << endl;
  else
    cout << 0 << " " << 0 << endl;
}

int main()
{
  FastIO int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}