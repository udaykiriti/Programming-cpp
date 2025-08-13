#include <bits/stdc++.h>
using namespace std;

int digitalRoot(int n)
{
  while (n >= 10)
  {
    int sum = 0;
    while (n)
    {
      sum += n % 10;
      n /= 10;
    }
    n = sum;
  }
  return n;
}

int main()
{
  int n = 9875;
  cout << "Digital Root: " << digitalRoot(n) << endl;
  return 0;
}
