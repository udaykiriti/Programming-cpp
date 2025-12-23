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

bool isPerfectSquare(long long x)
{
  long long root = sqrt(x);
  return root * root == x;
}

void solve()
{
  int n; cin >> n;
  long long total = 0;
  FOR(i, 0, n - 1)
  {
    int val; cin >> val;
    total += val;
  }

  if (isPerfectSquare(total)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}