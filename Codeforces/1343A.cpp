#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll arr[32];
  FOR(i, 0, 32) arr[i] = (1LL << (i + 1)) - 1;

  ll t;
  cin >> t;
  while (t--)
  {
    ll n; cin >> n;
    FOR(i, 1, 32)
    if (n % arr[i] == 0)
    {
      cout << n / arr[i] << endl;
      break;
    }
  }
}