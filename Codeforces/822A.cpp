#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll a, b; cin >> a >> b;
  ll A = 1;
  for (ll i = 2; i <= min(a, b); i++)
    A *= i;
  cout<<A<<endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}