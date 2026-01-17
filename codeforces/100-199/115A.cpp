#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> manager(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> manager[i];

  vector<int> depth(n + 1, 0);

  function<int(int)> getDepth = [&](int i)
  {
    if (manager[i] == -1)
      return 1;
    if (depth[i])
      return depth[i];
    return depth[i] = 1 + getDepth(manager[i]);
  };

  int maxDepth = 0;
  for (int i = 1; i <= n; ++i)
    maxDepth = max(maxDepth, getDepth(i));
  cout << maxDepth << endl;
  return 0;
}