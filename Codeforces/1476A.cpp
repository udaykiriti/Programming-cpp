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
#define ll long long

void solve()
{
  long long int n, k, r; cin >> n >> k;
  if (n % k == 0)
    cout << "1" << endl;
  else if (k % n == 0)
    cout << k / n << endl;
  else if (n > k)
    cout << "2" << endl;
  else
    cout << (k / n) + 1 << endl;
}

int main()
{
  FastIO();
  ll int t; cin >> t;
  while (t--) solve();
  return 0;
}