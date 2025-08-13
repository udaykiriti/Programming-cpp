#include <bits/stdc++.h>
using namespace std;
#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define int long long
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define EXIT return 0

bool isPrime(int x)
{
  if (x < 2)
    return false;
  FOR(i, 2, sqrt(x))
    if (x % i == 0)
      return false;
  return true;
}

void solve()
{
  int d; cin >> d;
  int p1 = d + 1;
  while (!isPrime(p1))
    ++p1;

  int p2 = p1 + d;
  while (!isPrime(p2))
    ++p2;

  int result = min(p1 * p2, p1 * p1 * p1);
  cout << result << endl;
}

int32_t main()
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}