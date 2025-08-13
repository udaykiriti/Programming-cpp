#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t;  cin >> t;
  while (t--)
  {
    ll n; cin >> n;
    if ((n / 2) % 2 != 0)
    {
      cout << "NO" << endl;
      continue;
    }
    else
    {
      cout << "YES" << endl;
      for (ll i = 1; i <= n / 2; i++)
        cout << (2 * i) << " ";
      for (ll i = 1; i < n / 2; i++)
        cout << (2 * i - 1) << " ";
      cout << (n / 2 + n - 1) << endl;
    }
  }
}