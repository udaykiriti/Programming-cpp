#include <bits/stdc++.h>  
using namespace std;

void solve()
{
  int n, m; cin >> n >> m;
  bool right = true;
  for (int i = 1; i <= n; ++i)
  {
    if (i % 2 == 1)
    {
      for (int j = 0; j < m; ++j)
        cout << '#';
    }
    else
    {
      if (right)
      {
        for (int j = 0; j < m - 1; ++j)
          cout << '.';
        cout << '#';
      }
      else
      {
        cout << '#';
        for (int j = 1; j < m; ++j)
          cout << '.';
      }
      right = !right;
    }
    cout << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  solve();
  return 0;
}