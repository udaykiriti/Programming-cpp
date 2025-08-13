#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i < b; i++)

int main()
{
  ll t; cin>>t;
  while (t--)
  {
    ll n; cin>>n;
    bool one = false;
    int s = 0;

    FOR(p, 0, n)
    {
      int x; cin>>x;
      if (x % 3 == 1)
        one = true;
      s += x;
      s %= 3;
    }

    if (!one && s % 3 == 1)
      cout<<2<<endl;
    else if (s % 3)
      cout<<1<<endl;
    else
      cout<<0<<endl;
  }
  return 0;
}