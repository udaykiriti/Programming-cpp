// Jellyfish and Undertale
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FASTIO             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
  int a, b, n, x; cin>>a>>b>>n;
  int sum = b;
  FOR(i, 0, n)
  {
    cin>>x;
    sum += min(x, a - 1);
  }
  cout << sum << endl;
}

int32_t main(void)
{
  FASTIO;
  int t; cin>>t;
  while (t--) solve();
  return 0;
}