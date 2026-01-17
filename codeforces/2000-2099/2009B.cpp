#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  int n; cin >> n;
  vector<string> grid(n);
  FOR(i, 0, n - 1) 
    cin >> grid[i];

  RFOR(i, n - 1, 0)
  {
    FOR(j, 0, 3)
    {
      if (grid[i][j] == '#')
      {
        cout << (j + 1) << " ";
        break;
      }
    }
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}