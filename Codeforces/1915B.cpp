#include <bits/stdc++.h>
using namespace std;
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr)

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    vector<string> grid(3);
    int row = -1, col = -1;

    for (int i = 0; i < 3; ++i)
    {
      cin >> grid[i];
      for (int j = 0; j < 3; ++j)
      {
        if (grid[i][j] == '?')
        {
          row = i;
          col = j;
        }
      }
    }
    set<char> letters = {'A', 'B', 'C'};
    for (char ch : grid[row]) letters.erase(ch);
    cout << *letters.begin() << '\n';
  }
}

int main()
{
  FastIO();
  solve();
  return 0;
}