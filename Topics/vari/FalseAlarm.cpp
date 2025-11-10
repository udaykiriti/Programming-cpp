/*
//optimal solution
#include <cstdio>
#include <vector>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define YES puts("YES")
#define NO puts("NO")

void solve()
{
  int n, x;
  scanf("%d%d", &n, &x);
  std::vector<int> vec(n);
  int f = -1, l = -1;
  FOR(i, 0, n)
  {
    scanf("%d", &vec  [i]);
    if (vec[i] == 1)
    {
      if (f == -1)
        f = i;
      l = i;
    }
  }
  int req = l - f + 1;
  (req <= x) ? YES : NO;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
*/
//brute force
#include <cstdio>
#include <vector>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define YES puts("YES")
#define NO puts("NO")

bool c(const std::vector<int> &v, int n, int x, int p)
{
  FOR(i, 0, n)
  {
    if (v[i] == 1)
    {
      if (i < p || i >= p + x)
        return false;
    }
  }
  return true;
}

void solve()
{
  int n, x;
  scanf("%d%d", &n, &x);
  std::vector<int> v(n);
  FOR(i, 0, n)
  scanf("%d", &v[i]);

  FOR(p, 0, n)
  {
    if (c(v, n, x, p))
    {
      YES;
      return;
    }
  }
  NO;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
