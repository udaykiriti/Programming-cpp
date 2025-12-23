#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  ll operations = 0;
  for (ll i = 0; i < n; i++)
  {
    if (s[i] == 'B')
    {
      operations++;
      i += k - 1;
    }
  }
  cout << operations << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t = 1; cin >> t;
  while (t--) solve();
}