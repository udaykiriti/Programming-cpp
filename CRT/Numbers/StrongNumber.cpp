#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
  int fact = 1;
  for (int i = 1; i <= n; ++i)
    fact *= i;
  return fact;
}

int main()
{
  int num, temp, sum = 0;
  cin >> num;
  temp = num;
  while (temp > 0)
  {
    int digit = temp % 10;
    sum += factorial(digit);
    temp /= 10;
  }
  if (sum == num)
    cout << "YES";
  else
    cout << "NO";
}