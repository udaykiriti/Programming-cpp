#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n,p; cin >> n>>p;
  set<int> x_levels;
  for (int i = 0; i < p; ++i)
  {
    int level; cin >> level;
    x_levels.insert(level);
  }

  int q; cin >> q;
  set<int> y_levels;
  for (int i = 0; i < q; ++i)
  {
    int level; cin >> level;
    y_levels.insert(level);
  }

  x_levels.insert(y_levels.begin(), y_levels.end());
  if (x_levels.size() == n) cout << "I become the guy." << endl;
  else cout << "Oh, my keyboard!" << endl;
  return 0;
}