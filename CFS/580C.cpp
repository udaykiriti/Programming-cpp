#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> cats;
int n, m, result = 0;

void dfs(int node, int parent, int catCount)
{
  if (cats[node])
    catCount++;
  else
    catCount = 0;

  if (catCount > m)
    return;

  bool isLeaf = true;
  for (int neighbor : tree[node])
  {
    if (neighbor != parent)
    {
      isLeaf = false;
      dfs(neighbor, node, catCount);
    }
  }

  if (isLeaf)
    result++;
}

void solve()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  cin >> n >> m;
  cats.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> cats[i];

  tree.resize(n);
  for (int i = 0; i < n - 1; ++i)
  {
    int u, v; cin >> u >> v;
    u--, v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(0, -1, 0);
  cout << result << '\n';
}
int main()
{
  solve();
  return 0;
}