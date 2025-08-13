#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)

void solve()
{
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  bool d = false;
  FOR (e, 1, 100)
    if (e != a)
      if (abs(e - b) < abs(a - b) && abs(e - c) < abs(a - c))
      {
        d = true;
        break;
      }
  printf(d ? "YES\n" : "NO\n");
}

int main()
{
  int f; scanf("%d", &f);
  while (f--) solve();
}