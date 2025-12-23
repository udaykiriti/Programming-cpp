#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
  int n, m, pairs = 0; cin >> n;
  int a[n];
  FOR(i, 0, n) cin >> a[i];
  cin >> m; int b[m];
  FOR(i, 0, m) cin >> b[i];

  sort(a, a + n); sort(b, b + m);
  FOR(i, 0, n)
  {
    FOR(j, 0, m)
    {
      if (abs(a[i] - b[j]) < 2)
      {
        b[j] = 1000;
        pairs++;
        break;
      }
    }
  }

  cout << pairs << endl;
  return 0;
}