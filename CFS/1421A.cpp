#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

void solve()
{
  ll a, b; ll d = 0; cin >> a >> b;
  d = a ^ b;
  cout << d << endl;
}

int main()
{
  FastIO();
  ll t; cin >> t;
  while (t--) solve();
  return 0;
}