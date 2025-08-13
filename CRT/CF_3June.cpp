#include <stdio.h>
void solve()
{
  int x;
  scanf("%d", &x);
  if (x == 0)
  {
    printf("3\n");
    return;
  }
  int high = 31 - __builtin_clz(x);
  int ans = 2 * high + 3;
  printf("%d\n", ans);
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
