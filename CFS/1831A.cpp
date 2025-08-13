#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(x) cin >> x

void solve()
{
  ll n; input(n);
  FOR(i, 1, n)
  {
    ll temp; input(temp);
    cout << (n + 1) - temp << " ";
  }
  cout << endl;
}

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
}

int main()
{
  FastIO();
  ll T; input(T);
  while (T--) solve();
  return 0;
}