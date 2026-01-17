#include <cstdio>
#define l long

int main()
{
  l t; scanf("%ld", &t);
  while (t--)
  {
    l n, x; scanf("%ld %ld", &n, &x);
    l odd(0);
    for (l p = 0; p < n; p++)
    {
      l a; scanf("%ld", &a);
      odd += (a % 2);
    }
    bool ans = (odd >= 1) && (!(x == n && odd % 2 == 0)) && (!(odd == n && x % 2 == 0));
    puts(ans ? "Yes" : "No");
  }
  return 0;
}