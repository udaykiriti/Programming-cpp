#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main()
{
  long t; cin >> t;
  while (t--)
  {
    int n, k; cin>>n>>k;
    int md = 0, even = 0;
    bool div = false;
    FOR(p, 0, n)
    {
      int x; cin>>x;
      x %= k;
      if (x) md = max(md, x);
      else div = true;
      if (x == 2) ++even;
    }

    if (div)
    {
      cout<<0<<endl;
    }
    else if (k == 4)
    {
      if (even >= 2) cout<<0<<endl;
      else if (even >= 1 || md == 3) cout<<1<<endl;
      else cout<<2<<endl;
    }
    else
    {
      cout<<k-md<<endl;
    }
  }
  return 0;
}