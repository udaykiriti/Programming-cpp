#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  int n, x; cin >> n;
  vector<int> count(5, 0);

  for (int i = 0; i < n; ++i)
  {
    cin >> x;
    ++count[x];
  }
  int taxis = count[4];
  taxis += count[3];
  count[1] = max(0, count[1] - count[3]);
  taxis += count[2] / 2;
  if (count[2] % 2)
  {
    ++taxis;
    count[1] = max(0, count[1] - 2);
  }
  if (count[1] > 0)
  {
    taxis += (count[1] + 3) / 4;
  }

  cout << taxis << '\n';
  return 0;
}