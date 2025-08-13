#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  vector<pair<int, int>> trees(n);
  for (int i = 0; i < n; ++i)
    cin >> trees[i].first >> trees[i].second;

  if (n == 1)
  {
    cout << 1 << '\n';
    return;
  }

  int count = 2;
  int last_pos = trees[0].first;

  for (int i = 1; i < n - 1; ++i)
  {
    int x = trees[i].first;
    int h = trees[i].second;
    int prev_x = trees[i - 1].first;
    int prev_h = trees[i - 1].second;
    int next_x = trees[i + 1].first;

    if (x - h > last_pos)
    {
      count++;
      last_pos = x;
    }
    else if (x + h < next_x)
    {
      count++;
      last_pos = x + h;
    }
    else
    {
      last_pos = x;
    }
  }

  cout << count << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cout.tie(NULL); cin.tie(nullptr);
  solve();
  return 0;
}