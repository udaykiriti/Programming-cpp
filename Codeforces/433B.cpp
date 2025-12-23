#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  vector<long long> stones(n), sortedStones(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> stones[i];
    sortedStones[i] = stones[i];
  }

  sort(sortedStones.begin(), sortedStones.end());
  vector<long long> prefixOriginal(n + 1, 0), prefixSorted(n + 1, 0);
  for (int i = 0; i < n; ++i)
  {
    prefixOriginal[i + 1] = prefixOriginal[i] + stones[i];
    prefixSorted[i + 1] = prefixSorted[i] + sortedStones[i];
  }
  int m; cin >> m;
  while (m--)
  {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1)
      cout << prefixOriginal[r] - prefixOriginal[l - 1] << "\n";
    else
      cout << prefixSorted[r] - prefixSorted[l - 1] << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}