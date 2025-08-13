#include <cstdio>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define PRINT(x) printf("%d ", x)
#define PRINTLN(x) printf("%d\n", x)

void solve()
{
  int n;
  scanf("%d", &n);

  PRINT(1);
  FOR(i, 3, n + 1)
  {
    PRINT(i);
  }
  PRINTLN(2);
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
