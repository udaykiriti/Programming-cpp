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

typedef long long ll;

void solve()
{
  ll n, k, x; cin >> n >> k >> x;
  ll mn = k * (k + 1) / 2;
  ll mx = n * k - k * (k - 1) / 2;

  if (mn <= x && x <= mx)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}