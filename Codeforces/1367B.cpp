#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    int x;
    int evcnt = 0, oddcnt = 0;
    FOR (i,0,n)
    {
      cin >> x;
      if (x % 2 == 0 && i % 2 != 0) evcnt++;
      if (x % 2 != 0 && i % 2 == 0) oddcnt++;
    }
    if (evcnt == oddcnt)
    {
      cout << evcnt << endl;
      continue;
    }
    cout << -1 << endl;
  }
}