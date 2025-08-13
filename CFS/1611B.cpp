#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    ll a, b; cin >> a >> b;
    ll total = a + b;
    ll teams = min({a, b, total / 4});
    cout << teams << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}
