#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
  ll n; cin >> n;
  ll a = -1, b = -1, c = -1;
  for (ll i = 2; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      a = i;
      break;
    }
  }
  if (a == -1)
  {
    cout << "NO" << endl;
    return;
  }

  ll remaining = n / a;
  for (ll j = a + 1; j * j <= remaining; ++j)
  {
    if (remaining % j == 0)
    {
      b = j;
      c = remaining / j;
      if (b != c && c > b)
      {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}