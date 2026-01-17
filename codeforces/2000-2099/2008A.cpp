#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    ll a, b; cin >> a >> b;
    cout << (((a % 2) || (b % 2 && a < 2)) ? "NO" : "YES") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}