#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define multicase \
  int t;          \
  cin >> t;       \
  while (t--)     \
  {               \
    solve();      \
  }

void solve()
{
  const int N = 8;
  vector<string> v(N);
  FOR(p, 0, N)
  {
    cin >> v[p];
  }

  char ans = '.';

  FOR(row, 0, N)
  {
    if (ans != '.')
      break;
    bool test = true;
    FOR(col, 0, N)
    {
      if (v[row][col] != 'R')
      {
        test = false;
        break;
      }
    }
    if (test)
    {
      ans = 'R';
    }
  }

  FOR(col, 0, N)
  {
    if (ans != '.')
      break;
    bool test = true;
    FOR(row, 0, N)
    {
      if (v[row][col] != 'B')
      {
        test = false;
        break;
      }
    }
    if (test)
    {
      ans = 'B';
    }
  }

  cout << ans << ln;
}

int main()
{
  stop_sync;
  untie_ios;
  multicase return 0;
}