#include <bits/stdc++.h>
using namespace std;

long long modPow(long long base, long long exp, long long mod)
{
  long long res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

int main()
{
  cout << "2^10 mod 1000 = " << modPow(2, 10, 1000) << endl;
  return 0;
}
