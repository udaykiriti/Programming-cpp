#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int t; cin >> t;
    ll n; cin >> n;
    if (n % 2050 != 0)
    {
      cout << -1 << '\n';
      return;
    }
    ll quotient = n / 2050;
    int sum = 0;
    while (quotient > 0)
    {
      sum += quotient % 10;
      quotient /= 10;
    }
    cout << sum << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}