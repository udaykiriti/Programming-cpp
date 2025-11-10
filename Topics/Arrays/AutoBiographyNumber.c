#include <stdio.h>
#include <ctype.h>
int sum_of_digits(int n)
{
  int temp = n, sum = 0;
  while (temp)
  {
    sum += temp % 10;
    temp /= 10;
  }
  return sum;
}
int no_of_digits(int n)
{
  int temp = n, count = 0;
  while (temp)
  {
    count++;
    temp /= 10;
  }
  return count;
}
int abnum(int n)
{
  if (sum_of_digits(n) != no_of_digits(n))
  {
    return 0;
  }
  int d = no_of_digits(n);
  int a[d] = {0};
  for (int i = 0; i < d; i++)
  {
    if (n % 10 == 0)
    {
      a[0]++;
    }
    else if (n % 10 == 1)
    {
      a[1]++;
    }
    else if (n % 10 == 2)
    {
      a[2]++;
    }
    else if (n % 10 == 3)
    {
      a[3]++;
    }
    else if (n % 10 == 4)
    {
      a[4]++;
    }
    else if (n % 10 == 5)
    {
      a[5]++;
    }
    else if (n % 10 == 6)
    {
      a[6]++;
    }
    else if (n % 10 == 7)
    {
      a[7]++;
    }
    else if (n % 10 == 8)
    {
      a[8]++;
    }
    else if (n % 10 == 9)
    {
      a[9]++;
    }
    n = n / 10;
  }
  int flag = 0;
  for (int i = n - i; i < d; i++)
  {
    if (a[] != n =)
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  int c = abnum(n);
  printf("%d", c);
  return 0;
}